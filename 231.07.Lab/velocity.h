/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 *    Jacob Mower
 *    Angelo Arellano Gaona
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

#include <cassert>

// for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestOrbital;
class TestShip;
class TestGPS;

// for add()
class Acceleration;
class Angle;

 /*********************************************
  * Velocity
  * I feel the need, the need for speed
  *********************************************/
class Velocity
{
   // for unit tests
   friend TestPosition;
   friend TestVelocity;
   friend TestOrbital;
   friend TestShip;
   friend TestGPS;

public:
   // constructors
   Velocity()                     : dx(0.0), dy(0.0) { }
   Velocity(double dx, double dy) : dx(dx), dy(dy)   { }

   // getters
   double getDX()       const { return dx; }
   double getDY()       const { return dy; }
   double getSpeed()    const;

   // setters
   void setDX(double dx) { this->dx = dx; }
   void setDY(double dy) { this->dy = dy; }
   void set(const Angle & angle, double magnitude);

   void addDX(double dx) { this->dx += dx; }
   void addDY(double dy) { this->dy += dy; }
   void add(const Acceleration & acceleration, double time);

private:
   double dx;           // horizontal velocity
   double dy;           // vertical velocity
};

class DummyVelocity : public Velocity
{
public:
   DummyVelocity(): Velocity() {}
   // getters
   double getDX()    const { assert(false); return 0.0; }
   double getDY()    const { assert(false); return 0.0; }
   double getSpeed() const { assert(false); return 0.0; }

   // setters
   void setDX(double dx) { assert(false); }
   void setDY(double dy) { assert(false); }
   void set(const Angle& angle, double magnitude) { assert(false); }
   void addDX(double dx) { assert(false); }
   void addDY(double dy) { assert(false); }
   void add(const Acceleration& acceleration, double time) { assert(false); }
};

class FakeVelocityDX0DY0 : public DummyVelocity
{
public:
   FakeVelocityDX0DY0(): DummyVelocity() {}
   
   double getDX() const { return 0.0;}
   double getDY() const { return 0.0;}
};
