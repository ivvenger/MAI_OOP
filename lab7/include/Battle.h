#ifndef BATTLE_H
#define BATTLE_H
#include "NPC.h"
#include "Observer.h"
#include <vector>
#include <memory>

class Battle {
public:
    Battle(std::vector<std::unique_ptr<NPC> >& npcs, int range);
    void addObserver(Observer* observer);
    void execute();

private:
    bool canFight(NPC& npc1, NPC& npc2);
    void notify(const std::string& message);

    std::vector<std::unique_ptr<NPC> >& npcs;
    int attackRange;
    std::vector<Observer*> observers;
};

#endif
