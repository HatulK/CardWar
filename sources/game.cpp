#include "game.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "player.hpp"
#include "card.hpp"

using namespace ariel;
using namespace std;

void ariel::Game::playTurn() {
    if(&player1==&player2) throw logic_error("A player cannot play against himself");
    if(this->numberOfTurns>26) throw logic_error("Max turns have been played");
    if (player2.stacksize() == 0 || player1.stacksize() == 0) {
        end();
        throw logic_error("Players have no more cards.");
    }
    this->increaseTurns();
    while (true) {
        vector<Card> p1temp;
        vector<Card> p2temp;
        if (player2.stacksize() == 0 || player1.stacksize() == 0) break;
        Card p1card = this->player1.getPersonalDeck().back();
        p1temp.push_back(p1card);
        this->player1.getPersonalDeck().pop_back();
        Card p2card = this->player2.getPersonalDeck().back();
        p2temp.push_back(p2card);
        this->player2.getPersonalDeck().pop_back();
        int result = p1card.compareCards(p2card);
        std::string logger = player1.getName() + " played " + p1card.toString() + " " + player2.getName() + " played "
                             + p2card.toString() + ". ";
        this->log.push_back(logger);
        cout << logger;
        if (result == 1) {
            player1.increaseCardsWon(2*(int)p1temp.size());
            player1.increaseWin();
            logger = player1.getName() + " wins. \n";
            this->log.push_back(logger);
            cout << logger;
            p1temp.clear();
            p2temp.clear();
            return;
        }
        if (result == 2) {
            player2.increaseCardsWon(2*(int)p2temp.size());
            player2.increaseWin();
            logger = player2.getName() + " wins. \n";
            this->log.push_back(logger);
            cout << logger;
            p1temp.clear();
            p2temp.clear();
            return;
        }
        if (result == 0) {
            logger = "Draw. \n";
            this->log.push_back(logger);
            cout << logger;
            int numOfWars = 0;
            while (!result) {
                Card p1card = this->player1.getPersonalDeck().back();
                this->player1.getPersonalDeck().pop_back();
                p1temp.push_back(p1card);
                p1card = this->player1.getPersonalDeck().back();//p1 taking out 2 cards and saves them on temp deck
                this->player1.getPersonalDeck().pop_back();
                p1temp.push_back(p1card);
                Card p2card = this->player2.getPersonalDeck().back();
                this->player2.getPersonalDeck().pop_back();
                p2temp.push_back(p2card);
                p2card = this->player2.getPersonalDeck().back();//p2 taking out 2 cards and saves them on temp deck
                this->player2.getPersonalDeck().pop_back();
                p2temp.push_back(p2card);
                result = p1card.compareCards(p2card);
                std::string logger =player1.getName() + " played " + p1card.toString() + " " + player2.getName() + " played "
                        + p2card.toString() + ". ";
                this->log.push_back(logger);
                cout << logger;
                numOfWars++;
                this->increaseNumOfDraws();
                if (numOfWars == 1 && player1.stacksize() < 2&&result==0)
                {
                    player1.increaseCardsWon(2*(int)p1temp.size());
                    player2.increaseCardsWon(2*(int)p2temp.size());
                    logger = "The last hand played as draw. Hence the players take the cards back and the game ended.\n";
                    this->log.push_back(logger);
                    cout << logger;
                    end();
                    return;
                }
                if (numOfWars > 1 && player1.stacksize() < 2&&result==0)
                {
                    shuffleDeck(p2temp);
                    shuffleDeck(p1temp);
                    player1.setPersonalDeck(p1temp);
                    player2.setPersonalDeck(p2temp);
                    cout << "More than one war happened and the players have no more cards on stack."
                            "Hence each player picks his card back shuffle them and the game continue regularly. ";
                    p1temp.clear();
                    p2temp.clear();
                    return;
                }
                if (result == 1)
                {
                    player1.increaseCardsWon(2*(int)p1temp.size());
                    player1.increaseWin();
                    logger = player1.getName() + " wins the war. \n";
                    this->log.push_back(logger);
                    cout << logger;
                    p1temp.clear();
                    p2temp.clear();
                    return;
                }
                if (result == 2)
                {
                    player2.increaseCardsWon(2 *(int)p1temp.size());
                    player1.increaseWin();
                    logger = player1.getName() + " wins the war. \n";
                    this->log.push_back(logger);
                    cout << logger;
                    p1temp.clear();
                    p2temp.clear();
                    return;
                }
                if (result == 0)
                {
                    logger = "Draw again. Starting another war. \n";
                    this->log.push_back(logger);
                    cout << logger;
                }
            }
        }
    }
}

void ariel::Game::resetTurns() {
    this->numberOfTurns = 0;
}

void ariel::Game::printLastTurn() {
    if (this->getNumberOfTurns() == 0) throw logic_error("No turn have been played yet");
    cout << this->log.back();
}

void ariel::Game::playAll() {
    while (this->player1.stacksize() != 0 && this->player2.stacksize() != 0) {
        playTurn();
    }
}

void ariel::Game::printWiner() {
    if (this->winner == 1) {
        cout << "The Winner is:" << this->player1.getName() << endl;
    }
    if (this->winner == 2) {
        cout << "The Winner is:" << this->player2.getName() << endl;
    }
    if (this->winner == 0) {
        cout << "The last game finished with a draw." << endl;
    } else {
        cout << "There is no winner yet." << endl;
    }
}

void ariel::Game::printLog() {
    if (!log.empty()) {
//        for (int i = 0; i < this->log.size(); ++i) {
        for (const auto &i: this->log) {
            cout << i << endl;
        }
    } else {
        throw logic_error("The log is currently empty. try again later. ");
    }
}

void ariel::Game::printStats() {
    if (this->numberOfTurns == 0) {
        cout<<"No turns have been played yet.\n";
    } else {
        cout << "The winner is:" << endl;
        printWiner();
        cout << "Turns played: " << this->numberOfTurns << endl;
        double p1wr = player1.getNumOfWins()/this->numberOfTurns*100;
        cout << player1.getName() << " Win rate is: " << p1wr << "%" << endl;
        cout << player1.getName() << " has won " << player1.cardesTaken() << " cards." << endl;
        double p2wr = player2.getNumOfWins() / this->numberOfTurns * 100;
        cout << player2.getName() << " Win rate is: " << p2wr << "%" << endl;
        cout << player2.getName() << " has won " << player2.cardesTaken() << " cards." << endl;
        cout << "There has been " << this->getNumOfDraws() << " draws in this game." << endl;
    }
}

void ariel::Game::initDeck() {
    std::vector<Card> initdeck;
    for (int i = 1; i < 14; i++) {
        for (int j = 0; j < 4; j++) {
            Card card((ariel::Card::cardValue(i)), ariel::Card::Suit(j));
            initdeck.push_back(card);
        }
    }
    shuffleDeck(initdeck);
    this->deck = initdeck;
    for (int i = 0; i < 26; ++i) {
        player1.getPersonalDeck().push_back(initdeck.back());
        initdeck.pop_back();
    }
    for (int i = 26; i < 52; ++i) {
        player2.getPersonalDeck().push_back(initdeck.back());
        initdeck.pop_back();
    }
}

int ariel::Game::getNumberOfTurns() {
    return this->numberOfTurns;
}

void Game::increaseTurns() {
    this->numberOfTurns++;
}

void ariel::Game::shuffleDeck(std::vector<Card> &deck) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen);
}


ariel::Game::Game(Player &player1, Player &player2) : numberOfTurns(0), numOfDraws(0),player1(player1), player2(
        player2), winner(-1) {
    if (!this->player1.getIsPlaying() && !this->player2.getIsPlaying()) {
        initDeck();
        this->player1.setIsPlaying(true);
        this->player2.setIsPlaying(true);
    } else {
        throw logic_error("At least one of the players is already playing a different game.");
    }
}

void Game::end() {
    if (player1.getNumOfWins() > player2.getNumOfWins()) {
        this->winner = 1;
    } else if (player1.getNumOfWins() > player2.getNumOfWins()) {
        this->winner = 2;
    } else {
        this->winner = 0;
    }
    this->deck.clear();
    player1.resetPlayerAfterGame();
    player2.resetPlayerAfterGame();
}

int Game::getNumOfDraws() const {
    return this->numOfDraws;
}

void Game::increaseNumOfDraws() {
    this->numOfDraws++;
}


