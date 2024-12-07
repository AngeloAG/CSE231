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
#include "acceleration.h"

class Orbital;

/*********************************************
* STARLINK
* A single instance of a Starlink that orbits.
*********************************************/
class Starlink : public Orbital
{
public:
   Starlink();
   Starlink(Position* initialPos, Velocity* initialVelocity,
            Angle* initialAngle);
   ~Starlink() { }

   virtual list<Orbital*> getParts()     const;
   virtual void draw(ogstream& ogstream) const;
};

/*********************************************
* STARLINKBODY
* A single instance of a Starlink body that orbits.
*********************************************/
class StarlinkBody : public Orbital
{
public:
   StarlinkBody();
   StarlinkBody(Position* initialPos, Velocity* initialVelocity,
                Angle* initialAngle) : Orbital(initialPos, 3, 2.0,
                                               initialVelocity,
                                               initialAngle) {    }
   ~StarlinkBody() { }

   virtual list<Orbital*> getParts()     const { return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const
   {
      ogstream.drawStarlinkBody(*this->pos, this->angle->getRadians());
   };
};

/*********************************************
* STARLINKARRAY
* A single instance of a Starlink body that orbits.
*********************************************/
class StarlinkArray : public Orbital
{
public:
   StarlinkArray();
   StarlinkArray(Position* initialPos, Velocity* initialVelocity,
                 Angle* initialAngle) : Orbital(initialPos, 3, 4.0,
                                                initialVelocity,
                                                initialAngle) {    }
   ~StarlinkArray() { }

   virtual list<Orbital*> getParts()     const { return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const
   {
      ogstream.drawStarlinkArray(*this->pos, this->angle->getRadians());
   };
};
