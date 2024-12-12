#include <gtest/gtest.h>
#include "../include/DungeonEditor.h"
#include "../include/Observer.h"
#include "../include/NPCFactory.h"
#include <fstream>

TEST(NPCCreationTest, CreateBear) {
    auto bear = NPCFactory::createNPC("Bear", "Grizzly", 100, 100);
    ASSERT_NE(bear, nullptr);
    EXPECT_EQ(bear->getType(), "Bear");
    EXPECT_EQ(bear->getName(), "Grizzly");
    EXPECT_EQ(bear->getCoordinates(), std::make_pair(100, 100));
}

TEST(NPCCreationTest, CreateElf) {
    auto elf = NPCFactory::createNPC("Elf", "Legolas", 200, 200);
    ASSERT_NE(elf, nullptr);
    EXPECT_EQ(elf->getType(), "Elf");
    EXPECT_EQ(elf->getName(), "Legolas");
    EXPECT_EQ(elf->getCoordinates(), std::make_pair(200, 200));
}

TEST(NPCCreationTest, CreateRogue) {
    auto rogue = NPCFactory::createNPC("Rogue", "Shadow", 300, 300);
    ASSERT_NE(rogue, nullptr);
    EXPECT_EQ(rogue->getType(), "Rogue");
    EXPECT_EQ(rogue->getName(), "Shadow");
    EXPECT_EQ(rogue->getCoordinates(), std::make_pair(300, 300));
}

TEST(NPCTest, UniqueNames) {
    DungeonEditor editor;
    editor.addNPC("Bear", "Grizzly", 100, 100);
    testing::internal::CaptureStderr();
    editor.addNPC("Elf", "Grizzly", 200, 200);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_NE(output.find("Name already exists!"), std::string::npos);
}

TEST(NPCTest, CoordinatesOutOfBounds) {
    DungeonEditor editor;
    testing::internal::CaptureStderr();
    editor.addNPC("Bear", "Baloo", 600, 600); // Координаты вне пределов
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_NE(output.find("Coordinates out of bounds!"), std::string::npos);
}

TEST(DungeonEditorTest, PrintNPCs) {
    DungeonEditor editor;
    editor.addNPC("Bear", "Grizzly", 100, 100);
    editor.addNPC("Elf", "Legolas", 200, 200);
    testing::internal::CaptureStdout();
    editor.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Bear Grizzly at 100, 100"), std::string::npos);
    EXPECT_NE(output.find("Elf Legolas at 200, 200"), std::string::npos);
}

TEST(BattleTest, ElfKillsRogue) {
    DungeonEditor editor;
    editor.addNPC("Elf", "Legolas", 100, 100);
    editor.addNPC("Rogue", "Shadow", 105, 100);
    editor.startBattle(10);
    testing::internal::CaptureStdout();
    editor.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Elf Legolas"), std::string::npos);
    EXPECT_EQ(output.find("Rogue Shadow"), std::string::npos);
}

TEST(BattleTest, RogueKillsRogue) {
    DungeonEditor editor;
    editor.addNPC("Rogue", "Shadow", 100, 100);
    editor.addNPC("Rogue", "Shade", 105, 100);
    editor.startBattle(10);
    testing::internal::CaptureStdout();
    editor.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();
    int rogueCount = 0;
    if (output.find("Rogue Shadow") != std::string::npos) rogueCount++;
    if (output.find("Rogue Shade") != std::string::npos) rogueCount++;
    EXPECT_LT(rogueCount, 2);
}

TEST(BattleTest, BearKillsElf) {
    DungeonEditor editor;
    editor.addNPC("Bear", "Grizzly", 100, 100);
    editor.addNPC("Elf", "Legolas", 105, 100);
    editor.startBattle(10);
    testing::internal::CaptureStdout();
    editor.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Bear Grizzly"), std::string::npos);
    EXPECT_EQ(output.find("Elf Legolas"), std::string::npos);
}

TEST(FileIOTest, SaveAndLoadNPCs) {
    DungeonEditor editor;
    editor.addNPC("Bear", "Grizzly", 100, 100);
    editor.addNPC("Elf", "Legolas", 200, 200);
    editor.saveToFile("npc_data_test.txt");
    DungeonEditor newEditor;
    newEditor.loadFromFile("npc_data_test.txt");
    testing::internal::CaptureStdout();
    newEditor.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Bear Grizzly at 100, 100"), std::string::npos);
    EXPECT_NE(output.find("Elf Legolas at 200, 200"), std::string::npos);
    remove("npc_data_test.txt");
}

TEST(ObserverTest, LoggingEvents) {
    DungeonEditor editor;
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
    editor.addObserver(&consoleLogger);
    editor.addObserver(&fileLogger);
    editor.addNPC("Bear", "Grizzly", 100, 100);
    editor.addNPC("Elf", "Legolas", 105, 100);
    testing::internal::CaptureStdout();
    std::ofstream logFile("log.txt", std::ios::trunc);
    logFile.close();
    editor.startBattle(10);
    std::string consoleOutput = testing::internal::GetCapturedStdout();
    EXPECT_NE(consoleOutput.find("Grizzly (Bear) killed Legolas (Elf)"), std::string::npos);

    std::ifstream logFileIn("log.txt");
    std::string line;
    bool found = false;
    while (std::getline(logFileIn, line)) {
        if (line.find("Grizzly and Legolas engaged in battle.") != std::string::npos) {
            found = true;
            break;
        }
    }
    EXPECT_TRUE(found);
    remove("log.txt");
}
