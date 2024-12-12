#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <random>
#include <chrono>
#include <atomic>
#include <algorithm>
#include <cmath>
#include <memory>
#include <string>

const int MAP_WIDTH = 100;
const int MAP_HEIGHT = 100;
const int GAME_DURATION_SECONDS = 30;
const int NUM_NPCS = 50;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis_x(0.0, MAP_WIDTH);
std::uniform_real_distribution<> dis_y(0.0, MAP_HEIGHT);
std::uniform_real_distribution<> dis_move_angle(0.0, 2 * M_PI);
std::uniform_real_distribution<> dis_move_distance(0.0, 1.0);
std::uniform_int_distribution<> dis_type(0, 15);
std::uniform_int_distribution<> dis_dice(1, 6);

enum class NPCType {
    Orc,
    Squirrel,
    Druid,
    WanderingKnight,
    Elf,
    Dragon,
    Bear,
    Bandit,
    Werewolf,
    Princess,
    Toad,
    SlaveTrader,
    Pegasus,
    Vampire,
    Mole,
    Bull
};

struct KillTableEntry {
    std::string name;
    double move_distance;
    double kill_distance;
};

const std::vector<KillTableEntry> kill_table = {
    {"Orc", 20.0, 10.0},
    {"Squirrel", 5.0, 5.0},
    {"Druid", 10.0, 10.0},
    {"WanderingKnight", 30.0, 10.0},
    {"Elf", 10.0, 50.0},
    {"Dragon", 50.0, 30.0},
    {"Bear", 5.0, 10.0},
    {"Bandit", 10.0, 10.0},
    {"Werewolf", 40.0, 5.0},
    {"Princess", 1.0, 1.0},
    {"Toad", 1.0, 10.0},
    {"SlaveTrader", 10.0, 10.0},
    {"Pegasus", 30.0, 10.0},
    {"Vampire", 50.0, 10.0},
    {"Mole", 5.0, 20.0},
    {"Bull", 30.0, 10.0}
};

struct NPC {
    int id;
    NPCType type;
    double x;
    double y;
    std::shared_ptr<std::atomic<bool>> alive;

    NPC(int id_, NPCType type_, double x_, double y_)
        : id(id_), type(type_), x(x_), y(y_), alive(std::make_shared<std::atomic<bool>>(true)) {}

    void move(double max_distance) {
        double angle = dis_move_angle(gen);
        std::uniform_real_distribution<> dis_distance(0.0, max_distance);
        double distance = dis_distance(gen);
        double dx = distance * cos(angle);
        double dy = distance * sin(angle);
        x += dx;
        y += dy;
        x = std::clamp(x, 0.0, static_cast<double>(MAP_WIDTH));
        y = std::clamp(y, 0.0, static_cast<double>(MAP_HEIGHT));
    }

    double distance_to(const NPC& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }
    std::string get_type_string() const {
        return kill_table[static_cast<int>(type)].name;
    }
};

struct BattleTask {
    int npc1_id;
    int npc2_id;
};

std::vector<NPC> npcs;
std::shared_mutex npcs_mutex;
std::vector<BattleTask> battle_tasks;
std::mutex battle_mutex;
std::condition_variable battle_cv;
std::mutex cout_mutex;
std::atomic<bool> game_over(false);

bool can_kill(const NPC& npc1, const NPC& npc2) {
    if (!npc1.alive->load() || !npc2.alive->load()) return false;

    if (npc1.type == NPCType::Dragon) {
        return true;
    }
    if (npc1.type == NPCType::WanderingKnight && npc2.type == NPCType::Dragon) {
        return true;
    }
    if (npc1.type == NPCType::Elf && npc2.type == NPCType::WanderingKnight) {
        return true;
    }

    return false;
}

void display_map() {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Карта NPC:\n";
    for (const auto& npc : npcs) {
        if (npc.alive->load()) {
            std::cout << "NPC " << npc.id << " (" << npc.get_type_string() << "): ("
                      << npc.x << ", " << npc.y << ")\n";
        }
    }
}

void movement_thread_func() {
    while (!game_over.load()) {
        {
            std::unique_lock<std::shared_mutex> lock(npcs_mutex);
            for (auto& npc : npcs) {
                if (npc.alive->load()) {
                    double max_distance = kill_table[static_cast<int>(npc.type)].move_distance;
                    npc.move(max_distance);
                }
            }

            for (size_t i = 0; i < npcs.size(); ++i) {
                for (size_t j = i + 1; j < npcs.size(); ++j) {
                    NPC& npc1 = npcs[i];
                    NPC& npc2 = npcs[j];
                    if (!npc1.alive->load() || !npc2.alive->load()) continue;

                    double distance = npc1.distance_to(npc2);
                    double kill_dist1 = kill_table[static_cast<int>(npc1.type)].kill_distance;
                    double kill_dist2 = kill_table[static_cast<int>(npc2.type)].kill_distance;

                    bool npc1_can_kill_npc2 = can_kill(npc1, npc2) && distance <= kill_dist1;
                    bool npc2_can_kill_npc1 = can_kill(npc2, npc1) && distance <= kill_dist2;

                    if (npc1_can_kill_npc2 || npc2_can_kill_npc1) {
                        {
                            std::lock_guard<std::mutex> battle_lock(battle_mutex);
                            battle_tasks.push_back(BattleTask{npc1.id, npc2.id});
                        }
                        battle_cv.notify_one();
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void battle_thread_func() {
    while (!game_over.load()) {
        BattleTask task;
        {
            std::unique_lock<std::mutex> lock(battle_mutex);
            battle_cv.wait(lock, [] { return !battle_tasks.empty() || game_over.load(); });
            if (game_over.load()) break;
            if (battle_tasks.empty()) continue;
            task = battle_tasks.back();
            battle_tasks.pop_back();
        }

        NPC* npc1 = nullptr;
        NPC* npc2 = nullptr;
        {
            std::shared_lock<std::shared_mutex> lock(npcs_mutex);
            for (auto& npc : npcs) {
                if (npc.id == task.npc1_id && npc.alive->load()) {
                    npc1 = &npc;
                }
                if (npc.id == task.npc2_id && npc.alive->load()) {
                    npc2 = &npc;
                }
                if (npc1 && npc2) break;
            }
        }

        if (npc1 && npc2 && npc1->alive->load() && npc2->alive->load()) {
            int attack1 = dis_dice(gen);
            int defense1 = dis_dice(gen);
            int attack2 = dis_dice(gen);
            int defense2 = dis_dice(gen);
            bool npc1_kills_npc2 = false;
            bool npc2_kills_npc1 = false;

            if (can_kill(*npc1, *npc2)) {
                if (attack1 > defense2) {
                    npc1_kills_npc2 = true;
                }
            }

            if (can_kill(*npc2, *npc1)) {
                if (attack2 > defense1) {
                    npc2_kills_npc1 = true;
                }
            }

            if (npc1_kills_npc2) {
                npc2->alive->store(false);
                std::lock_guard<std::mutex> cout_lock(cout_mutex);
                std::cout << "NPC " << npc1->id << " (" << npc1->get_type_string()
                          << ") убил NPC " << npc2->id << " (" << npc2->get_type_string() << ")\n";
            }

            if (npc2_kills_npc1 && npc1->alive->load()) {
                npc1->alive->store(false);
                std::lock_guard<std::mutex> cout_lock(cout_mutex);
                std::cout << "NPC " << npc2->id << " (" << npc2->get_type_string()
                          << ") убил NPC " << npc1->id << " (" << npc1->get_type_string() << ")\n";
            }
        }
    }
}

NPCType get_random_npc_type() {
    return static_cast<NPCType>(dis_type(gen));
}

int main() {
    {
        std::unique_lock<std::shared_mutex> lock(npcs_mutex);
        for (int i = 1; i <= NUM_NPCS; ++i) {
            double x = dis_x(gen);
            double y = dis_y(gen);
            NPCType type = get_random_npc_type();
            npcs.emplace_back(i, type, x, y);
        }
    }
    std::thread movement_thread(movement_thread_func);
    std::thread battle_thread(battle_thread_func);

    auto start_time = std::chrono::steady_clock::now();
    while (true) {
        auto current_time = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();
        if (elapsed >= GAME_DURATION_SECONDS) break;

        display_map();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    game_over.store(true);
    battle_cv.notify_all();

    movement_thread.join();
    battle_thread.join();

    {
        std::lock_guard<std::mutex> cout_lock(cout_mutex);
        std::cout << "Игра окончена! Выжившие NPC:\n";
        for (const auto& npc : npcs) {
            if (npc.alive->load()) {
                std::cout << "NPC " << npc.id << " (" << npc.get_type_string() << "): ("
                          << npc.x << ", " << npc.y << ")\n";
            }
        }
    }

    return 0;
}
