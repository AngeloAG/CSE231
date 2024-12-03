/***********************************************************************
 * Source File:
 *    Ship
 * Author:
 *    Jacob Mower
 *    Angelo Arellano Gaona
 *    Connor Hopkins
 * Summary:
 *    Ship class
 ************************************************************************/

#include "ship.h"

/*******************************************************************************
* SHIP :: DEFAULT CONSTRUCTOR
*******************************************************************************/
Ship::Ship() :
   Orbital(new Position(), 0, 10.0,
      new Velocity(0.0, -2000.0), new Angle()), isThrust(false) 
{
   this->pos->setPixelsX(-450);
   this->pos->setPixelsY(450);
}

/*******************************************************************************
* SHIP :: CONSTRUCTOR
*******************************************************************************/
Ship::Ship(Position* initialPos, int fragmentCount, double radius,
   Velocity* initialVelocity, Angle* initialAngle) : isThrust(false),
   Orbital(initialPos, fragmentCount, radius, initialVelocity, initialAngle) {}

/*******************************************************************************
* SHIP :: GET SHIP PARTS
*     Returns the parts the SHIP breaks into
*******************************************************************************/
list<Orbital*>& Ship::getParts() const
{
   list<Orbital*> emptyList; // This is just a placeholder for next labs
   return emptyList;
}

/*******************************************************************************
* SHIP :: DRAW
*     Draws the Ship in the screen
*******************************************************************************/
void Ship::draw(ogstream& ogstream) const
{
   ogstream.drawShip(*this->pos, this->angle->getRadians(), this->isThrust);
}

/*******************************************************************************
* SHIP :: THRUST
*     Applies thrust to the Ship
*******************************************************************************/
void Ship::thrust()
{
   Acceleration a(*this->angle, 2.0);
   this->vel->add(a, 48);
   this->isThrust = true;
}

/*******************************************************************************
* SHIP :: INPUT
*     Determines what happens when keys are pressed
*******************************************************************************/
void Ship::input(KeyPress pressed)
{
   switch (pressed)
   {
   case DOWN:
      thrust();
      break;
   case LEFT:
      turnLeft();
      break;
   case RIGHT:
      turnRight();
      break;
   case SPACE:
      break;
   default:
      break;
   }
}

/*******************************************************************************
* SHIP :: UPDATE
*     Ensures flames are properly drawn.
*******************************************************************************/
void Ship::update()
{
   Orbital::update();
   this->isThrust = false;
}
