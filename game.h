#ifndef GAME_H
#define GAME_H

#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"
#include "const.h"
#include "read-file.h"

#include <vector>
#include <random>
#include <iostream>

using namespace std;
// blueprint
class Game
{
public:
    Deck deck;
    Computer computer;
    Bookmarker bookmarker;
    string path = "GameScore.txt";

    void printResult(string label)
    {
        system("clear");
        cout << "COM Hand: " << endl;
        this->computer.showHand();
        cout
            << "Value: " << this->computer.countValue() << endl
            << endl;

        cout << "Bookmarker Hand: " << endl;
        this->bookmarker.showHand();
        cout
            << "Value: " << this->bookmarker.countValue() << endl
            << endl;

        cout << label << endl;
        cout << "Computer score: " << this->computer.score << endl;
        cout << "Bookmarker score: " << this->bookmarker.score << endl
             << endl;

        this->saveScore();
        this->showMenu();
    }

    void saveScore()
    {
        FileAction fileAction(this->path);

        fileAction.write(to_string(this->computer.score) + "\n" + to_string(this->bookmarker.score));
    }

    void loadScore()
    {
        FileAction fileAction(this->path);

        string content = fileAction.read();
        //"0\n1"
    }

    void dealtCard()
    {
        for (int i = 0; i < 2; i++)
        {
            computer.receiveCard(deck.takeCard());   // receive card and
            bookmarker.receiveCard(deck.takeCard()); // receive card and
        }
    }

    void checkWin(bool isPreWin = false)
    {
        system("clear");
        int comValue = this->computer.countValue();
        int bmValue = this->bookmarker.countValue();
        int countHandCom = this->computer.hand.size();
        int countHandBm = this->bookmarker.hand.size();

        // check pre-win
        if (comValue == bmValue && (comValue == BLACK_JACK || comValue == JACK_JACK))
        {
            return this->printResult("DRAW");
        }
        if ((comValue == JACK_JACK && bmValue == BLACK_JACK) || ((comValue == JACK_JACK || comValue == BLACK_JACK) && (bmValue != JACK_JACK && bmValue != BLACK_JACK)))
        {
            this->computer.score += 1;
            return this->printResult("Computer WIN");
        }
        if ((bmValue == JACK_JACK && comValue == BLACK_JACK) || ((bmValue == JACK_JACK || bmValue == BLACK_JACK) && (comValue != JACK_JACK && bmValue != BLACK_JACK)))
        {
            this->bookmarker.score += 1;
            return this->printResult("Bookmarker WIN");
        }
        if (isPreWin)
        {
            return;
        }
        // check after playing game

        // COM and BM fail => DRAW
        if (comValue > 21 && bmValue > 21)
        {
            return this->printResult("DRAW");
        }
        // COM fail => BM WIN
        if (comValue > 21)
        {
            this->bookmarker.score += 1;
            return this->printResult("Bookmarker WIN");
        }
        // BM fail => COM WIN
        if (bmValue > 21)
        {
            this->computer.score += 1;
            return this->printResult("Computer WIN");
        }
        // CHECK 5 CARDS 1
        if (bmValue == FIVE_CARDS && comValue != FIVE_CARDS)
        {
            this->bookmarker.score += 1;
            return this->printResult("Bookmaker WIN");
        }

        if (comValue == FIVE_CARDS && bmValue != FIVE_CARDS)
        {
            this->computer.score += 1;
            return this->printResult("Computer WIN");
        }

        if (comValue > bmValue)
        {
            this->computer.score += 1;
            return this->printResult("Computer WIN");
        }
        if (bmValue > comValue)
        {
            this->bookmarker.score += 1;
            return this->printResult("Bookmarker WIN");
        }
        if (bmValue == comValue)
        {
            return this->printResult("DRAW");
        }
    }
    void bookmarkerTurn()
    {
        this->bookmarker.showHand(); // print show hand
        int choice;
        bool flag = true;

        while (flag)
        {
            int bmValue = this->bookmarker.countValue();

            if (bmValue > 21)
            {
                this->checkWin();
                return;
            }
            if (bmValue < 16)
            {
                cout << "===HIT or STAND===" << endl;
                cout << "1. HIT" << endl;
            }
            if (bmValue >= 16 && bmValue <= 21)
            {
                cout << "===HIT or STAND===" << endl;
                cout << "1. HIT" << endl;
                cout << "2. STAND" << endl;
            }

            cin >> choice;

            system("clear");

            switch (choice)
            {
            case 1:
                this->bookmarker.receiveCard(this->deck.takeCard());
                cout << "Your current hand is: " << endl;
                this->bookmarker.showHand();
                break;
            case 2:
                if (bmValue < 16)
                {
                    break;
                }
                flag = false;
                break;
            default:
                cout << "Invalid choice!";
                break;
            }
        }
    }

    void showMenu()
    {
        // cout menu - Do you to want to play a game?
        int choice;
        cout << "Do you to want to play a game?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;

        system("clear");
        switch (choice)
        {
        case 1:
            this->bookmarker.clearHand();
            this->computer.clearHand();
            this->playGame();
            break;
        case 2:
            cout << "Thank you!";
            break;
        default:
            cout << "Invalid choice!";
            break;
        }
    }
    void playGame()
    {
        system("clear");
        // todo: shuffle / dealt card
        this->deck.loadDeck();
        this->deck.shuffle();
        this->dealtCard();

        // todo: check pre-win
        this->checkWin(true);

        // todo: Computer turn

        bool flag = this->computer.decisionHitOrStand();
        while (flag == DECISION_HIT)
        {
            this->computer.receiveCard(this->deck.takeCard());
            flag = this->computer.decisionHitOrStand();
        }

        // todo: Bookmarker turn
        this->bookmarkerTurn();

        // todo: check result
        this->checkWin();
    }
};

#endif // GAME_H
