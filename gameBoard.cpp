#include <iostream>
#include <string>
#include "player.hpp"
#include "Card.hpp"
#include "Holding.hpp"
#include "gameBoard.hpp"

using namespace std;

string playersNames[2]={"Makis","Sakis"};

gameBoard::gameBoard(){
  cout<<"Setting up a new GAMEBOARD..."<<endl;
}
void gameBoard::initializeGameBoard(){
  cout<<endl<<"--------INITIALIZING THE PLAYERS-------"<<endl;
  players=new player*[PLAYERS_NUM];
  for(int i=0; i < PLAYERS_NUM; i++){
    players[i]=new player(playersNames[i]);
  }
}

void gameBoard::printGameStatistics(){
  cout<<"Printing Statistics"<<endl;
  for (int i=0 ; i<PLAYERS_NUM ; i++){
    cout<<"**Player "<<i+1<<" : **"<<endl;
    cout<<"Name is : "<<this->players[i]->pGetName();
    cout<<" \t , \t Honour is : "<<this->players[i]->pGetHonour();
    cout<<" \t , \t Money is : "<<this->players[i]->pGetMoney();
    cout<<" \t , \t Initial Defense is : "<<this->players[i]->pGetInitialDefense();
    cout<<" \t and provinces are :  (calling print provinces function...)" <<endl;
    this->players[i]->printProvinces();

  }
}

void gameBoard::finalPhase(){
  cout<<"\t\t\t*****GAMEBOARD FINAL PHASE*****"<<endl;
  for (int i=0 ; i<PLAYERS_NUM ; i++){
    cout<<"\t-------PLAYER " << i+1 <<"-------" <<endl;
    this->players[i]->pFinalPhase();
  }
}

gameBoard::~gameBoard(){
  //cout<<"closing gameboard"<<endl;
  for(int i=0; i<PLAYERS_NUM ; i++){
    delete players[i];
  }
   delete[] players;
}


int gameBoard::checkWinningCondition(){
  if (players[0]->pGetProvincesNum()==0){
    return WIN_2;
  }else if (players[1]->pGetProvincesNum()==0){
    return WIN_1;
  }
  return NO_WINNER;
}

void gameBoard::printWinner(){
  int i=this->checkWinningCondition();
  cout<<"**************GAMEPLAY END*************"<<endl;
  switch (i){
    case WIN_1:
      cout<<"\t\t\t\tWinner is " <<players[WIN_1]->pGetName();
      break;
    case WIN_2:
      cout<<"\t\t\t\tWinner is " <<players[WIN_2]->pGetName();
      break;
    case NO_WINNER:
      // cout<<"\t\t\t\tSORRY , NO WINNER "<<endl;
      cout<<"\033[1;31m";
      cout<<"\t\t\t\tSORRY , NO WINNER "<<endl;
      cout<<"\033[0m";
      break;
    }
  }

  void gameBoard::gamePlay(){
    //do {
    players[0]->startingPhase();
    players[0]->equipPhase();
    //players[0]->battlephase()
    //players[0]->economyPhase();
    players[0]->pFinalPhase();
    int temp=this->checkWinningCondition();
    if(temp==NO_WINNER) {
      players[1]->startingPhase();
      players[1]->equipPhase();
      //players[0]->battlephase()
      //players[1]->economyPhase();
      players[1]->pFinalPhase();
      }
    //}while (this->checkWinningCondition()==NO_WINNER); //We commented it because it was an infinite loop
    this->printWinner();
}
