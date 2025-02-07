#ifndef DECK_H
#define DECK_H

#include <string>
#include "card.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

class Deck
{
public:
    vector<Card> listCard;

    // method
    void loadDeck()
    {
        // chạy for nhét bài vô
        // chạy for 4 chất  -> 0 -> 3
        // mỗi for tạo 13 lá bài 2 -> 10, JQKA
        string suits[] = {"Heart", "Spades", "Diamond", "Clubs"};
        string courtCard[] = {"J", "Q", "K", "A"};
        for (int i = 0; i < 4; i++)
        {
            // nhét 2 -> 10
            for (int j = 2; j < 11; j++)
            {
                Card temp(j, to_string(j), suits[i]);
                this->listCard.push_back(temp);
            }

            // nhét JQKA -> value = 10
            for (int j = 0; j < 4; j++)
            {
                Card temp(10, courtCard[j], suits[i]);
                this->listCard.push_back(Card(temp));
            }
        }
    }

    void shuffle()
    {
        random_device rd;
        mt19937 gen(rd());

        std::shuffle(this->listCard.begin(), this->listCard.end(), gen);
    }

    void printDeck()
    {
        for (int i = 0; i < this->listCard.size(); i++)
        {
            cout << i << ". " << this->listCard[i].toString() << endl;
        }
    }
    // lấy lá bài cuối - remove khỏi deck
    Card takeCard()
    {
        Card temp = this->listCard.back();
        this->listCard.pop_back();

        return temp;
    }
};

#endif // DECK_H
