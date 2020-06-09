#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Card.hpp"

using namespace std;
class Stronghold;
class player {
  public:
    player(string in_name);
    ~player();

    void printHand();
    void printHoldings();
    void printArmy();
    void printMoney();

    void holdingChain();
    void sethonour(int);
    //everything we need for starting phase.
    void untapEverything();
    void drawFateCard();
    void revealProvinces();
    void printProvinces();
    void startingPhase();
    void equipPhase();
    void economyPhase();
    void pFinalPhase();
    int pGetMoney();
    string pGetName();
    int pGetHonour();
    int pGetInitialDefense();
    int pGetProvincesNum();
    void setMoney(int m);
  private:
    string name;
    list<GreenCard*>* fateDeck;
    list<BlackCard*>* dynastyDeck;
    list<GreenCard*>* hand;
    list<BlackCard*>* holdings;
    list<BlackCard*>* army;
    list<BlackCard*>* provinces;
    // BlackCard* playersStronghold;
    Stronghold* playersStronghold;
    int numOfProvinces;
    int honour;
    int money;
    int initialDefense;
} ;

#endif
