#include "Card.hpp"
#include <iostream>
#include <string>
using namespace std;
static int c=0;
Card::Card(string in_name , int in_cost ){
   this->name=in_name ;
   this->cost=in_cost ;
   this->isTapped=0;
   cout<<"A card has just constructed"<<endl;
 }

Card::~Card(){
//  cout << "A card is going to be destroyed..."<<++c<< endl ;
}

void Card::print(){
  cout << "Printing a CARD... " <<endl;
  cout << "Name = " << this->name<<endl<<endl;;
}

int Card::getCost(){
  return this->cost;
}

void Card::Tap(){
  this->isTapped=1;
}

BlackCard::BlackCard(string in_name ,cardType ct, int in_cost):Card(in_name,in_cost){
  this->isReleaved=0;
  this->type=ct;
}

GreenCard::GreenCard(string in_name ,cardType ct, int in_cost , int in_ab , int in_db , int in_mh , string in_ct,int in_ec , int in_eb):Card(in_name,in_cost){
  this->attackBonus=in_ab;
  this->defenseBonus=in_db;
  this->minimumHonour=in_mh;
  this->cardText=in_ct;
  this->effectBonus=in_eb;
  this->effectCost=in_ec;
  this->type=ct;
}

int GreenCard::getType(){
  return type;
}

void GreenCard::print(){
  cout << "Printing a GREEN CARD... "<< endl;
  Card::print();
}
void BlackCard::print(){
  cout << "Printing a BLACK CARD... "<< endl;
  Card::print();
}

int BlackCard::getType(){
  return type;
}

void BlackCard::cardReveal(){
  this->isReleaved=1;
  cout<<"<BlackCard> Province set Releaved SUCCESSFULLY"<<endl;
}
void Card::cardUntap(){
  this->isTapped=1;
}

int GreenCard::getAttackB(){
  return this->attackBonus;
}

int GreenCard::getDefenseB(){
  return this->defenseBonus;
}
