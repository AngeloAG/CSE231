/***********************************************************************
 * Source File:
 *    ORBITAL
 * Author:
 *    Angelo
 *    Connor
 *    Jacob
 * Summary:
 *    Orbital class.
 ************************************************************************/

#include "orbital.h"
#include "acceleration.h"
#include <cmath>     // for SQRT() and ATAN2()

const double EARTH_RADIUS = 6378000;
const double FRAME_RATE = 15.0;
const double TIME_DIALATION = 24 * 60; //hours * minutes
const double TIME_PER_FRAME = TIME_DIALATION / FRAME_RATE;

/*******************************************************************************
* ORBITAL :: GET CURRENT HEIGHT
*  Description.
*******************************************************************************/
double Orbital::getCurrentHeight()
{
   return sqrt((this->pos.getMetersX() * this->pos.getMetersX()) +
		  (this->pos.getMetersY() * this->pos.getMetersY())) -
		  EARTH_RADIUS;
}

/*******************************************************************************
* ORBITAL :: GET GRAVITY DIRECTION
*  Description.
*******************************************************************************/
double Orbital::getGravityDirection()
{
   return atan2(0.0 - this->pos.getMetersX(), 0.0 - this->pos.getMetersY());
}

/*******************************************************************************
* ORBITAL :: GET GRAVITY DIRECTION
*  Description.
*******************************************************************************/
void Orbital::update()
{
   // We get the distance from the surface of the earth
   double currentHeight = getCurrentHeight();
   // Use that to calculate the current gravity experienced by the orbital
   double currentGravity = getGravityFromHeight(currentHeight);
   // Calculate the current angle the gravity is being applied
   double gravityDirection = getGravityDirection();
   // And finally get the acceleration due to gravity
   Acceleration gravityAcceleration(currentGravity, gravityDirection);
   // And move the orbital based on gravity
   move(gravityAcceleration, TIME_PER_FRAME);
}