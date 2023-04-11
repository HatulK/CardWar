#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <iostream>


namespace ariel {
    class Game {
        Player &player1;
        Player &player2;
        std::vector<Card> deck;
        std::vector <std::string> log;
        int winner; // if p1 win, winner =1, if p2 winner =2 if draw winner =0
        int numberOfTurns;
        int numOfDraws;

    public:

        int getNumOfDraws() const;
        void increaseNumOfDraws();

        //int setAndGetWinner();
        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();

        void initDeck();

        void end();

        int getNumberOfTurns();

        void increaseTurns();

        void resetTurns();

        static void shuffleDeck(std::vector <Card> &deck);

        Game(Player &player1, Player &player2);

    };
}
#endif