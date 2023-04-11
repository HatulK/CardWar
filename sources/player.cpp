//
// Created by vboxuser on 3/24/23.
//

#include "string"
#include "player.hpp"

using namespace ariel;
using namespace std;

void Player::increaseWin(){
    this->numOfWins++;
}

void Player::setPersonalDeck(const std::vector<Card> &deck) {
    for (const Card &i: deck){
        this->personalDeck.push_back(i);
    }
}


int Player::cardesTaken() const {
    return this->cardsWon;
}

std::string Player:: getName(){
    return this->name;
}

int Player::stacksize() {
    return (int)this->personalDeck.size();
}

void Player::increaseCardsWon(int num){
    this->cardsWon+=num;
}

void Player::zeroCardsWon(){
    this->cardsWon=0;
}

int Player::getNumOfWins() const{
    return this->numOfWins;
}

vector<Card>& Player::getPersonalDeck() {
    return this->personalDeck;
}


Player::Player() = default;


Player::Player(std::string playerName) :
        name(std::move(playerName)), isPlaying(false), cardsWon(0), numOfWins(0){}

void Player::setIsPlaying(bool state) {
    this->isPlaying=state;
}

void Player::resetPlayerAfterGame() {
this->cardsWon=0;
    this->personalDeck.clear();
    this->numOfWins=0;
    this->isPlaying= false;
}

bool Player::getIsPlaying() {
    return this->isPlaying;
}
