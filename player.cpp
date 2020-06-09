#include "player.hpp"
#include "DeckBuilder.h"
#include "TypeConverter.hpp"
#include "Personality.hpp"
#include "Follower.hpp"
#include "Item.hpp"
#include "gameBoard.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#define ARMY_NUM 3
#define HOLDING_NUM 5
#define PROVINCES_NUM 4
using namespace std;


int follower_count=0;
int item_count=0;

player::player(string in_name){
  this->name=in_name;
  this->playersStronghold=new Stronghold("playersStronghold");
  this->money= this->playersStronghold->getMoney();
  //------INITIALIZE LISTS
  this->fateDeck = new list<GreenCard *>();
	this->dynastyDeck = new list<BlackCard *>();
  this->hand= new list<GreenCard*>();
  this->holdings=new list<BlackCard *>();
  this->army=new list<BlackCard *>();
  this->provinces=new list<BlackCard*>();

  DeckBuilder playersDeck;
  playersDeck.deckShuffler(this->fateDeck); //suffle the deck
  this->fateDeck=playersDeck.createFateDeck(); //and set it to the player
  playersDeck.deckShuffler(this->dynastyDeck);
  this->dynastyDeck=playersDeck.createDynastyDeck();

  this->initialDefense=playersStronghold->getInitialDefense();
  this->numOfProvinces=4;
  //-----IN THIS SECTION WE ARE MAKING THE HAND OUT OF RANDOM GREEN CARDS
  cout<<"----MAKING THE HAND..."<<endl;
  vector <GreenCard*> GreenCardVector; //we set a temporary vector
  list <GreenCard*>::iterator it1;
  int pos , GreenCardNum=fateDeck->size();
  for (it1=fateDeck->begin(); it1 != fateDeck->end(); it1++ )
    GreenCardVector.push_back((*it1)); //to hold all the cards from the deck .It's like a copy of the deck but as vector not as list.

  for (int i=0 ; i<6 ; i++){
    pos=rand()%GreenCardNum ;
    // hand->push_back(GreenCardVector[i]);
    hand->push_back(GreenCardVector[pos]);
    // v1.pop(v1[pos]);
    cout<<"PUSHING IN HAND"<<endl;
  }
  cout << "PUSHING HAND END"<<endl;

  //-----IN THIS SECTION WE ARE MAKING THE ARMY AND THE HOLDINGS OUT OF RANDOM BLACK CARDS
  cout<<"----MAKING THE HOLDINGS & ARMY"<<endl;
  vector <BlackCard*> holdingVector;
  vector <BlackCard*> personalityVector;
  list <BlackCard*>::iterator it2;
  int BlackCardNum=dynastyDeck->size();
  for (it2=dynastyDeck->begin(); it2 != dynastyDeck->end(); it2++ ) {
    if ((*it2)->getType()==HOLDING) {
      holdingVector.push_back((*it2));
      // cout <<"THIS CARD IS HOLDING"<< i<<endl;
    }
    else if((*it2)->getType()==PERSONALITY){
      personalityVector.push_back((*it2));
      // cout <<"THIS CARD IS PERSONALITY"<< i <<endl;
    }

  }
  int holdingNum=holdingVector.size();
  int personalityNum=personalityVector.size();

  for (int i=0 ; i<HOLDING_NUM ; i++){
    pos=rand()%holdingNum;
    // holdings->push_back(holdingVector[i]); //this line is to take not random cards but the first i cards
    holdings->push_back(holdingVector[pos]); //this line is to take random card and add it to the deck
    cout<<"PUSHING IN HOLDINGS"<<endl;
  }
  cout<<"PUSHING IN HOLDINGS END"<<endl;

  for (int i=0 ; i<ARMY_NUM ; i++){
    pos=rand()%personalityNum;
    //army->push_back(personalityVector[i]);
    army->push_back(personalityVector[pos]); ////this line is to take random card and add it to the deck
    cout<<"PUSHING IN ARMY"<<endl;
  }
  cout<<"PUSHING IN ARMY END"<<endl;
  //-----IN THIS SECTION WE ARE MAKING THE PROVINCES OUT OF RANDOM BLACK CARDS
  cout << "----MAKING THE PROVINCES"<<endl;
  vector <BlackCard*> provincesVector;
  list <BlackCard*>::iterator it3;
  for (it3=dynastyDeck->begin(); it3 != dynastyDeck->end(); it3++ )
    provincesVector.push_back((*it3)); //to hold all the cards from the deck .It's like a copy of the deck but as vector not as list.

  for (int i=0 ; i<4 ; i++){
    pos=rand()%BlackCardNum ;
    provinces->push_back(provincesVector[i]);
     // provinces->push_back(provincesVector[pos]); ////this line is to take random card and add it to the deck
    cout<<"PUSHING IN PROVINCES"<<endl;
  }
  cout<<"PUSHING IN PROVINCES END"<<endl;

  //We don't need the vectors yet so,
  holdingVector.clear();
  personalityVector.clear();
  provincesVector.clear();

  holdingVector.shrink_to_fit();
  personalityVector.shrink_to_fit();
  provincesVector.shrink_to_fit();

  cout << "We created a new player with name : " <<in_name <<" and has " <<numOfProvinces << " provinces." <<endl;

}
void player::printMoney(){
  cout<<"Player "<<name<<" has " <<money<<" money"<<endl;
}
void player::printHand(){
  cout<<"\t\t\t*******PRINTING HAND WITH SIZE "<<hand->size()<<endl;
  list<GreenCard*>::iterator it;
  for ( it=hand->begin(); it!= hand->end() ; it++ )
    (*it)->print();
}

void player::printHoldings(){
  cout<<"\t\t\t*******PRINTING HOLDING WITH SIZE "<<holdings->size()<<endl;
  list<BlackCard*>::iterator it ;
  for ( it=holdings->begin(); it!=holdings->end(); it++)
    (*it)->print();
}

void player::printArmy(){
  cout<<"\t\t\t*******PRINTING ARMY WITH SIZE "<<army->size()<<endl;
  list<BlackCard*>::iterator it ;
  for (it=army->begin(); it != army->end(); it++ )
    (*it)->print();
}

player::~player(){
  list<GreenCard*>::iterator it1;
  list<BlackCard*>::iterator it2;
  for (it1 = fateDeck->begin(); it1 != fateDeck->end(); it1++)
	{
		fateDeck->remove((*it1));
		delete *it1;
		it1 = fateDeck->begin();
	}

  for (it2 = dynastyDeck->begin(); it2 != dynastyDeck->end(); it2++)
	{
		dynastyDeck->remove((*it2));
		delete *it2;
		it2 = dynastyDeck->begin();
	}

  delete fateDeck;
  delete dynastyDeck ;

}

void player::sethonour(int h){
  honour=h;
}

void player::untapEverything(){
  list<GreenCard*>::iterator it1;
  list<BlackCard*>::iterator it2;
  list<BlackCard*>::iterator it3;
  list<BlackCard*>::iterator it4;

  for (it1 = hand->begin(); it1 != hand->end(); it1++)
    (*it1)->cardUntap();

  for (it2 = holdings->begin(); it2 != holdings->end(); it2++)
    (*it2)->cardUntap();

  for (it3 = army->begin(); it3 != army->end(); it3++)
    (*it3)->cardUntap();

  for (it4 = provinces->begin(); it4 != provinces->end(); it4++)
    (*it4)->cardUntap();
}

void player::drawFateCard(){
  cout <<"FATE DECK CONTAINS "<<this->fateDeck->size()<<endl;
  list<GreenCard*>::iterator it=this->fateDeck->begin();

  hand->push_back(*it);
  cout<<"------THATS THE CARD THAT THE PLAYER TAPPED"<<endl;
  (*it)->print();
  cout<<"After  drawFateCard...Hand size is : " <<hand->size()<<endl;
}

void player::revealProvinces(){
  list<BlackCard*>::iterator it;
  for (it = provinces->begin(); it != provinces->end(); it++)
    (*it)->cardReveal();
}

void player::printProvinces(){
  cout<<"\t\t\t******PRINT PROVINCES WITH SIZE"<<this->provinces->size()<<endl;
  list<BlackCard*>::iterator it;
  for (it = provinces->begin(); it != provinces->end(); it++)
    (*it)->print();
}

void player::startingPhase(){
  cout<<endl<<"------------------STARTING PHASE------------------"<<endl;
  this->untapEverything();
  this->drawFateCard();
  this->revealProvinces();
  cout<<"\t\t\tPRINTING HAND IN STARTING PHASE,AFTER ADDING 1 CARD "<<endl;
  this->printHand();
  cout<<"\t\t\tPRINTING PROVINCES IN STARTING PHASE"<<endl;
  this->printProvinces();
}

void player::equipPhase(){
  list<GreenCard*>::iterator it;
  list<BlackCard*>::iterator it2;
  Follower* follower;
  Item* item;
  Personality* person;
  TypeConverter conv;

  cout<<endl<<"-----------------EQUIP PHASE----------------------"<<endl;
  for(it2=army->begin(); it2 != army->end(); it2++){
    follower_count=0;
    item_count=0;
    for(it=hand->begin(); it != hand->end(); it++){
      conv.getCorrectType((*it),&follower,&item);
      follower=conv.getFollower((*it));
      item=conv.getItem((*it));
      person=conv.getPersonality((*it2));



      if(follower!=NULL )
        if(person->getHonour() > follower->getMinimumHonour()){
          if(follower_count < MAX_FOLLOWERS ){
          person->setFollowers(follower);
          follower_count++;
          person->setAttack(follower->getAttackB());
          person->setDefense(follower->getDefenseB());

          follower->Tap();
        }
      }
      if(item!=NULL )
        if(this->pGetMoney() > item->getCost()){
          if(item_count < MAX_ITEMS){
          setMoney(item->getCost());
          person->setItems(item);
          item_count++;
          person->setAttack(item->getAttackB());
          person->setDefense(item->getDefenseB());

          item->Tap();
        }
      }


    }

}
   for(it2=army->begin(); it2 != army->end(); it2++){
   cout<<"------------PRINTING FOLLOWERS LIST---------------"<<endl;
   person->printFollowers();
  }

    for(it2=army->begin(); it2 != army->end(); it2++){
      cout<<"------------PRINTING ITEMS LIST---------------"<<endl;
      person->printItems();
    }

}

int player::pGetMoney(){
  return this->money;
}


void player::economyPhase(){
  cout<<endl<<"-----------------ECONOMY PHASE ----------------------"<<endl;
  this->revealProvinces();
  //buying ...
  list<BlackCard*>::iterator it3=provinces->begin();
  list<BlackCard*>::iterator it4=provinces->begin();;
  for(int i=0 ; i< PROVINCES_NUM ; i++){
      int tmp=(*it4)->getCost();
    if(tmp<=this->pGetMoney()) {
      this->army->push_back((*it4));
      (*it4)->cardUntap();
      this->printMoney();
      this->money-=tmp;
      provinces->erase(it4);
      // cout<<"PROVINCE SIZE IS"<<provinces->size()<<endl;
      list<BlackCard*>::iterator it2=dynastyDeck->begin();
      provinces->push_back(*(it2));
      // cout<<"PROVINCE SIZE IS"<<provinces->size()<<endl;
      cout<<"Just bought a card."<<endl;
    }else break;
  }
  this->printMoney();
}

void player::pFinalPhase(){
  //CHECK IF ALL DECKS HAVE SIZE BIGGER THAN THE MAXIMUM
      //------FATE DECK -----
  list<GreenCard*>::iterator it1=fateDeck->begin();
  int fateSize=this->fateDeck->size();

  if(fateSize>MAXDECKSIZE){ //and if the deck has more cards than the maximum
    int extraCards=fateSize-MAXDECKSIZE; //find the difference between the maximum size of the deck and the current deck size
    for(int i=0 ; i<extraCards ; i++){ //and for each extra card
      this->fateDeck->erase(it1); //remove it from the deck
      it1=this->fateDeck->begin(); //set the iterator to the start of the deck
    }
  }

//P.S. We are following the same logic as the fate deck , as the others decks of the player

    //------DYNASTY DECK -----
  list<BlackCard*>::iterator it2=this->dynastyDeck->begin();
  int dynastySize=this->dynastyDeck->size();
  if(dynastySize>MAXDECKSIZE){
    int extraCards=dynastySize-MAXDECKSIZE;
    for(int i=0 ; i<extraCards ; i++){
      this->dynastyDeck->erase(it2);
      it2=this->dynastyDeck->begin();
    }
  }

  //-----HAND-------

  //notice:you can uncomment lines 323-325 to check if the code works 100%.We add new cards at the deck
  //and then we are sure that the deck has more cards  than the maximum size

  // this->hand->push_back(new Cavalry("Unicorn Horses"));
  // this->hand->push_back(new Atakebune("Yomi Ships"));
  // this->printHand();
  list<GreenCard*>::iterator it3=this->hand->begin();
  int handSize=this->hand->size();
  //cout<<"hand size is "<<hand->size()<<endl;
  if(handSize>6){
    int extraCards=handSize-6;
    for(int i=0 ; i<extraCards ; i++){
      this->hand->erase(it3);
      it3=this->hand->begin();

    }
  }

  //-----HOLDINGS-----
  list<BlackCard*>::iterator it4=this->holdings->begin();
  int holdingsSize=this->holdings->size();
  if(holdingsSize>HOLDING_NUM){
    int extraCards=holdingsSize-HOLDING_NUM;
    for(int i=0 ; i<extraCards ; i++){
      this->holdings->erase(it4);
      it4=this->holdings->begin();
    }
  }

  //-----ARMY----
  list<BlackCard*>::iterator it5=this->army->begin();
  int armySize=this->army->size();
  if(armySize>ARMY_NUM){
    int extraCards=armySize-ARMY_NUM;
    for(int i=0 ; i<extraCards ; i++){
      this->army->erase(it5);
      it5=this->army->begin();
    }
  }

  //----PROVINCES----
  list<BlackCard*>::iterator it6=this->provinces->begin();
  int provincesSize=this->provinces->size();
  if(provincesSize>PROVINCES_NUM){
    int extraCards=provincesSize-PROVINCES_NUM;
    for(int i=0 ; i<extraCards ; i++){
      this->provinces->erase(it6);
      it6=this->provinces->begin();
    }
  }
this->printHand();
this->printProvinces();
this->printArmy(); //is the same as printArena()
this->printHoldings();
}

string player::pGetName(){
  return this->name;
}

int player::pGetHonour(){
  return this->honour;
}

int player::pGetInitialDefense(){
  return this->initialDefense;
}
int player::pGetProvincesNum(){
  return this->numOfProvinces;
}

void player::setMoney(int m){
  this->money-=m;
}
