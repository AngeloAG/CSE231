/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 *    Jacob Mower
 *    Alberto Angelo Arellano Gaona
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159
#include <cassert>

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestOrbital;

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestOrbital;

   // Constructors
   //Default constructor 
   Angle() : radians(0.0) { }

   //Copy constructor creates a copy of the given angle
   Angle(const Angle& rhs) : radians(rhs.radians) { }

   // Cosntructor to explicitly set the angle from degrees
   Angle(double degrees) : radians(0.0)
   {
      setDegrees(degrees);
   }

   // Getters
   /*********************************************
    * name:    Get Degrees
    * Returns The current angle in degrees 0 to 360.
    * input:   Nothing.
    * output:  The current angle in degrees from 0 to 360.
    *********************************************/
   double getDegrees() const
   {
      return convertToDegrees(radians);
   }

   /*********************************************
    * name:    Get Radians
    * Returns The current angle in radians 0 to 2pi
    * input:   Nothing.
    * output:  The current angle in radians 0 to 2pi
    *********************************************/
   double getRadians() const
   {
      return radians;
   }

   // Setters
   /*********************************************
    * name:    Set Degrees
    * Changes the current radians angle to a given degree.
    *          Converts them to radians and normalizes
    *          them (Keeps them from 0 to 2pi).
    * input:   The angle expressed in degrees
    * output:  Nothing.
    *********************************************/
   void setDegrees(double degrees)
   {
      radians = normalize(convertToRadians(degrees));
   }

   /*********************************************
    * name:    Set Radians
    * Changes the current radians angle to the given radians
    *          and normalizes them (Keeps them from 0 to 2pi)
    * input:   The angle expressed in radians
    * output:  Nothing.
    *********************************************/
   void setRadians(double radians)
   {
      this->radians = normalize(radians);
   }

   /*********************************************
    * name:    Set Up
    * Changes the current radians angle 0 (Up)
    * input:   nothing
    * output:  nothing.
    *********************************************/
   void setUp()
   {
      setRadians(0.0);
   }

   /*********************************************
    * name:    Set Down
    * Changes the current radians angle to PI (Down)
    * input:   Nothing.
    * output:  Nothing.
    *********************************************/
   void setDown()
   {
      setRadians(M_PI);
   }

   /*********************************************
    * name:    Set Right
    * Changes the current radians angle to half PI (Right)
    * input:   Nothing.
    * output:  Nothing.
    *********************************************/
   void setRight()
   {
      setRadians(M_PI_2);
   }

   /*********************************************
    * name:    Set Left
    * Changes the current radians angle to PI and a half (Left)
    * input:   Nothing.
    * output:  Nothing.
    *********************************************/
   void setLeft()
   {
      setRadians(M_PI + M_PI_2);
   }

   /*********************************************
    * name:    Reverse
    * Changes the current radians angle to the oposite
    *          direction in a circle. i.e. (0 "UP" to PI "DOWN")
    * input:   Nothing.
    * output:  Nothing.
    *********************************************/
   void reverse()
   {
      setRadians(radians - M_PI);
   }

   /*********************************************
    * name:    Add
    * Adds the given amount of radians to the current
    *          angle.
    * input:   delta (the radians to add).
    * output:  Nothing.
    *********************************************/
   Angle& add(double delta) { setRadians(radians + delta); return *this; }

private:
   /*********************************************
    * name:    Normalize
    * Changes the radians value passed to it to be
    *          within the range of 0 to 2PI.
    * input:   radians (the radians to normalize)
    * output:  The normilized radians.
    *********************************************/
   double normalize(double radians) const;

   /*********************************************
    * name:    Convert to Radians
    * Changes the degrees passed to it into radians.
    * input:   The angle in degrees.
    * output:  The angle in radians.
    *********************************************/
   double convertToRadians(double degrees) const
   {
      return (degrees * (2.0 * M_PI) / 360.0);
   }

   /*********************************************
    * name:    Convert to Degrees
    * Changes the radians passed to it into degrees.
    * input:   The angle in radians.
    * output:  The angle in degrees.
    *********************************************/
   double convertToDegrees(double radians) const
   {
      return radians * 360.0 / (2.0 * M_PI);
   }

   double radians;   // 360 degrees equals 2 PI radians
};

class DummyAngle : public Angle
{
public:
   DummyAngle(): Angle() {}
   
   double getDegrees() const { assert(false); return 0.0;  }
   double getRadians() const { assert(false); return 0.0;  }
   
   void setDegrees(double degrees) { assert(false);        }
   void setRadians(double radians) { assert(false);        }
   void setUp()                    { assert(false);        }
   void setDown()                  { assert(false);        }
   void setRight()                 { assert(false);        }
   void setLeft()                  { assert(false);        }
   void reverse()                  { assert(false);        }
   Angle& add(double delta) { assert(false); return *this; }
};
 
