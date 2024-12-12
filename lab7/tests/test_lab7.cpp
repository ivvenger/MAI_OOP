#include <gtest/gtest.h>
#include <vector>
#include <atomic>
#include <memory>
#include <cmath>
#include <string>

const int MAP_WIDTH = 100;
const int MAP_HEIGHT = 100;

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
        double angle = 0.0;
        double distance = max_distance;
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

TEST(NPCTest, Initialization) {
    NPC npc1(1, NPCType::Elf, 10.0, 20.0);
    EXPECT_EQ(npc1.id, 1);
    EXPECT_EQ(npc1.type, NPCType::Elf);
    EXPECT_DOUBLE_EQ(npc1.x, 10.0);
    EXPECT_DOUBLE_EQ(npc1.y, 20.0);
    EXPECT_TRUE(npc1.alive->load());
}

TEST(NPCTest, MovementWithinBounds) {
    NPC npc1(2, NPCType::Orc, 50.0, 50.0);
    npc1.move(20.0);
    EXPECT_DOUBLE_EQ(npc1.x, 70.0);
    EXPECT_DOUBLE_EQ(npc1.y, 50.0);
    EXPECT_TRUE(npc1.alive->load());
}

TEST(NPCTest, MovementBoundary) {
    NPC npc1(3, NPCType::Dragon, 95.0, 95.0);
    npc1.move(10.0);
    EXPECT_DOUBLE_EQ(npc1.x, 100.0);
    EXPECT_DOUBLE_EQ(npc1.y, 100.0);
    EXPECT_TRUE(npc1.alive->load());
}

TEST(NPCTest, DistanceCalculation) {
    NPC npc1(4, NPCType::Bear, 0.0, 0.0);
    NPC npc2(5, NPCType::Bear, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(npc1.distance_to(npc2), 5.0);
}

TEST(BattleTest, CanKillFunction) {
    NPC dragon(6, NPCType::Dragon, 10.0, 10.0);
    NPC knight(7, NPCType::WanderingKnight, 20.0, 20.0);
    NPC elf(8, NPCType::Elf, 30.0, 30.0);
    NPC orc(9, NPCType::Orc, 40.0, 40.0);
    NPC another_dragon(10, NPCType::Dragon, 50.0, 50.0);
    EXPECT_TRUE(can_kill(dragon, another_dragon));

    EXPECT_TRUE(can_kill(knight, dragon));

    EXPECT_TRUE(can_kill(elf, knight));

    EXPECT_FALSE(can_kill(knight, elf));

    EXPECT_FALSE(can_kill(elf, dragon));

    EXPECT_FALSE(can_kill(orc, elf));
}

TEST(BattleTest, KillingNPC) {
    NPC npc1(11, NPCType::Elf, 10.0, 10.0);
    NPC npc2(12, NPCType::WanderingKnight, 10.0, 10.0);
    EXPECT_TRUE(can_kill(npc1, npc2));
    EXPECT_FALSE(can_kill(npc2, npc1));

    if (can_kill(npc1, npc2)) {
        npc2.alive->store(false);
    }

    EXPECT_FALSE(npc2.alive->load());
    EXPECT_TRUE(npc1.alive->load());
}

TEST(BattleTest, DeadNPCCannotKill) {
    NPC npc1(13, NPCType::Dragon, 20.0, 20.0);
    NPC npc2(14, NPCType::Orc, 20.0, 20.0);
    npc1.alive->store(false);

    EXPECT_FALSE(can_kill(npc1, npc2));
    EXPECT_TRUE(can_kill(npc2, npc1));
}

TEST(NPCTest, CorrectCoordinatesAfterMovement) {
    NPC npc1(15, NPCType::Toad, 50.0, 50.0);
    npc1.move(1.0);
    EXPECT_DOUBLE_EQ(npc1.x, 51.0);
    EXPECT_DOUBLE_EQ(npc1.y, 50.0);
    EXPECT_TRUE(npc1.alive->load());
}

TEST(NPCTest, BoundaryMovement) {
    NPC npc1(16, NPCType::Vampire, 99.0, 99.0);
    npc1.move(50.0);

    EXPECT_DOUBLE_EQ(npc1.x, 100.0);
    EXPECT_DOUBLE_EQ(npc1.y, 100.0);
    EXPECT_TRUE(npc1.alive->load());
}

TEST(NPCTest, ZeroDistance) {
    NPC npc1(17, NPCType::Princess, 25.0, 25.0);
    NPC npc2(18, NPCType::Princess, 25.0, 25.0);
    EXPECT_DOUBLE_EQ(npc1.distance_to(npc2), 0.0);
}

TEST(NPCTest, DeadNPCDoesNotMove) {
    NPC npc1(19, NPCType::Mole, 30.0, 30.0);
    npc1.alive->store(false);
    double original_x = npc1.x;
    double original_y = npc1.y;
    npc1.move(5.0);
    EXPECT_DOUBLE_EQ(npc1.x, original_x);
    EXPECT_DOUBLE_EQ(npc1.y, original_y);
}

TEST(BattleTest, NoKillIfDistanceTooFar) {
    NPC npc1(20, NPCType::Elf, 10.0, 10.0);
    NPC npc2(21, NPCType::WanderingKnight, 100.0, 100.0);
    EXPECT_FALSE(can_kill(npc1, npc2));
}

TEST(BattleTest, MultipleKills) {
    NPC npc1(22, NPCType::Dragon, 10.0, 10.0);
    NPC npc2(23, NPCType::WanderingKnight, 12.0, 10.0);
    NPC npc3(24, NPCType::Elf, 14.0, 10.0);
    EXPECT_TRUE(can_kill(npc1, npc2));
    EXPECT_TRUE(can_kill(npc1, npc3));

    EXPECT_TRUE(can_kill(npc2, npc1));

    EXPECT_TRUE(can_kill(npc3, npc2));

    if (can_kill(npc1, npc2)) {
        npc2.alive->store(false);
    }
    if (can_kill(npc1, npc3)) {
        npc3.alive->store(false);
    }

    EXPECT_FALSE(npc2.alive->load());
    EXPECT_FALSE(npc3.alive->load());
    EXPECT_TRUE(npc1.alive->load());
}

TEST(NPCTest, AliveNPCStaysAlive) {
    NPC npc1(25, NPCType::Orc, 50.0, 50.0);
    EXPECT_TRUE(npc1.alive->load());

    // Без вызова убийства
    EXPECT_TRUE(npc1.alive->load());
}

TEST(NPCTest, GetTypeString) {
    NPCType types[] = {NPCType::Orc, NPCType::Squirrel, NPCType::Druid, NPCType::WanderingKnight, NPCType::Elf,
                       NPCType::Dragon, NPCType::Bear, NPCType::Bandit, NPCType::Werewolf, NPCType::Princess,
                       NPCType::Toad, NPCType::SlaveTrader, NPCType::Pegasus, NPCType::Vampire, NPCType::Mole, NPCType::Bull};

    for (int i = 0; i < 16; ++i) {
        NPC npc(i+1, types[i], 0.0, 0.0);
        EXPECT_EQ(npc.get_type_string(), kill_table[i].name);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
