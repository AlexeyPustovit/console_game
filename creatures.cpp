#include "creatures.h"

Creature::Creature(std::string name, char rank, int health, int attack, int gold)
    : m_name(std::move(name)),
      m_rank(rank),
      m_health(health),
      m_attack(attack),
      m_gold(gold) {}

Player::Player(std::string name) : Creature(name, '@', 15, 1, 0) {}

Monster::Monster(monsterType type)
    : Creature(monsterList[type].getName(), monsterList[type].getRank(),
               monsterList[type].getHealth(), monsterList[type].getAttack(),
               monsterList[type].getGold()) {}

Creature Monster::monsterList[Monster::MAX_TYPES]{
    {"dragon", 'D', 15, 3, 100}, {"orc", 'o', 4, 2, 25}, {"slime", 's', 2, 1, 10}};

char Monster::getSymbol() { return m_rank; }
std::string& Monster::getName() { return m_name; }
