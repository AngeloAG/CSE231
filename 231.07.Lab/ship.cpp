
#include "ship.h"

/*******************************************************************************
* SHIP :: CONSTRUCTOR
*******************************************************************************/
Ship::Ship(Position* initialPos, int fragmentCount, double radius,
   Velocity& initialVelocity, Angle& initialAngle) : isThrust(false),
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
   ogstream.drawShip(*this->pos, this->angle.getRadians(), this->isThrust);
}

/*******************************************************************************
* SHIP :: THRUST
*     Applies thrust to the Ship
*******************************************************************************/
void Ship::thrust()
{
   Acceleration a(this->angle, 2.0);
   move(a, 48);
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
      this->isThrust = true;
      thrust();
      break;
   case LEFT:
      turn(true);
      break;
   case RIGHT:
      turn(false);
      break;
   case SPACE:
      break;
   default:
      break;
   }
}