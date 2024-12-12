#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class ConsoleLogger : public Observer {
public:
    void update(const std::string& message) override;
};

class FileLogger : public Observer {
public:
    void update(const std::string& message) override;
};

#endif
