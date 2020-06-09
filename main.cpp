
#include <iostream>
#include <string>
#include "Item.hpp"
#include "Personality.hpp"
#include "Follower.hpp"
#include "Holding.hpp"
#include "player.hpp"
#include "gameBoard.hpp"
#include "TypeConverter.hpp"
using namespace std;



int main(void){

  gameBoard LegendOf5Rings;
  LegendOf5Rings.initializeGameBoard();
  LegendOf5Rings.printGameStatistics();
  LegendOf5Rings.finalPhase();
  LegendOf5Rings.gamePlay();
//if you uncommment these lines and comment the lines 17-21
//you'll be able to see the operations of each player function separate
  // player p1("Michalis");
  // p1.startingPhase();
  // p1.equipPhase();
  // p1.economyPhase();
  // p1.finalPhase();


}
