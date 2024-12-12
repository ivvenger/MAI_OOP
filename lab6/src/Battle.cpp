#include "../include/Battle.h"
#include <cmath>
#include <algorithm>

Battle::Battle(std::vector<std::unique_ptr<NPC>>& npcs, int range) : npcs(npcs), attackRange(range) {}

void Battle::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Battle::execute() {
    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = i + 1; j < npcs.size(); ++j) {
            if (!npcs[i]->isAlive() || !npcs[j]->isAlive()) continue;
            if (canFight(*npcs[i], *npcs[j])) {
                npcs[i]->interact(*npcs[j]);
                npcs[j]->interact(*npcs[i]);
                if (!npcs[i]->isAlive() || !npcs[j]->isAlive()) {
                    std::string message = npcs[i]->getName() + " and " + npcs[j]->getName() + " engaged in battle.";
                    notify(message);
                }
            }
        }
    }
    npcs.erase(std::remove_if(npcs.begin(), npcs.end(),
                              [](const std::unique_ptr<NPC>& npc) { return !npc->isAlive(); }),
               npcs.end());
}

bool Battle::canFight(NPC& npc1, NPC& npc2) {
    auto [x1, y1] = npc1.getCoordinates();
    auto [x2, y2] = npc2.getCoordinates();
    int dx = x1 - x2;
    int dy = y1 - y2;
    double distance = std::sqrt(dx * dx + dy * dy);
    return distance <= attackRange;
}

void Battle::notify(const std::string& message) {
    for (auto observer : observers) {
        observer->update(message);
    }
}
