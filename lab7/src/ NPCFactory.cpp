#include "../include/NPCFactory.h"

std::unique_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Bear") {
        return std::make_unique<Bear>(name, x, y);
    } else if (type == "Elf") {
        return std::make_unique<Elf>(name, x, y);
    } else if (type == "Rogue") {
        return std::make_unique<Rogue>(name, x, y);
    } else {
        return nullptr;
    }
}
