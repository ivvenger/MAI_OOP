#include "../include/DungeonEditor.h"
#include "../include/NPCFactory.h"
#include "../include/Battle.h"
#include <iostream>
#include <fstream>
#include <unordered_set>

DungeonEditor::DungeonEditor() {}

void DungeonEditor::addNPC(const std::string& type, const std::string& name, int x, int y) {
    if (x < 0 || x > 500 || y < 0 || y > 500) {
        std::cerr << "Coordinates out of bounds!" << std::endl;
        return;
    }
    for (const auto& npc : npcs) {
        if (npc->getName() == name) {
            std::cerr << "Name already exists!" << std::endl;
            return;
        }
    }
    auto npc = NPCFactory::createNPC(type, name, x, y);
    if (npc) {
        npcs.push_back(std::move(npc));
    } else {
        std::cerr << "Invalid NPC type!" << std::endl;
    }
}

void DungeonEditor::printNPCs() const {
    for (const auto& npc : npcs) {
        std::cout << npc->getType() << " " << npc->getName() << " at "
                  << npc->getCoordinates().first << ", " << npc->getCoordinates().second << std::endl;
    }
}

void DungeonEditor::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& npc : npcs) {
            outFile << npc->getType() << " " << npc->getName() << " "
                    << npc->getCoordinates().first << " " << npc->getCoordinates().second << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Failed to open file for saving!" << std::endl;
    }
}

void DungeonEditor::loadFromFile(const std::string& filename) {
    npcs.clear();
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string type, name;
        int x, y;
        while (inFile >> type >> name >> x >> y) {
            addNPC(type, name, x, y);
        }
        inFile.close();
    } else {
        std::cerr << "Failed to open file for loading!" << std::endl;
    }
}

void DungeonEditor::startBattle(int range) {
    Battle battle(npcs, range);
    for (auto observer : observers) {
        battle.addObserver(observer);
    }
    battle.execute();
}

void DungeonEditor::addObserver(Observer* observer) {
    observers.push_back(observer);
}
