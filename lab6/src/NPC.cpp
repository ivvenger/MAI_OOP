#include "../include/NPC.h"
#include <iostream>

NPC::NPC(const std::string& name, int x, int y) : name(name), x(x), y(y), alive(true) {}

std::string NPC::getName() const { return name; }

std::pair<int, int> NPC::getCoordinates() const { return {x, y}; }

bool NPC::isAlive() const { return alive; }

void NPC::kill() { alive = false; }

Bear::Bear(const std::string& name, int x, int y) : NPC(name, x, y) {}

std::string Bear::getType() const { return "Bear"; }

void Bear::interact(NPC& other) {
    if (other.getType() == "Elf") {
        other.kill();
        std::cout << getName() << " (Bear) killed " << other.getName() << " (Elf)" << std::endl;
    }
}

Elf::Elf(const std::string& name, int x, int y) : NPC(name, x, y) {}

std::string Elf::getType() const { return "Elf"; }

void Elf::interact(NPC& other) {
    if (other.getType() == "Rogue") {
        other.kill();
        std::cout << getName() << " (Elf) killed " << other.getName() << " (Rogue)" << std::endl;
    }
}

Rogue::Rogue(const std::string& name, int x, int y) : NPC(name, x, y) {}

std::string Rogue::getType() const { return "Rogue"; }

void Rogue::interact(NPC& other) {
    if (other.getType() == "Rogue" && other.getName() != getName()) {
        other.kill();
        kill();
        std::cout << getName() << " and " << other.getName() << " (Rogues) killed each other" << std::endl;
    }
}
