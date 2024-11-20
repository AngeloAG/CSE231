/***********************************************************************
 * Header File:
 *    ACCELERATION
 * Author:
 *    Br. Helfrich
 *    Jacob Mower
 *    Alberto Angelo Arellano Gaona
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once
#include <cassert>

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestOrbital;
class Angle;
class TestShip;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestOrbital;
   friend TestShip;

public:
   // constructors
   // Default values for constructors
   Acceleration() : ddx(0.0), ddy(0.0) {}

   // Constructor that uses values given
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) {}

   // For Ship thrust
   Acceleration(const Angle& angle, double speed) : ddx(0.0), ddy(0.0)
   {
      set(angle, speed);
   }

   // getters
   double getDDX()   const { return ddx; }
   double getDDY()   const { return ddy; }

   // setters
   void setDDX(double ddx) { this->ddx = ddx; }
   void setDDY(double ddy) { this->ddy = ddy; }
   void set(const Angle& a, double magnitude);

   void addDDX(double ddx) { this->ddx += ddx; }
   void addDDY(double ddy) { this->ddy += ddy; }
   void add(const Acceleration& rhs);

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};

class DummyAcceleration : public Acceleration
{
public:
   DummyAcceleration() : Acceleration() {}
   
   double getDDX()   const       { assert(false); return 0.0; }
   double getDDY()   const       { assert(false); return 0.0; }
   
   void setDDX(double ddx)       { assert(false);             }
   void setDDY(double ddy)       { assert(false);             }
   void set(const Angle& a, double magnitude){ assert(false); }
   void addDDX(double ddx)                   { assert(false); }
   void addDDY(double ddy)                   { assert(false); }
   void add(const Acceleration& rhs)         { assert(false); }
};
