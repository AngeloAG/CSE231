/***********************************************************************
 * Header File:
 *    GPS
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    GPS class.
 ************************************************************************/

#pragma once
#include "orbital.h"

class Orbital;

/*********************************************
* GPS
* A single instance of a GPS that orbits.
*********************************************/
class GPS : public Orbital
{
public:
   GPS(Position* initialPos, int fragmentCount, double radius,
      Velocity& initialVelocity, Angle* initialAngle);
   ~GPS() { }

   virtual list<Orbital*>& getParts()    const;
   virtual void draw(ogstream& ogstream) const;
};