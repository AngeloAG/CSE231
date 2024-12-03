/***********************************************************************
 * Header File:
 *    CREW DRAGON
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Crew Dragon class.
 ************************************************************************/

#pragma once
#include "orbital.h"

class Orbital;

/*********************************************
* CREW DRAGON
* A single instance of a Crew Dragon that orbits.
*********************************************/
class CrewDragon : public Orbital
{
public:
   CrewDragon(Position* initialPos, int fragmentCount, double radius,
      Velocity* initialVelocity, Angle* initialAngle);
   ~CrewDragon() { }

   virtual list<Orbital*>& getParts()    const;
   virtual void draw(ogstream& ogstream) const;
};