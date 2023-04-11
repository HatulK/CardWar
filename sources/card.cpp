#include "card.hpp"
using namespace ariel;


Card::Card(cardValue value, Suit suit) {
    this->value = value;
    this->suit = suit;
}

Card::Card() {
    this->suit = Hearts;
    this->value =King ;
}

std::string Card::getSuit() const {
    switch (this->suit) {
        case Hearts:
            return "Hearts";
        case Diamonds:
            return "Diamonds";
        case Clubs:
            return "Clubs";
        case Spades:
            return "Spades";
        default:
            return "UNKNOWN";
    }
}

std::string Card::getValueByName() const {
    switch (this->value) {
        case Ace:
            return "Ace";
        case Two:
            return "2";
        case Three:
            return "3";
        case Four:
            return "4";
        case Five:
            return "5";
        case Six:
            return "6";
        case Seven:
            return "7";
        case Eight:
            return "8";
        case Nine:
            return "9";
        case Ten:
            return "10";
        case Jack:
            return "Jack";
        case Queen:
            return "Queen";
        case King:
            return "King";
        default:
            return "UNKNOWN";
    }

}

int Card::getValue() const {
    switch (this->value) {
        case Ace:
            return 14;
        case Two:
            return 2;
        case Three:
            return 3;
        case Four:
            return 4;
        case Five:
            return 5;
        case Six:
            return 6;
        case Seven:
            return 7;
        case Eight:
            return 8;
        case Nine:
            return 9;
        case Ten:
            return 10;
        case Jack:
            return 11;
        case Queen:
            return 12;
        case King:
            return 13;
        default:
            return -1;
    }
}


std::string ariel::Card::toString() const{
    return this->getValueByName() + " of " + this->getSuit();
}

int Card::compareCards(Card &card1) const {
    if (card1.getValue() == 14||this->getValue() == 14) {
        if (card1.getValue() == 2&&this->getValue() == 14) return 2;
        else if (this->getValue() == 14 && card1.getValue() != 2)return 1;
        else if (this->getValue() == 2 && card1.getValue() == 14) return 1;
        else if (this->getValue() != 2 && card1.getValue() != 14)return 2;
        else if (this->getValue() == 14 && card1.getValue() == 14) return 0;
    }
    if (this->getValue() > card1.getValue()) return 1;
    else if (this->getValue() == card1.getValue())return 0;
    else return 2;
}
