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
#include "acceleration.h"

class Orbital;

/*********************************************
* CREW DRAGON
* A single instance of a Crew Dragon that orbits.
*********************************************/
class CrewDragon : public Orbital
{
public:
   CrewDragon(); 
   CrewDragon(Position* initialPos, Velocity* initialVelocity,
              Angle* initialAngle);
   ~CrewDragon() { }

   virtual list<Orbital*> getParts()     const;
   virtual void draw(ogstream& ogstream) const;
};

/*********************************************
* CREW DRAGON Center
* A single instance of a Crew Dragon  center that orbits.
*********************************************/
class CrewDragonCenter : public Orbital
{
public:
   CrewDragonCenter();
   CrewDragonCenter(Position* initialPos, Velocity* initialVelocity,
                    Angle* initialAngle) : Orbital(initialPos, 4, 6.0,
                                                   initialVelocity,
                                                   initialAngle) {    }

   ~CrewDragonCenter() { }

   virtual list<Orbital*> getParts()     const { return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const
   {
      ogstream.drawCrewDragonCenter(*this->pos, this->angle->getRadians());
   };
};

/*********************************************
* CREW DRAGON Left
* A single instance of a Crew Dragon  left that orbits.
*********************************************/
class CrewDragonLeft : public Orbital
{
public:
   CrewDragonLeft();
   CrewDragonLeft(Position* initialPos, Velocity* initialVelocity,
                  Angle* initialAngle) : Orbital(initialPos, 2, 6.0,
                                                 initialVelocity,
                                                 initialAngle) {    }

   ~CrewDragonLeft() { }

   virtual list<Orbital*> getParts()     const { return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const
   {
      ogstream.drawCrewDragonLeft(*this->pos, this->angle->getRadians());
   };
};

/*********************************************
* CREW DRAGON Right
* A single instance of a Crew Dragon  right that orbits.
*********************************************/
class CrewDragonRight : public Orbital
{
public:
   CrewDragonRight();
   CrewDragonRight(Position* initialPos, Velocity* initialVelocity,
                   Angle* initialAngle) : Orbital(initialPos, 2, 6.0,
                                                  initialVelocity,
                                                  initialAngle) {    }

   ~CrewDragonRight() { }

   virtual list<Orbital*> getParts()     const { return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const
   {
      ogstream.drawCrewDragonRight(*this->pos, this->angle->getRadians());
   };
};
