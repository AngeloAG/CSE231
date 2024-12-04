/***********************************************************************
 * Header File:
 *    STARLINK
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Starlink class.
 ************************************************************************/

#pragma once
#include "orbital.h"

class Orbital;

/*********************************************
* STARLINK
* A single instance of a Starlink that orbits.
*********************************************/
class Starlink : public Orbital
{
public:
   Starlink();
   Starlink(Position* initialPos, int fragmentCount, double radius,
      Velocity* initialVelocity, Angle* initialAngle);
   ~Starlink() { }

   virtual list<Orbital*> getParts()    const;
   virtual void draw(ogstream& ogstream) const;
};