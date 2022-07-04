#include <iostream>

#include "creatures.h"

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster getRandomMonster() {
    return {
        static_cast<Monster::monsterType>(getRandomNumber(0, Monster::MAX_TYPES - 1))};
}

std::string getDungeonLevel(const int level) {
    switch (level) {
        case 1: return "first";
        case 2: return "second"; break;
        case 3: return "third"; break;
        case 4: return "fourth"; break;
        case 5: return "fifth"; break;
        case 6: return "sixth"; break;
        case 7: return "seventh"; break;
        case 8: return "eighth"; break;
        case 9: return "ninth"; break;
        case 10: return "tenth"; break;
        case 11: return "eleventh"; break;
        case 12: return "twelfth"; break;
        case 13: return "thirteenth"; break;
        case 14: return "fourteenth"; break;
        case 15: return "fifteenth"; break;
        case 16: return "sixteenth"; break;
        case 17: return "seventeenth"; break;
        case 18: return "eighteenth"; break;
        case 19: return "nineteenth"; break;
        case 20: return "twentieth"; break;
    }
    return "???";
}

void attackMonster(Player& player, Monster& monster) {
    monster.reduceHealth(player.getAttack());
    std::cout << "You hit " << monster.getName() << " for " << player.getAttack()
              << " damage.\n";
}

void attackPlayer(Player& player, Monster& monster) {
    player.reduceHealth(monster.getAttack());
    std::cout << "The " << monster.getName() << " hit you for " << monster.getAttack()
              << " damage.\n";
}

bool DefeatTheMonster(Player& player, Monster& monster, bool playerFirst) {
    if (!playerFirst) attackPlayer(player, monster);

    while (!player.isDead()) {
        attackMonster(player, monster);
        if (monster.isDead()) {
            player.levelUp();
            player.addGold(monster.getGold());
            player.plusHealth();

            std::cout << "You killed the " << monster.getName() << ".\n"
                      << "You are now level " << player.getLevel() << ".\n"
                      << "You found " << monster.getGold() << " gold.\n"
                      << "Your Health increased by 1\n"
                      << "Now you can go to the next level\n\n";
            return true;
        }
        attackPlayer(player, monster);
    }
    return false;
}

bool FightOrRun(Player& player, Monster& monster) {
    bool playerKilled{false};
    std::cout << "What will you choose, (F)ight or (R)un: ";
    char playerChoice;
    do {
        std::cin >> playerChoice;
    } while (playerChoice != 'f' && playerChoice != 'r');

    if (playerChoice == 'r') {
        if (getRandomNumber(0, 100) > 50) {
            std::cout << "You have successfully sneaked on and now you can go to the "
                         "next level\n\n";
            return playerKilled;
        }

        std::cout << "The monster saw you and runs to attack!\n";
        playerKilled = !DefeatTheMonster(player, monster, false);
    } else /*playerChoice == 'f'*/
        playerKilled = !DefeatTheMonster(player, monster, true);
    return playerKilled;
}
