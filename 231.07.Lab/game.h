/***********************************************************************
 * Header File:
 *    GAME
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Game class.
 ************************************************************************/

#pragma once

#include "constants.h"
#include "entity.h"
#include <list>
using std::list;

class Orbital;
class Ship;

/*********************************************
* Game
* The simulation.
*********************************************/
class Game
{

public:
   Game();
   ~Game() { } // Prevent memory leaks
  /* void update();
   void draw() const;*/

private:
   //list<Orbital*> orbitals;
   //Entity stars[NUMBER_OF_STARS];
   //Ship* ship;

   /*void createBullet();*/
};