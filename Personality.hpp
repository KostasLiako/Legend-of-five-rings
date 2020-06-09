#ifndef PERSONALITY_HPP
#define PERSONALITY_HPP
#include <string>
#include <list>
#include <iostream>
#include "Card.hpp"
#include "Follower.hpp"
#include "Item.hpp"
#include "TypeConverter.hpp"

using namespace std;

class Personality : public BlackCard {
  public:
    ~Personality(){};
    Personality(string in_name,cardType ct,int in_cost,int in_attack , int in_defense,int in_honour);
    void print();
    int getType();
    int getHonour();
    void setFollowers(Follower* f);
    void printFollowers();
    void setItems(Item*);
    void printItems();

    void setAttack(int a);
    void setDefense(int d);



  protected:
    int attack;
    int defense;
    int honour;
    int isDead;
    int type;
    //maybe the personalities have followers
    int hasFollowers; //if is 1 , the personality has followers
    list<Follower*>* personalityFollowers;

    //and maybe have items
    int hasItems;//if is 1 , the personality has items
    list<Item*>* personalityItems;
};


class  Attacker :public Personality{
  public:
    ~Attacker(){};
    Attacker(string in_name,cardType ct=PERSONALITY);
    void print();
    int getHonour();
  private:
};

class  Defender :public Personality{
  public:
    ~Defender(){};
    Defender(string in_name,cardType ct=PERSONALITY);
    void print();
    int getHonour();
  private:
};

class Shogun :public Personality{
  public:
    ~Shogun(){};
    Shogun(string in_name,cardType ct=PERSONALITY);
    void print();
    int getHonour();
  private:
};

class Chancellor :public Personality{
  public:
    ~Chancellor(){};
    Chancellor(string in_name,cardType ct=PERSONALITY);
    void print();
    int getHonour();
  private:
};

class Champion :public Personality{
  public:
    ~Champion(){};
    Champion(string in_name,cardType ct=PERSONALITY);
    void print();
    int getHonour();
  private:
};

#endif
