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
#include <iostream>

class Orbital;
class TestShip;

/*********************************************
* SHIP
* A single instance of a Ship that orbits.
*********************************************/
class Ship : public Orbital
{
   friend TestShip;
   
public:
   Ship(Position* initialPos, int fragmentCount, double radius,
      Velocity& initialVelocity, Angle& initialAngle);
   ~Ship() { }

   virtual list<Orbital*>& getParts()    const;
   virtual void draw(ogstream& ogstream) const;
   void input(KeyPress pressed);
private:

   void thrust();
   void turn(bool isLeft) {isLeft ? angle.add(-0.1) : angle.add(0.1);}

   bool isThrust;

};