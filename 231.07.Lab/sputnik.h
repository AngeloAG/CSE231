/***********************************************************************
 * Header File:
 *    Sputnik
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Sputnik class.
 ************************************************************************/

#pragma once
#include "orbital.h"

class Orbital;

/*********************************************
* GPS
* A single instance of a GPS that orbits.
*********************************************/
class Sputnik : public Orbital
{
public:
   Sputnik();
   Sputnik(Position* initialPos, int fragmentCount, double radius,
      Velocity* initialVelocity, Angle* initialAngle);
   ~Sputnik() { }

   virtual list<Orbital*>& getParts()    const;
   virtual void draw(ogstream& ogstream) const;
};