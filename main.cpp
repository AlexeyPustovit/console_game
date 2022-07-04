#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "creatures.h"
#include "functions.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    rand();

    std::cout << "Elder: Hello stranger...\n"
              << "Elder: What's your name?\n"
              << "You: My name is ";

    std::string playerName;
    do {
        std::cin >> playerName;
    } while (playerName.empty() && playerName.size() > 20);

    // Create player's character
    Player player(playerName);

    std::cout << "Elder: We've been waiting for you, " << playerName
              << ". Monsters attacked our village, destroyed several huts and stole "
                 "our treasure - the sacred sweetroll. \n"
              << "Elder: You need to go down into the ancient ruins for that group of "
                 "monsters and defeat them.\n"
              << "Elder: There were about twenty of them. This is a difficult challenge, "
                 "but please save our treasure!\n"
              << playerName << ": I'll bring your sweetrool back!\n"
              << std::endl;

    // beginning of the game
    int ruinsLevel{1};
    while (!player.hasWon(ruinsLevel)) {
        std::cout << "This is the " << getDungeonLevel(ruinsLevel)
                  << " level of this ruins\n"
                  << "Now your Health is " << player.getHealth() << ".\n";

        Monster monster{getRandomMonster()};
        std::cout << "Here you have encountered a " << monster.getName() << " ("
                  << monster.getSymbol() << ")\n"
                  << "The monster hasn't seen you yet. You can try to sneak through "
                     "it or fight it.\n";

        // if player was killed - end the game
        if (FightOrRun(player, monster)) {
            std::cout << "You died at level " << player.getLevel() << " with "
                      << player.getGold() << " gold.\n"
                      << "Too bad you can't take it with you!\n";

            // clang-format off
                #ifdef _WIN32
                    system("pause");
                #endif
            // clang-format on

            return 0;
        }
        ++ruinsLevel;
    }  // end of game loop

    std::cout << "Congratulations! You reached " << getDungeonLevel(ruinsLevel)
              << " level of the ancient ruins, and here you see the stolen "
                 "sweetroll. Now you can get it back!.\n"
              << "As a reward, the village elder gave you 500 gold\n"
              << "Your level is " << player.getLevel() << ". Now you have "
              << (player.addGold(500), player.getGold())
              << " gold and you decide to spend it on a good rest from all these "
                 "monsters...\n";

    // clang-format off
    #ifdef _WIN32
        system("pause");
    #endif
    // clang-format on

    return 0;
}
