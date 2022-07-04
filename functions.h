#ifndef FUNCTION_H
#define FUNCTION_H

#include "creatures.h"

int getRandomNumber(int min, int max);

Monster getRandomMonster();

std::string getDungeonLevel(int level);

void attackMonster(Player& player, Monster& monster);

void attackPlayer(Player& player, Monster& monster);

bool DefeatTheMonster(Player& player, Monster& monster, bool playerFirst);

bool FightOrRun(Player& player, Monster& monster);

#endif  // FUNCTION_H
