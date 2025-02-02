#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "card.h"
#include "const.h"
#include <vector>
#include <random>
#include <iostream>
#include <random>

using namespace std;

class Player
{
public:
    Player()
    { // constructor
        this->score = 0;
    }

public:
    // property
    vector<Card> hand;
    int score;

    // method
    void showHand()
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            cout << i << ". " << this->hand[i].toString() << endl;
        }
    }

    void receiveCard(Card card)
    {
        // add element into vector
        this->hand.push_back(card);
    }

    void clearHand()
    {
        hand.clear();
    }

    int countValue()
    {

        int count = 0;
        for (int i = 0; i < this->hand.size(); i++)
        {
            count = count + this->hand[i].value;
        }
        // BJ , JJ, Numbers
        if (this->hand.size() == 2) // count initial
        {
            if (count == 21)
            {
                return BLACK_JACK;
            }

            if (this->hand[0].face == "A" && this->hand[1].face == "A")
            {
                return JACK_JACK;
            }
            return count; // =2 card != BJ, JJ
        }
        if (this->hand.size() == 5)
        {
            if (count <= 21)
            {
                return FIVE_CARDS;
            }
        }

        return count; // !=2 card
    }
};
class Computer : public Player
{
public:
    bool randomDecision()
    {
        static random_device rd;                      // Seed for randomness
        static mt19937 gen(rd());                     // Mersenne Twister random number generator
        static uniform_int_distribution<> dist(0, 1); // Uniform distribution for 0 or 1

        return dist(gen); // Generate and return random boolea
    }

    bool decisionHitOrStand()
    {
        if (this->hand.size() == 5)
        {
            return DECISION_STAND;
        }
        int value = this->countValue();

        if (value >= 18)
        {
            return DECISION_STAND;
        }
        if (value == 16 || value == 17)
        {
            if (!randomDecision())
            {
                return DECISION_STAND;
            }
            else
            {
                return DECISION_HIT;
            }
        }
        if (value <= 15)
        {
            return DECISION_HIT;
        }
        return DECISION_STAND;
    }
};

class Bookmarker : public Player
{
};

#endif // PLAYER_H
