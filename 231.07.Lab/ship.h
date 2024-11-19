/***********************************************************************
 * Header File:
 *    SHIP
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Ship class.
 ************************************************************************/

#pragma once
#include "orbital.h"
#include "keyPress.h"
#include "acceleration.h"

class Orbital;

/*********************************************
* SHIP
* A single instance of a Ship that orbits.
*********************************************/
class Ship : public Orbital
{
public:
   Ship(Position* initialPos, int fragmentCount, double radius,
      Velocity& initialVelocity, Angle& initialAngle);
   ~Ship() { }

   virtual list<Orbital*>& getParts()    const;
   virtual void draw(ogstream& ogstream) const;
   void input(KeyPress pressed);
private:

   void thrust();

   bool isThrust;

};