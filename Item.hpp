#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <iostream>
#include "Card.hpp"
using namespace std;


class Item : public GreenCard {
  public:
    ~Item(){};
    void print();
    Item(string in_name ,cardType ct ,int in_cost , int in_ab , int in_db , int in_mh , string in_ct , int in_eb , int in_ec , int in_durability);
    int getType();
    
  private:
    int durability;
    int type;
};

class Katana :public Item {
  public:
    ~Katana(){};
    Katana(string in_name,cardType ct=ITEM);
    void print();
  private:
};

class Spear :public Item {
  public:
    ~Spear(){};
    Spear(string in_name,cardType ct=ITEM);
    void print();
  private:
};

class Bow :public Item {
  public:
    ~Bow(){};
    Bow(string in_name,cardType ct=ITEM);
    void print();
  private:
};

class Ninjato :public Item {
  public:
    ~Ninjato(){};
    Ninjato(string in_name,cardType ct=ITEM);
    void print();
  private:
};

class Wakizashi :public Item {
  public:
    ~Wakizashi(){};
    Wakizashi(string in_name,cardType ct=ITEM);
    void print();
  private:
};
#endif
