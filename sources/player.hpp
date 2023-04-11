#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "string"
#include "card.hpp"
#pragma once
using namespace std;
namespace ariel {
    class Player {
    public:
        Player(std::string name);
        Player();
        void setPersonalDeck(const vector<Card>& deck);
        void increaseCardsWon(int num);
        void increaseWin();
        void zeroCardsWon();
        int stacksize();
        int cardesTaken() const;
        std::string getName();
        int getNumOfWins() const;
        vector<Card>& getPersonalDeck();
        void setIsPlaying(bool state);
        void resetPlayerAfterGame();
        bool getIsPlaying();

    private:
        const std::string name;
        std::vector<Card> personalDeck;
        int cardsWon;
        int numOfWins;
        bool isPlaying;
    };
}
#endif