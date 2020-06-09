
#include "Holding.hpp"
#include <iostream>
#include <string>
using namespace std;



Holding::Holding(string in_name,cardType ct,int cost,int hv, int uh, int sh):BlackCard(in_name,ct,cost){
  this->harvestValue=hv;
  this->type=ct;
  upperHolding=NULL;
  subHolding=NULL;

}

Holding::~Holding(){
  //cout <<"Holding is about to be destroyed "<<endl;
}

void Holding::print(){
  cout<<"Printing a HOLDING"<<endl;
  BlackCard::print();
}

int Holding::getType(){
  return type;
}

int Holding::setSubHolding(Holding *card) {
	if (subHolding == NULL) {
		subHolding = card;
		card->setUpHolding(this);
		return 1;
	}
	else return 0;
}

int Holding::setUpHolding(Holding *card) {
	if (upperHolding == NULL) {
		upperHolding = card;
		card->setSubHolding(this);
		return 1;
	}
  else return 0;
}

Holding* Holding::getSubHolding() {
	return subHolding;
}
Holding* Holding::getUpHolding() {
	return upperHolding;
}

int Holding::harvestValues(){
  if (this->holdingType == MINE) {
    if (this->upperHolding != NULL) {
      return CHAIN_1;
    }
  }
  else if (this->holdingType == GOLD_MINE) {
    if (this->subHolding != NULL) {
        if (this->upperHolding != NULL) {
          return CHAIN_2;
        }
        else {
          return CHAIN_3;
        }
    } else if (this->upperHolding != NULL) {
      return CHAIN_4;
    }
  }
  else if (this->holdingType == CRYSTAL_MINE) {
    if (this->subHolding != NULL) {
      if (this->subHolding->getSubHolding() == NULL) {
        return CHAIN_5;
      }
      else {
        return CHAIN_6;
      }
    }
  }
  return NO_CHAIN;

}

void Holding::setHarvestValue(int i){
  int v=harvestValues();
  switch(i){
    case CHAIN_1:
      this->harvestValue+=2;
    case CHAIN_2:
      this->harvestValue*=2;
    case CHAIN_3:
      this->harvestValue+=4;
    case CHAIN_4:
      this->harvestValue+=5;
    case CHAIN_5:
      this->harvestValue*=2;
    case CHAIN_6:
      this->harvestValue*=3;
  }
}


Plain::Plain(string in_name,cardType ct):Holding(in_name,ct,2,2,0,0){
  this->holdingType=0;
  cout<<"We made a new PLAIN with name "<< in_name <<endl;
}

Mine::Mine(string in_name,cardType ct):Holding(in_name,ct,5,3,1,0){
  this->holdingType=1;
  cout<<"We made a new MINE with name "<< in_name <<endl;
}

GoldMine::GoldMine(string in_name,cardType ct):Holding(in_name,ct,7,5,1,1){
  this->holdingType=2;
  cout <<"We made a new GOLD_MINE with name "<< in_name <<endl;
}

CrystalMine::CrystalMine(string in_name,cardType ct):Holding(in_name,ct,12,6,0,1){
  this->holdingType=3;
  cout <<"We made a new CRYSTAL MINE with name "<< in_name <<endl;
}

Farmland::Farmland(string in_name,cardType ct):Holding(in_name,ct,3,4,0,0){
  this->holdingType=0;
  cout <<"We made a new FARM LAND with name "<<in_name<<endl;
}


GiftsandFavour::GiftsandFavour(string in_name,cardType ct):Holding(in_name,ct,2,2,0,0){
  this->holdingType=0;
  cout <<"We made a new Gift & Favour with name "<<in_name<<endl;
}
void Plain::print(){
  cout<<"Printing PLAIN"<<endl;
  Holding::print();
}

void Mine::print(){
  cout<<"Printing MINE"<<endl;
  Holding::print();
}

void GoldMine::print(){
  cout<<"Printing GOLD MINE"<<endl;
  Holding::print();
}

void CrystalMine::print(){
  cout<<"Printing CRYSTAL MINE"<<endl;
  Holding::print();
}

void Farmland::print(){
  cout<<"Printing FARM LAND "<<endl;
  Holding::print();
}

void GiftsandFavour::print(){
  cout<<"Printing GIFTS AND FAVOUR "<<endl;
  Holding::print();
}


Stronghold::Stronghold(string in_name,cardType ct):Holding(in_name,ct,0,5,0,0){
  int r=1+rand()%5;
  //this->money=5;
  this->money=5+rand()%8; //random money {5,13}
  this->honour=r;
  this->initialDefense=5;
}

int Stronghold::getMoney(){
  return money;
}
Stronghold::~Stronghold(){
  // cout <<"STRONGHOLD is about to be destroyed "<<endl;
}
void Stronghold::print(){
  cout<<"Printing STRONGHOLD"<<endl;
  Holding::print();
}
int Stronghold::getHonour(){
  return honour;
}

int Stronghold::getInitialDefense(){
  return initialDefense;
}
