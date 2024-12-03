/***********************************************************************
 * Header File:
 *    Hubble
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Hubble class.
 ************************************************************************/

#pragma once
#include "orbital.h"

class Orbital;
class TestHubble;

/*********************************************
* Hubble
* A single instance of a Hubble that orbits.
*********************************************/
class Hubble : public Orbital
{
   friend TestHubble;
public:
   Hubble();
   Hubble(Position* initialPos, int fragmentCount, double radius,
      Velocity* initialVelocity, Angle* initialAngle);
   ~Hubble() { }

   virtual list<Orbital*>& getParts()    const;
   virtual void draw(ogstream& ogstream) const;
};
