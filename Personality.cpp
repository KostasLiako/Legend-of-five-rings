#include "Personality.hpp"
#include "Follower.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int counter_fol=0;
int counter_item=0;

Personality::Personality(string in_name,cardType ct,int in_cost,int in_attack , int in_defense,int in_honour):BlackCard(in_name,ct,in_cost){
  this->attack=in_attack;
  this->defense=in_defense;
  this->honour=in_honour;
  this->type=ct;
  this->personalityFollowers=new list<Follower *>();
  this->personalityItems=new list<Item *>();


}
void Personality::print(){
  cout<<"Printing a PERSONALITY"<<endl;
  BlackCard::print();
}

int Personality::getHonour(){
  return this->honour;
}

int Personality::getType(){
  return type;
}

void Personality::setFollowers(Follower* f){
  personalityFollowers->push_back(f);
    cout<<"-----------FOLLOWER ADDING TO THE LIST--------"<<endl;
}

void Personality::setItems(Item* i){
  personalityItems->push_back(i);
  cout<<"-----------ITEM ADDING TO THE LIST--------"<<endl;
}

void Personality::printFollowers(){
  list<Follower*>::iterator it;

   for(it=personalityFollowers->begin(); it != personalityFollowers->end();it++){
  (*it)->print();}

}

void Personality::setAttack(int a){
  this->attack+=a;
}

void Personality::setDefense(int d){
  this->defense+=d;
}

void Personality::printItems(){
  list<Item*>::iterator it;

  for(it=personalityItems->begin(); it != personalityItems->end();it++){
    (*it)->print();}
}

Attacker::Attacker(string in_name,cardType ct):Personality(in_name,ct,5,3,2,2){
  cout << "We made a new ATTACKER with name " << in_name << endl;
}


Defender::Defender(string in_name,cardType ct):Personality(in_name,ct,5,2,3,2){
  cout << "We made a new DEFENDER with name " << in_name << endl;
}

Shogun::Shogun(string in_name,cardType ct):Personality(in_name,ct,15,10,5,8){
  cout << "We made a new SHOGUN with name " << in_name << endl;
}

Chancellor::Chancellor(string in_name,cardType ct):Personality(in_name,ct,15,5,10,8){
  cout << "We made a new CHANCELLOR with name " << in_name << endl;
}

Champion::Champion(string in_name,cardType ct):Personality(in_name,ct,30,20,20,12){
  cout << "We made a new CHAMPIO with name " << in_name << endl;
}


void Attacker::print(){
  cout<<"Printing ATTACKER"<<endl;
Personality::print();
}
void Defender::print(){
  cout<<"Printing DEFENDER "<<endl;
Personality::print();
}
void Shogun::print(){
  cout<<"Printing SHOGUN"<<endl;
Personality::print();
}
void Chancellor::print(){
  cout<<"Printing CHANCELLOR"<<endl;
Personality::print();
}

void Champion::print(){
  cout<<"Printing CHAMPION"<<endl;
  Personality::print();
}
