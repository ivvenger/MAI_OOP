#include <iostream>
#include "include/DungeonEditor.h"
#include "include/Observer.h"

int main() {
    DungeonEditor editor;
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;

    editor.addObserver(&consoleLogger);
    editor.addObserver(&fileLogger);

    editor.addNPC("Bear", "Grizzly", 100, 100);
    editor.addNPC("Elf", "Legolas", 150, 150);
    editor.addNPC("Rogue", "Shadow", 200, 200);
    editor.addNPC("Rogue", "Shade", 205, 200);

    editor.printNPCs();

    editor.saveToFile("npc_data.txt");

    std::cout << "\nStarting battle...\n" << std::endl;
    editor.startBattle(10);

    editor.printNPCs();

    return 0;
}
