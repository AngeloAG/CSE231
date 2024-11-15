/***********************************************************************
 * Source File:
 *    ORBITAL
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Orbital class.
 ************************************************************************/

#include "orbital.h"
#include "acceleration.h"
#include <cmath>     // for SQRT() and ATAN2()

 /*******************************************************************************
 * ORBITAL :: CONSTRUCTOR
 *******************************************************************************/
Orbital::Orbital(Position& initialPos, int fragmentCount, double radius, 
   Velocity& initialVelocity, Angle& initialAngle): 
     Entity(initialPos), vel(initialVelocity), radius(radius), 
     fragmentCount(fragmentCount), hasCrashed(false), angle(initialAngle) {}

/*******************************************************************************
* ORBITAL :: GET CURRENT HEIGHT
* Description. Returns the current distance between the orbital and 
*              earth's surface
*******************************************************************************/
double Orbital::getCurrentHeight() const
{
   return sqrt((this->pos.getMetersX() * this->pos.getMetersX()) +
		  (this->pos.getMetersY() * this->pos.getMetersY())) -
		  EARTH_RADIUS;
}

/*******************************************************************************
* ORBITAL :: GET GRAVITY DIRECTION
* Description. Returns the angle at which the gravity is pulling
*******************************************************************************/
double Orbital::getGravityDirection() const
{
   return atan2(0.0 - this->pos.getMetersX(), 0.0 - this->pos.getMetersY());
}

/*******************************************************************************
* ORBITAL :: GET GRAVITY ACCELARTION
* Description. Returns the acceleration due to gravity the orbital experiences
*******************************************************************************/
Acceleration Orbital::getGravityAcceleration() const
{
   // We get the distance from the surface of the earth
   double currentHeight = getCurrentHeight();
   // Use that to calculate the current gravity experienced by the orbital
   double currentGravity = getGravityFromHeight(currentHeight);
   // Calculate the current angle the gravity is being applied
   double gravityDirection = getGravityDirection();
   Angle gravityAngle;
   gravityAngle.setRadians(gravityDirection);
   // And finally get the acceleration due to gravity
   Acceleration acc;
   acc.set(gravityAngle, currentGravity);
   return acc;
}

/*******************************************************************************
* ORBITAL :: UPDATE
* Description. Recalculates the position and velocity of the orbital 
*              due to gravity and moves it
*******************************************************************************/
void Orbital::update()
{
   // rotate a little the orbital
   this->angle.add(-(2.0 * M_PI / FRAME_RATE) *
                    (TIME_DIALATION / SECONDS_PER_DAY));
   // Get the acceleration due to gravity
   Acceleration gravityAcceleration = getGravityAcceleration();
   // And move the orbital based on gravity
   move(gravityAcceleration, TIME_PER_FRAME);
}

/*******************************************************************************
* ORBITAL :: MOVE
* Description. Acctually changes the position of the orbital
*******************************************************************************/
void Orbital::move(Acceleration& accel, double time)
{
   this->vel.add(accel, time);
   this->pos.add(accel, this->vel, time);
}

/*******************************************************************************
* ORBITAL :: DETECT COLLISIONS
* Description. Checks if the orbital has collided with any other orbital 
*              in the list
*******************************************************************************/
void Orbital::detectCollisions(std::list<Orbital*>& orbitals)
{
   for (auto orbital : orbitals)
   {
      double distanceBetween = sqrt(((orbital->pos.getMetersX() - this->pos.getMetersX()) *
                                     (orbital->pos.getMetersX() - this->pos.getMetersX())) +
                                    ((orbital->pos.getMetersY() - this->pos.getMetersY()) *
                                     (orbital->pos.getMetersY() - this->pos.getMetersY())));
      double sumOfRadii = this->getRadius() + orbital->getRadius();
      if (distanceBetween <= sumOfRadii)
      {
         this->hasCrashed = true;
      }
   }
}