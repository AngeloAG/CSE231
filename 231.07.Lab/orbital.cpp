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
// #include "fragment.h"
#include <cmath>     // for SQRT() and ATAN2()

 /*******************************************************************************
 * ORBITAL :: CONSTRUCTOR
 *******************************************************************************/
Orbital::Orbital(Position* initialPos, int fragmentCount, double radius, 
   Velocity* initialVelocity, Angle* initialAngle): 
     Entity(initialPos), vel(initialVelocity), radius(radius), 
     fragmentCount(fragmentCount), hasCrashed(false), angle(initialAngle) {}

/*******************************************************************************
* ORBITAL :: GET CURRENT HEIGHT
*     Returns the current distance between the orbital and earth's surface
*******************************************************************************/
double Orbital::getCurrentHeight() const
{
   return sqrt((this->pos->getMetersX() * this->pos->getMetersX()) +
		  (this->pos->getMetersY() * this->pos->getMetersY()))     -
		  EARTH_RADIUS;
}

/*******************************************************************************
* ORBITAL :: GET GRAVITY DIRECTION
*     Returns the angle at which the gravity is pulling
*******************************************************************************/
double Orbital::getGravityDirection() const
{
   return atan2(0.0 - this->pos->getMetersX(), 0.0 - this->pos->getMetersY());
}

/*******************************************************************************
* ORBITAL :: GET GRAVITY ACCELARTION
*     Returns the acceleration due to gravity the orbital experiences
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
*     Recalculates the position and velocity of the orbital due
*     to gravity and moves it
*******************************************************************************/
void Orbital::update()
{
   // rotate a little the orbital
   // this->angle.add(-(2.0 * M_PI / FRAME_RATE) *
                    // (TIME_DIALATION / SECONDS_PER_DAY));

   // Get the acceleration due to gravity
   Acceleration gravityAcceleration = getGravityAcceleration();

   // And move the orbital based on gravity
   move(gravityAcceleration, TIME_PER_FRAME);
}

/*******************************************************************************
* ORBITAL :: MOVE
*     Actually changes the position of the orbital
*******************************************************************************/
void Orbital::move(const Acceleration& accel, double time)
{
   this->vel->add(accel, time / 2.0);
   this->pos->add(accel, *this->vel, time);
   this->vel->add(accel, time / 2.0);
}

/*******************************************************************************
* ORBITAL :: DETECT COLLISIONS
*     Checks if the orbital has collided with any other orbital in the list
*******************************************************************************/
void Orbital::detectCollisions(const std::list<Orbital*>& orbitals)
{
   for (auto orbital : orbitals)
   {
      if (this != orbital) // Make sure we are not comparing to ourselves
      {
         double distanceBetween = computeDistance(*this->pos, orbital->getPos());

         double sumOfRadii = this->getRadius() + orbital->getRadius();
         if (distanceBetween <= sumOfRadii)
         {
            this->hasCrashed = true;
         }
      }
   }
}

/*******************************************************************************
* ORBITAL :: DESTROY
*     Puts the parts and fragments into a list
*******************************************************************************/
void Orbital::destroy(list<Orbital*>& orbitals)
{
   orbitals.remove(this);
   
   list<Orbital*> fragments = this->getFragments();

   list<Orbital*> parts = this->getParts();

   for (auto part : parts)
   {
      orbitals.push_back(part);
   }
   
   for (auto fragment : fragments)
   {
      orbitals.push_back(fragment);
   }
}

/*******************************************************************************
* ORBITAL :: DESTROY
*     Puts the parts and fragments into a list
*******************************************************************************/
list<Orbital*> Orbital::getFragments() const
{
   list<Orbital*> fragments;
   double randomStartAngle = 0.0;
   if (useRandom)
      randomStartAngle = random(0.0, 360.0);

   for (int i = 0; i < fragmentCount; i++)
   {
      Angle* fragmentAngle = new Angle(randomStartAngle +
                                       (360/fragmentCount * i));
      Position* fragmentPosition = new Position(*this->pos);
      fragmentPosition->addPixelsX((4 + this->radius) * cos(fragmentAngle->getRadians()));
      fragmentPosition->addPixelsY((4 + this->radius) * sin(fragmentAngle->getRadians()));
      
      Velocity* fragmentVelocity = new Velocity(*this->vel);
      double fragmentSpeed = random(50, 90);
      Acceleration fragmentAcceleration(*fragmentAngle, fragmentSpeed);
      fragmentVelocity->add(fragmentAcceleration, TIME_PER_FRAME);
      
      fragments.push_back(new Fragment(fragmentPosition,fragmentVelocity,
                                       fragmentAngle));
   }
   
   return fragments;
}
