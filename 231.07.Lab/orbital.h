/***********************************************************************
 * Header File:
 *    ORBITAL
 * Author:
 *    Angelo
 *    Connor
 *    Jacob
 * Summary:
 *    Orbital class.
 ************************************************************************/

#pragma once

#include "entity.h"
#include "velocity.h"
#include "angle.h"
#include <vector>

const double FRAME_RATE = 15.0;
const double GRAVITY_AT_SEA = 9.80665;
const double TIME_DIALATION = 24 * 60; //hours * minutes
const double TIME_PER_FRAME = TIME_DIALATION / FRAME_RATE;

/*********************************************
* Orbital
* A single instance of an entity that orbits.
*********************************************/
class Orbital : public Entity
{
public:
   Orbital(Position initialPos, int fragmentCount,
           double radius, Velocity initialVelocity);
   double getRadius()           { return radius; }
   int  getFragmentCount()      { return fragmentCount; }
   bool hasCrashed()            { return false; }
   void update();
   void move(Acceleration accel, double time);
   void detectCollisions(std::vector<Orbital>orbitals);
   virtual Orbital& getParts();

private:
   Velocity vel;
   Angle angle;
   double radius;
   int fragmentCount;
   bool hasCrashed;

   double getCurrentHeight()    { return 0.0; }
   double getGravityDirection() { return 0.0; }
};

inline double getGravityFromHeight(double currentHeight)
{
   double radiusAndHeight = EARTH_RADIUS / (EARTH_RADIUS + currentHeight);
   return GRAVITY_AT_SEA * (radiusAndHeight * radiusAndHeight);
}
