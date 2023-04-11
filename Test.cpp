//
// Created by vboxuser on 3/26/23.
//
#include "doctest.h"
#include "sources/card.hpp"
#include "sources/game.hpp"
#include "sources/player.hpp"
using namespace ariel;
TEST_CASE("test1") {
    Player p1("Amit");
    Player p2("Nadav");
    Game game(p1, p2);
    CHECK_NOTHROW(Game(p1, p2));
    CHECK_THROWS(Game(p1,p1));
    CHECK_EQ(p1.cardesTaken(), 0);
    CHECK_EQ(p2.cardesTaken(), 0);
    CHECK_EQ(p1.stacksize(), 26);
    CHECK_EQ(p2.stacksize(), 26);
    CHECK_THROWS(game.printLog());
    CHECK_THROWS(game.printStats());
    CHECK_THROWS(game.printWiner());
    CHECK_THROWS(game.printLastTurn());
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(p2.stacksize());
    CHECK_NOTHROW(p1.stacksize());
    CHECK_NOTHROW(p2.cardesTaken());
    CHECK_NOTHROW(p1.cardesTaken());
    int x = p1.stacksize();
    int y = p2.stacksize();
    CHECK(((p1.stacksize() >= x +1 ) || (p1.stacksize() <= x - 1)));
    CHECK(((p2.stacksize() <= y - 1) || (p2.stacksize() >= y + 1) ));
    game.playAll();
    CHECK(((p2.stacksize() == 0) || (p2.stacksize() == 0)));
    CHECK(((p2.stacksize() == 52) || (p2.stacksize() == 52)));
    CHECK_NOTHROW(game.printLastTurn());//check if actually print the last turn of the game
    CHECK_THROWS(game.playTurn());
    CHECK_NOTHROW(game.printLastTurn());//check if print the last turn that actually played
    CHECK_THROWS(game.playAll());
    CHECK_NOTHROW(game.printLastTurn());//check if  print the last turn that actually played
}