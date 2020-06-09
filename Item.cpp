#include <string>
#include <iostream>
#include "Item.hpp"
using namespace std;


Item::Item(string in_name,cardType ct, int in_cost , int in_ab , int in_db , int in_mh , string in_ct , int in_eb , int in_ec , int in_durability):GreenCard( in_name ,ct, in_cost , in_ab ,  in_db , in_mh ,  in_ct, in_ec ,  in_eb){
  this->durability=in_durability;
  this->type=ct;

}

void Item::print(){
  cout<<"Printing ITEM ..."<<endl;
  GreenCard::print();
}

int Item::getType(){
  return type;
}


Katana::Katana(string in_name,cardType ct):Item(in_name,ct,0,2,0,1," ",1,2,3){
  cout << "We made a new KATANA with name " << in_name << endl;
}

Spear::Spear(string in_name,cardType ct):Item(in_name,ct,0,0,2,1," ",1,2,3){
  cout << "We made a new KATANA with name " << in_name << endl;
}

Bow::Bow(string in_name,cardType ct):Item(in_name,ct,2,2,2,2," ",3,4,5){
  cout << "We made a new BOW with name " << in_name << endl;
}

Ninjato::Ninjato(string in_name,cardType ct):Item(in_name,ct,4,3,3,3," ",2,2,4){
  cout << "We made a new NINJATO with name " << in_name << endl;
}

Wakizashi::Wakizashi(string in_name,cardType ct):Item(in_name,ct,8,5,5,3," ",3,3,8){
  cout << "We made a new WAKIZASHI with name " << in_name << endl;
}

void Katana::print(){
  cout << "Printing KATANA"<<endl;
  Item::print();

}
void Spear::print(){
  cout << "Printing SPEAR "<<endl;
  Item::print();

}
void Bow::print(){
  cout << "Printing BOW "<<endl;
  Item::print();

}
void Ninjato::print(){
  cout << "Printing NINJATO "<<endl;
  Item::print();

}
void Wakizashi::print(){
  cout << "Printing WAKIZASHI"<<endl;
  Item::print();

}
