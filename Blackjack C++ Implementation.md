Blackjack C++ Implementation
Overview:Implement a single-player Blackjack game where the player plays against the computer (COM).
1. The player acts as the bookmaker (nhà cái).
2. A standard playing card deck consists of 52 cards, divided into 4 suits:
    * Hearts (♥)
    * Diamonds (♦)
    * Clubs (♣)
    * Spades (♠)
3. Each suit contains 13 cards:
    * Numbers: 2 through 10.
    * Face cards: Jack (J), Queen (Q), King (K). // be counted as 10
    * Ace (A): Can be counted as either 1 or 11, depending on the situation.
4. At the start of the game, the deck is shuffled randomly, and 2 cards are dealt to each player.
5. Implement a strategy for COM to decide whether to HIT or STAND. You will need to explain your strategy.
6. During the player's turn, the player will have two options: HIT or STAND.
7. After the player STANDS, the game will determine the winner and ask the player if they want to play another game.
8. The implementation must follow Vietnamese Blackjack rules, including the calculation of points, recognition of Five-card Charlie, and Blackjack.

Note: You can use either OOP or POP but code MUST be broken into small, reusable function

class Card: 
- properties: int value, string suit, string face
- method: show()

class Deck:
- properties: Card[52]
- method: hit (dealt), shuffle

class abstract Player:
- properties: Card[2->5] hand
- method: evaluate -> BLACJACK, JACKJACK, VALUE, take

class Computer inherit Player
- method: logicHitOrStand() (xử lí rút bài)

class User inherit Player

class GAME:
- properties: Deck deck, Computer com, User bookmarker
- method: 
+ showMenu() -> while
+ showResult()
+ exit()
+ checkPreWin()
+ play -> Deck.shuffle(), checkPreWin(), com.logicHitOrStand(), xử lí rút bài, 


Blackjack
1. Add new feature to allow player see the score versus computer //done
2. Show it at the beginning when open game or each time a match end. // done
3. User also have 1 more option “Load game” under “Play game” to load an unfinished match (if have) and continue it with the score
4. If User choose “Play game” then reset score and unfinished match. Then start like normal