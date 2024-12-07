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
#include "GPS.h"
#include "sputnik.h"
#include "starlink.h"
#include "ship.h"
#include "hubble.h"
#include "crewDragon.h"
#include "star.h"
#include "earth.h"
#include "keyPress.h"
#include "uiInteract.h"

#include <list>
using std::list;

class Orbital;
class Ship;
class TestGame;

/*********************************************
* Game
* The simulation.
*********************************************/
class Game
{
   friend TestGame;
public:
   Game(Position* ptUpperRight);
   ~Game()
   {
       for (auto orbital : orbitals)
           delete orbital;
       delete ship;
       
       orbitals.clear();
   }
   void update();
   void draw(ogstream& og) const;
   void input(const Interface* pUI);

private:
   list<Orbital*> orbitals;
   Star stars[NUMBER_OF_STARS];
   Ship* ship;

   void createBullet();
};
