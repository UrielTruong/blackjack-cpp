#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card
{
public:
    int value;
    string face; // 2 -> 10, J, Q, K, A
    string suit; // Heart, Spades, Diamond, Clubs

    Card(int value, string face, string suit)
    {
        this->value = value;
        this->face = face;
        this->suit = suit;
    }

    // method;
    string toString()
    {
        return this->face + " " + this->suit;
    }
};

#endif // CARD_H
