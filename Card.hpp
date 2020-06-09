#ifndef CARD_HPP
#define CARD_HPP
#include <string>
#include <iostream>

using namespace std;
enum cardType{PERSONALITY=1,HOLDING,FOLLOWER,ITEM};
enum Personalities{ATTACKER, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION};
enum Holdings{PLAIN, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD};
enum Followers{FOOTSOLDIER, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO};
enum Items{KATANA, SPEAR, BOW, NINJATO, WAKIZASHI};


class Card {
  public:
    Card(string in_name , int in_cost );
    ~Card();
    virtual void print();
    void cardUntap();
    int getCost();
    void Tap();
  private:
    string name ;
    int cost ;
    int isTapped ;
};


class GreenCard : public Card {
  public:
    GreenCard(string in_name,cardType ct, int in_cost , int in_ab , int in_db , int in_mh , string in_ct,int in_ec , int in_eb);
    ~GreenCard(){};
    void print();
    int getType();
    int getAttackB();
    int getDefenseB();

  protected:
    int attackBonus;
    int defenseBonus;
    int minimumHonour;
    string cardText;
    int effectBonus;
    int effectCost;
    int type;
};

class BlackCard : public Card {
  public:
    BlackCard(string in_name ,cardType ct, int in_cost);
    ~BlackCard(){};
    void print();
    int getType();
    void cardReveal();
  private:
    int isReleaved;
    int type;
};


#endif
