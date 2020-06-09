#ifndef FOLLOWER_HPP
#define FOLLOWER_HPP
#include <string>
#include <iostream>
#include "Card.hpp"
using namespace std;

class Follower :public GreenCard{
  public:
    ~Follower(){};
    Follower(string in_name,cardType ct, int in_cost , int in_ab , int in_db , int in_mh , string in_ct , int in_eb , int in_ec );
    void print();
    int getType();
    int getMinimumHonour();
  private:
    int type;
};

class Footsoldier : public Follower {
  public:
    ~Footsoldier(){};
    Footsoldier(string in_name,cardType ct=FOLLOWER);
    void print();
  private:
};

class Archer : public Follower {
  public:
    Archer(string in_name,cardType ct=FOLLOWER);
    ~Archer(){};
    void print();
  private:
};
class Sieger : public Follower {
  public:
    ~Sieger(){};
    Sieger (string in_name,cardType ct=FOLLOWER);
    void print();
  private:
};

class Cavalry : public Follower {
  public:
    ~Cavalry(){};
    Cavalry(string in_name,cardType ct=FOLLOWER);
    void print();
  private:
};

class Naval : public Follower {
  public:
    ~Naval(){};
    Naval(string in_name,cardType ct=FOLLOWER);
    void print();
  private:
};

class Bushido : public Follower {
  public:
    ~Bushido(){};
    Bushido(string in_name,cardType ct=FOLLOWER);
    void print();
  private:
};

class Atakebune: public Follower {
  public:
    ~Atakebune(){};
    Atakebune(string in_name,cardType ct=FOLLOWER);
    void print();
  private:
};

#endif
