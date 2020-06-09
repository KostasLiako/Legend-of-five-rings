#include <string>
#include <iostream>
#include "Follower.hpp"
using namespace std;



Follower::Follower(string in_name,cardType ct, int in_cost , int in_ab , int in_db , int in_mh , string in_ct , int in_eb , int in_ec) : GreenCard( in_name ,ct,  in_cost , in_ab ,  in_db , in_mh ,  in_ct,in_ec , in_eb) {
  type=ct;
}

void Follower::print(){
  cout<<"Printing a FOLLOWER CARD " <<endl;
  GreenCard::print();
}

int Follower::getType(){
  return type;
}


int Follower::getMinimumHonour(){
  return minimumHonour;
}


Footsoldier::Footsoldier(string in_name,cardType ct):Follower(in_name,ct,0,2,0,1," ",1,2){
  cout << "We made a new FOOTSOLDIER with name " << in_name <<endl;
}


Archer::Archer(string in_name,cardType ct):Follower(in_name,ct,0,0,2,1," ",1,2){
  cout << "We made a new ARCHER with name " << in_name <<endl;
}

Sieger::Sieger(string in_name,cardType ct):Follower(in_name,ct,5,3,3,2," ", 2,3){
  cout << "We made a new SIEGER with name " << in_name <<endl;
}

Cavalry::Cavalry(string in_name,cardType ct):Follower(in_name,ct,3,4,2,3," ",3,4){
  cout << "We made a new CAVALRY with name " << in_name <<endl;
}

Naval::Naval(string in_name,cardType ct):Follower(in_name,ct,3,2,4,3," ",3,4){
  cout << "We made a new NAVAL with name " << in_name <<endl;
}

Bushido::Bushido(string in_name,cardType ct):Follower(in_name,ct,8,8,8,6," ",3,8){
  cout << "We made a new BUSHIDO with name " << in_name <<endl;
}


Atakebune::Atakebune(string in_name,cardType ct):Follower(in_name,ct,3,2,4,3," ",3,4){
  cout << "We made a new Atakebune with name " << in_name <<endl;
}




void Footsoldier::print(){
  cout<< "PRINTING Footsoldier" <<endl;
  Follower::print();
}


void Archer::print(){
  cout<< "PRINTING ARCHER" <<endl;
  Follower::print();
}

void Sieger::print(){
  cout<< "PRINTING SIEGER" <<endl;
  Follower::print();
}

void Cavalry::print(){
  cout<< "PRINTING CAVALRY" <<endl;
  Follower::print();
}

void Naval::print(){
  cout<< "PRINTING NAVAL" <<endl;
  Follower::print();
}

void Bushido::print(){
  cout<< "PRINTING BUSHIDO" <<endl;
  Follower::print();
}

void Atakebune::print(){
  cout<< "PRINTING ATAKEBUNE" <<endl;
  Follower::print();
}
