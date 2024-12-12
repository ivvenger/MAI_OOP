#include "../include/Observer.h"
#include <iostream>
#include <fstream>

void ConsoleLogger::update(const std::string& message) {
    std::cout << message << std::endl;
}

void FileLogger::update(const std::string& message) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    }
}
