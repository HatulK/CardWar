#ifndef CARD_HPP
#define CARD_HPP
#include "string"
#include "vector"
namespace ariel {
    class Card {


    public:
        enum cardValue{
            Ace = 1,Two = 2,Three = 3,Four = 4,Five = 5,Six = 6,
            Seven = 7,Eight = 8,Nine = 9,Ten = 10,Jack = 11,Queen = 12,
            King = 13
        };
        enum Suit{
            Spades=0, Hearts=1, Diamonds=2, Clubs=3
        };


        int compareCards(Card &card1) const;

        std::string toString() const;


        int getValue() const;

        std::string getSuit() const;

        std::string getValueByName() const;


        Card();

        Card(cardValue value, Suit suit);

    private:

        Suit suit;
        cardValue value;

    };
}
#endif