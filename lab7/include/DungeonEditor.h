#ifndef DUNGEONEDITOR_H
#define DUNGEONEDITOR_H
#include "NPC.h"
#include "Observer.h"
#include <vector>
#include <memory>
#include <string>

class DungeonEditor {
public:
    DungeonEditor();
    void addNPC(const std::string& type, const std::string& name, int x, int y);
    void printNPCs() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void startBattle(int range);

    void addObserver(Observer* observer);

private:
    std::vector<std::unique_ptr<NPC> > npcs;
    std::vector<Observer*> observers;
};

#endif
