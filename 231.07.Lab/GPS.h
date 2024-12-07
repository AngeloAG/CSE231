/***********************************************************************
 * Header File:
 *    GPS
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    GPS class.
 ************************************************************************/

#pragma once
#include "orbital.h"
#include "acceleration.h"

class Orbital;
class TestGPS;

/*********************************************
* GPS
* A single instance of a GPS that orbits.
*********************************************/
class GPS : public Orbital
{
   friend TestGPS;
public:
   GPS(int gpsId);
   GPS(Position* initialPos, Velocity* initialVelocity, Angle* initialAngle);
   ~GPS() { }

   virtual list<Orbital*> getParts()     const;
   virtual void draw(ogstream& ogstream) const;
};


/*********************************************
* GPSCenter
* A single instance of a GPS that orbits.
*********************************************/
class GPSCenter : public Orbital
{
   friend TestGPS;
public:
   GPSCenter(int gpsId);
   GPSCenter(Position* initialPos, Velocity* initialVelocity,
             Angle* initialAngle) : Orbital(initialPos, 3, 7.0,
                                            initialVelocity,
                                            initialAngle) {    }
   ~GPSCenter() { }

   virtual list<Orbital*> getParts() const{ return list<Orbital*> ();}
   virtual void draw(ogstream& ogstream) const 
   {
      ogstream.drawGPSCenter(*this->pos, this->angle->getRadians());
   };
};


/*********************************************
* GPSRight
* A single instance of a GPS that orbits.
*********************************************/
class GPSRight : public Orbital
{
   friend TestGPS;
public:
   GPSRight(int gpsId);
   GPSRight(Position* initialPos, Velocity* initialVelocity,
            Angle* initialAngle) : Orbital(initialPos, 3, 8.0,
                                           initialVelocity,
                                           initialAngle) {    }
   ~GPSRight() { }

   virtual list<Orbital*> getParts()     const{ return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const 
   {
      ogstream.drawGPSRight(*this->pos, this->angle->getRadians());
   };
};

/*********************************************
* GPSLeft
* A single instance of a GPS that orbits.
*********************************************/
class GPSLeft : public Orbital
{
   friend TestGPS;
public:
   GPSLeft(int gpsId);
   GPSLeft(Position* initialPos, Velocity* initialVelocity,
           Angle* initialAngle) : Orbital(initialPos, 3, 8.0,
                                          initialVelocity,
                                          initialAngle) {    }
   ~GPSLeft() { }

   virtual list<Orbital*> getParts()     const{ return list<Orbital*> (); }
   virtual void draw(ogstream& ogstream) const 
   {
      ogstream.drawGPSLeft(*this->pos, this->angle->getRadians());
   };
};
