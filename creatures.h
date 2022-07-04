#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature {
protected:
    std::string m_name;
    char m_rank;
    int m_health;
    int m_attack;
    int m_gold;

public:
    Creature(std::string name, char rank, int health, int attack, int gold);

    // getters
    [[nodiscard]] const std::string& getName() const { return m_name; }
    char getRank() { return m_rank; };
    int getHealth() { return m_health; };
    int getAttack() { return m_attack; };
    int getGold() { return m_gold; };

    // methods
    void reduceHealth(int hp) { m_health -= hp; }
    void plusHealth() { ++m_health; }
    bool isDead() { return m_health <= 0; }
    void addGold(int gold) { m_gold += gold; }
};

class Player : public Creature {
private:
    std::size_t level{1};

public:
    explicit Player(std::string name);

    int getLevel() { return level; }

    void levelUp() {
        ++level;
        ++m_attack;
    }
    static bool hasWon(int lvl) { return lvl == 20; }
};

struct Monster : public Creature {
    enum monsterType { DRAGON, ORC, SLIME, MAX_TYPES };

private:
    static Creature monsterList[Monster::MAX_TYPES];

public:
    Monster(monsterType type);

    char getSymbol();
    std::string& getName();
};

#endif  // CREATURE_H
