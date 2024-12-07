/***********************************************************************
 * Header File:
 *    Point : The representation of a position 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 ************************************************************************/

#pragma once

#include <iostream> 
#include <cmath>
#include <cassert>

class TestPosition;
class TestOrbital;
class Acceleration;
class Velocity;
class TestEntity;
class TestShip;
class TestGPS;
class TestHubble;
class TestSputnik;
class TestStarlink;
class TestCrewDragon;

/*********************************************
 * Position
 * A single position on the field in Meters  
 *********************************************/
class Position
{
public:
   friend TestPosition;
   friend TestEntity;
   friend TestOrbital;
   friend TestShip;
   friend TestGPS;
   friend TestHubble;
   friend TestSputnik;
   friend TestStarlink;
   friend TestCrewDragon;
   
   // constructors
   Position() : x(0.0), y(0.0)  { }
   Position(double x, double y);
   Position(const Position & pt) : x(pt.x), y(pt.y) { }
   Position& operator = (const Position& pt);

   // getters
   virtual double getMetersX() const { return x;                    }
   virtual double getMetersY() const { return y;                    }
   virtual double getPixelsX() const { return x / metersFromPixels; }
   virtual double getPixelsY() const { return y / metersFromPixels; }

   // setters
   void setMeters(double xMeters, double yMeters) { x = xMeters; y = yMeters; }
   void setMetersX(double xMeters)  { x = xMeters;                            }
   void setMetersY(double yMeters)  { y = yMeters;                            }
   void setPixelsX(double xPixels)  { x = xPixels * metersFromPixels;         }
   void setPixelsY(double yPixels)  { y = yPixels * metersFromPixels;         }
   void addMetersX(double dxMeters) { setMetersX(getMetersX() + dxMeters);    }
   void addMetersY(double dyMeters) { setMetersY(getMetersY() + dyMeters);    }
   void addPixelsX(double dxPixels) { setPixelsX(getPixelsX() + dxPixels);    }
   void addPixelsY(double dyPixels) { setPixelsY(getPixelsY() + dyPixels);    }
   void add(const Acceleration& a, const Velocity& v, double t);

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   double getZoom() const { return metersFromPixels; }

private:
   double x; // horizontal position
   double y; // vertical position
   static double metersFromPixels;
};

/*********************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *********************************************/
inline double computeDistance(const Position& pos1, const Position& pos2)
{
   return sqrt((pos1.getMetersX() - pos2.getMetersX()) *
               (pos1.getMetersX() - pos2.getMetersX()) +
               (pos1.getMetersY() - pos2.getMetersY()) *
               (pos1.getMetersY() - pos2.getMetersY()));
}

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in,        Position& pt);

/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};

class DummyPosition : public Position
{
public:
   DummyPosition() : Position() { };
   virtual double getMetersX() const { assert(false); return 0.0; }
   virtual double getMetersY() const { assert(false); return 0.0; }
   double getPixelsX()         const { assert(false); return 0.0; }
   double getPixelsY()         const { assert(false); return 0.0; }

   // setters
   void setMeters(double xMeters, double yMeters) { assert(false); }
   void setMetersX(double xMeters)                { assert(false); }
   void setMetersY(double yMeters)                { assert(false); }
   void setPixelsX(double xPixels)                { assert(false); }
   void setPixelsY(double yPixels)                { assert(false); }
   void addMetersX(double dxMeters)               { assert(false); }
   void addMetersY(double dyMeters)               { assert(false); }
   void addPixelsX(double dxPixels)               { assert(false); }
   void addPixelsY(double dyPixels)               { assert(false); }
   void add(const Acceleration& a, const Velocity& v,
            double t)                             { assert(false); }
};

/*******************************************************************************
********************************************************************************
** STUBS FOR TESTING
********************************************************************************
*******************************************************************************/
class StubPosition00 : public DummyPosition
{
public:
   StubPosition00() : DummyPosition() {             };
   virtual double getMetersX()  const { return 0.0; }
   virtual double getMetersY()  const { return 0.0; }
   virtual double getPixelsX()  const { return 0.0; }
   virtual double getPixelsY()  const { return 0.0; }
};

class StubPositionX6378000Y0 : public DummyPosition
{
public:
   StubPositionX6378000Y0() : DummyPosition() {          };
   virtual double getMetersX() const { return 6378000.0; }
   virtual double getMetersY() const { return 0.0;       }
};

class StubPositionXMINUS6378000Y0 : public DummyPosition
{
public:
   StubPositionXMINUS6378000Y0() : DummyPosition() {      };
   virtual double getMetersX() const { return -6378000.0; }
   virtual double getMetersY() const { return 0.0;        }
};

class StubPositionX0Y6378000 : public DummyPosition
{
public:
   StubPositionX0Y6378000() : DummyPosition() {          };
   virtual double getMetersX() const { return 0.0;       }
   virtual double getMetersY() const { return 6378000.0; }
};

class StubPositionX0YMINUS6378000 : public DummyPosition
{
public:
   StubPositionX0YMINUS6378000() : DummyPosition() {      };
   virtual double getMetersX() const { return 0.0;        }
   virtual double getMetersY() const { return -6378000.0; }
};

class StubPositionX6378010Y6378010 : public DummyPosition
{
public:
   StubPositionX6378010Y6378010() : DummyPosition() {    };
   virtual double getMetersX() const { return 6378010.0; }
   virtual double getMetersY() const { return 6378010.0; }
};

class StubPositionX6378010Y0 : public DummyPosition
{
public:
   StubPositionX6378010Y0() : DummyPosition() {          };
   virtual double getMetersX() const { return 6378010.0; }
   virtual double getMetersY() const { return 0.0;       }
};

class StubPositionX0Y6378010 : public DummyPosition
{
public:
   StubPositionX0Y6378010() : DummyPosition() {          };
   virtual double getMetersX() const { return 0.0;       }
   virtual double getMetersY() const { return 6378010.0; }
};
