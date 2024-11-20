/***********************************************************************
 * Header File:
 *    ORBITAL
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Orbital class.
 ************************************************************************/

#pragma once

#include "entity.h"
#include "velocity.h"
#include "angle.h"
#include "constants.h"
#include <list>
using std::list;

class TestOrbital;
class TestShip;

/*********************************************
* Orbital
* A single instance of an entity that orbits.
*********************************************/
class Orbital : public Entity
{
   friend TestOrbital;
   friend TestShip;
   
public:
   Orbital(Position* initialPos, int fragmentCount, double radius, 
           Velocity& initialVelocity, Angle& initialAngle);
   ~Orbital()                    {                       }
   double getRadius()      const { return radius;        }
   int  getFragmentCount() const { return fragmentCount; }
   bool crashed()          const { return hasCrashed;    }
   virtual void update();
   void move(Acceleration& accel, double time);
   void detectCollisions(list<Orbital*>& orbitals);
   virtual list<Orbital*>& getParts() const = 0;
   virtual void draw(ogstream& ogstream) const {}

protected:
   Angle angle;
   Acceleration getGravityAcceleration() const;

private:
   Velocity vel;
   double radius;
   int fragmentCount;
   bool hasCrashed;

   double getCurrentHeight() const;
   double getGravityDirection() const;
};

/*******************************************************************************
* INLINE :: GET GRAVITY FROM HEIGHT
*     Helper function to determine the force of gravity at a certain height.
*******************************************************************************/
inline double getGravityFromHeight(double currentHeight)
{
   double radiusAndHeight = EARTH_RADIUS / (EARTH_RADIUS + currentHeight);
   return GRAVITY_AT_SEA * (radiusAndHeight * radiusAndHeight);
};

/*********************************************
* DummyOrbital
* An dummy class to test the orbital.
*********************************************/
class DummyOrbital : public Orbital
{
public:
   DummyOrbital(Position* initialPos, int fragmentCount, double radius,
      Velocity& initialVelocity, Angle& initialAngle): 
            Orbital(initialPos, fragmentCount, radius,
                    initialVelocity, initialAngle) {  }

   list<Orbital*>& getParts() const
   {
      list<Orbital*> emptyList;
      return emptyList;
   }
};
