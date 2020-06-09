#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#include <iostream>
#include <string>
#include "player.hpp"
#include "Card.hpp"
#include "Holding.hpp"

#define PLAYERS_NUM 2
#define ARMY_NUM 3
#define HOLDING_NUM 5
#define MAX_ITEMS 2
#define MAX_FOLLOWERS 2
#define WIN_1 0
#define WIN_2 1
#define NO_WINNER -1
using namespace std;

class gameBoard{
  public:
    gameBoard(); //constructor is the Initializer
    ~gameBoard();

    void initializeGameBoard();
    void printGameStatistics();
    void finalPhase();
    void printWinner();
    int checkWinningCondition();
    void gamePlay();
  private:
    player** players;
};

#endif
