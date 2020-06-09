#ifndef HOLDING_HPP
#define HOLDING_HPP
#include <string>
#include <iostream>
#include "Card.hpp"
#include "player.hpp"

#define OTHER_HOLDING 0
#define MINE 1
#define GOLD_MINE 2
#define CRYSTAL_MINE 3
#define NO_CHAIN 0
#define CHAIN_1 1
#define CHAIN_2 2
#define CHAIN_3 3
#define CHAIN_4 4
#define CHAIN_5 5
#define CHAIN_6 6
using namespace std;

class Holding : public BlackCard {
  public:
    Holding(string in_name,cardType,int cost,int hv,int uh,int sh);
    ~Holding();
    Holding();
    void print();
    int getType();

    int holdingType;
    int type;

    int setUpHolding(Holding* card);
    int setSubHolding(Holding* card);

    Holding* getSubHolding();
    Holding* getUpHolding();

    int harvestValues();
    void setHarvestValue(int i);
  private:
    int harvestValue;
    Holding* upperHolding ;
    Holding* subHolding;
};

class Plain : public Holding{
public:
  ~Plain(){};
  Plain(string in_name,cardType ct=HOLDING);
  void print();
private:
};

class Mine : public Holding{
public:
  ~Mine(){};
  Mine(string in_name,cardType ct=HOLDING);
  void print();
private:
};

class GoldMine : public Holding{
public:
  ~GoldMine(){};
  GoldMine(string in_name,cardType ct=HOLDING);
  void print();
private:
};

class Farmland : public Holding{
public:
  ~Farmland(){};
  Farmland(string in_name,cardType ct=HOLDING);
  void print();
private:
};

class CrystalMine : public  Holding{
public:
  ~CrystalMine(){};
  CrystalMine(string in_name,cardType ct=HOLDING);
  void print();
private:
};

class GiftsandFavour : public Holding{
public:
  ~GiftsandFavour(){};
  GiftsandFavour(string in_name,cardType ct=HOLDING);
  void print();
};

class Stronghold : public Holding{
public:
  Stronghold(string in_name,cardType ct=HOLDING);
  void print();
  ~Stronghold();

  int getHonour();
  int getInitialDefense();
  int getMoney();
private:
  int honour;
  int money;
  int initialDefense;
};

#endif
