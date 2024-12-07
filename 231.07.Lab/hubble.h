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
#include "acceleration.h"

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
   Hubble(Position* initialPos, Velocity* initialVelocity, Angle* initialAngle);
   ~Hubble() { }

   virtual list<Orbital*> getParts()     const;
   virtual void draw(ogstream& ogstream) const;
};

/*********************************************
* Hubble telescope
* A single instance of a Hubble telescope that orbits.
*********************************************/
class HubbleTelescope : public Orbital
{
   friend TestHubble;
public:
   HubbleTelescope();
   HubbleTelescope(Position* initialPos, Velocity* initialVelocity,
                   Angle* initialAngle) : Orbital(initialPos, 3, 10.0,
                                                  initialVelocity,
                                                  initialAngle) {     }
   ~HubbleTelescope() { }

   virtual list<Orbital*> getParts()     const { return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const
   {
      ogstream.drawHubbleTelescope(*this->pos, this->angle->getRadians());
   };
};

/*********************************************
* Hubble Computer
* A single instance of a Hubble computer that orbits.
*********************************************/
class HubbleComputer : public Orbital
{
   friend TestHubble;
public:
   HubbleComputer();
   HubbleComputer(Position* initialPos, Velocity* initialVelocity,
                  Angle* initialAngle) : Orbital(initialPos, 2, 7.0,
                                                 initialVelocity,
                                                 initialAngle) {    }
   ~HubbleComputer() { }

   virtual list<Orbital*> getParts()     const { return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const
   {
      ogstream.drawHubbleComputer(*this->pos, this->angle->getRadians());
   };
};

/*********************************************
* Hubble Left side
* A single instance of a Hubble Left that orbits.
*********************************************/
class HubbleLeft: public Orbital
{
   friend TestHubble;
public:
   HubbleLeft();
   HubbleLeft(Position* initialPos, Velocity* initialVelocity,
              Angle* initialAngle) : Orbital(initialPos, 2, 8.0,
                                             initialVelocity,
                                             initialAngle) {    }
   ~HubbleLeft() { }

   virtual list<Orbital*> getParts()     const { return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const
   {
      ogstream.drawHubbleLeft(*this->pos, this->angle->getRadians());
   };
};

/*********************************************
* Hubble Right side
* A single instance of a Hubble right that orbits.
*********************************************/
class HubbleRight : public Orbital
{
   friend TestHubble;
public:
   HubbleRight();
   HubbleRight(Position* initialPos, Velocity* initialVelocity,
               Angle* initialAngle) : Orbital(initialPos, 2, 8.0,
                                              initialVelocity,
                                              initialAngle) {    }
   ~HubbleRight() { }

   virtual list<Orbital*> getParts()     const { return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const
   {
      ogstream.drawHubbleRight(*this->pos, this->angle->getRadians());
   };
};
