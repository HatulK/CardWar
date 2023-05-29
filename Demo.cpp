#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unistd.h>

using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace ariel;

int main() {
    // Create two players
    Player p1("May");
    Player p2("Lia");

    std::cout << "The players who are about to play: " << p1.getName() << ", " << p2.getName() << endl;

    //creating a new game
    Game game(p1, p2);
    game.playTurn();
    game.printLastTurn();

    game.playTurn();
    game.playTurn();
    std::cout << "---------START TEMP STAS---------" << endl;
    game.printStats();
    game.printWiner();
    std::cout << "---------END TEMP STAS---------" << endl;

    game.playAll();
    game.printLog();
    game.printStats();

    //Play another game after the game ended
    sleep(1);
    Game game2(p1, p2);
    game2.playAll();
    std::cout << "---------SECOND GAME STATS END---------" << endl;
    std::cout << "Second game winner:" << endl;
    game2.printWiner();
    game2.printStats();

}