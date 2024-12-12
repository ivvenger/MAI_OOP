#ifndef NPC_H
#define NPC_H
#include <string>
#include <utility>

class NPC {
public:
    NPC(const std::string& name, int x, int y);
    virtual ~NPC() {}

    virtual std::string getType() const = 0;
    virtual void interact(NPC& other) = 0;

    std::string getName() const;
    std::pair<int, int> getCoordinates() const;

    bool isAlive() const;
    void kill();

private:
    std::string name;
    int x, y;
    bool alive;
};

class Bear : public NPC {
public:
    Bear(const std::string& name, int x, int y);
    std::string getType() const override;
    void interact(NPC& other) override;
};

class Elf : public NPC {
public:
    Elf(const std::string& name, int x, int y);
    std::string getType() const override;
    void interact(NPC& other) override;
};

class Rogue : public NPC {
public:
    Rogue(const std::string& name, int x, int y);
    std::string getType() const override;
    void interact(NPC& other) override;
};

#endif
