/***********************************************************************
 * Header File:
 *    TEST ORBITAL
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Unit tests for the Orbital class.
 ************************************************************************/

#pragma once
#define _USE_MATH_DEFINES
#include "unitTest.h"
#include "orbital.h"


/*********************************************
* TEST ORBITAL
* Unit tests for orbital
*********************************************/
class TestOrbital : public UnitTest
{
public:
   void run()
   {
      constructor_nonDefault();
      getCurrentHeight_noHeight();
      getCurrentHeight_earthSurfaceX();
      getCurrentHeight_earthSurfaceY();
      getCurrentHeight_inSpaceX();
      getCurrentHeight_inSpaceY();
      getCurrentHeight_inSpaceXY();
      getGravityDirection_Top();
      getGravityDirection_Middle();
      getGravityDirection_Right();
      
      report("Orbital");
   }

private:

   /*****************************************************************
   *****************************************************************
   * CONSTRUCTOR
   *****************************************************************
   *****************************************************************/

   /*********************************************
    * name:    NON-DEFAULT CONSTRUCTOR
    * input:   Pos(11.1, 22.2), Vel(9.9, 8.8), Angle(0.0), 
    *          radius 10.0, fragmentCount 5
    * output:  Pos(11.1, 22.2), Vel(9.9, 8.8), Angle(0.0), 
    *          radius 10.0, fragmentCount 5
    *********************************************/
   void constructor_nonDefault()
   {  // setup
      Position initialPosition;
      initialPosition.x = 11.1;
      initialPosition.y = 22.2;
      Velocity initialVelocity;
      initialVelocity.dx = 9.9;
      initialVelocity.dy = 8.8;
      Angle initialAngle;
      initialAngle.radians = 0.0;
      double radius = 10.0;
      int fragmentCount = 5;

      // exercise
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);

      // verify
      assertEquals(orbital.pos.x, 11.1);
      assertEquals(orbital.pos.y, 22.2);
      assertEquals(orbital.vel.dx, 9.9);
      assertEquals(orbital.vel.dy, 8.8);
      assertEquals(orbital.angle.radians, 0.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 5);
      assertEquals(orbital.hasCrashed, false);
   }  // teardown

   /*****************************************************************
   *****************************************************************
   * PRIVATE METHODS
   *****************************************************************
   *****************************************************************/

   /*********************************************
    * name:    GETCURRENTHEIGHT NOHEIGHT (CENTER OF EARTH)
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = -6378000.0 (Under earth's surface)
    *********************************************/
   void getCurrentHeight_noHeight()
   {
      // setup
      StubPosition00 initialPosition;
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, -6378000.0);
   }

   /*********************************************
    * name:    GETCURRENTHEIGHT EARTH SURFACE X
    * input:   Pos(6378000.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = 0.0 (At sea level on earth's surface)
    *********************************************/
   void getCurrentHeight_earthSurfaceX()
   {
      // setup
      StubPositionX6378000Y0 initialPosition;
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 0.0);
   }

   /*********************************************
    * name:    GETCURRENTHEIGHT EARTH SURFACE Y
    * input:   Pos(0.0, 6378000.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = 0.0 (At sea level on earth's surface)
    *********************************************/
   void getCurrentHeight_earthSurfaceY()
   {
      // setup
      StubPositionX0Y6378000 initialPosition;
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 0.0);
   }

   /*********************************************
    * name:    GETCURRENTHEIGHT IN SPACE X
    * input:   Pos(6378010.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = 10.0 (10 meters over the earth)
    *********************************************/
   void getCurrentHeight_inSpaceX()
   {
      // setup
      StubPositionX6378010Y0 initialPosition;
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 10.0);
   }

   /*********************************************
    * name:    GETCURRENTHEIGHT IN SPACE Y
    * input:   Pos(0.0, 6378010.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = 10.0 (10 meters over the earth)
    *********************************************/
   void getCurrentHeight_inSpaceY()
   {
      // setup
      StubPositionX0Y6378010 initialPosition;
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 10.0);
   }

   /*********************************************
    * name:    GETCURRENTHEIGHT IN SPACE XY
    * input:   Pos(6378010.0, 6378010.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = 2641868.2430 (meters over the earth)
    *********************************************/
   void getCurrentHeight_inSpaceXY()
   {
      // setup
      StubPositionX6378010Y6378010 initialPosition;
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 2641868.2430);
   }

   /*********************************************
    * name:    getGravityDirection_Middle
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravity direction = 0.0
    *********************************************/
   void getGravityDirection_Middle()
   {
      // setup
      StubPosition00 initialPosition;
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double gravityDirection = 999.9;

      //exercise
      gravityDirection = orbital.getGravityDirection();
      // verify
      assertEquals(gravityDirection, 0.0);
   }
   
   /*********************************************
    * name:    getGravityDirection_Top
    * input:   Pos(0.0, 6378000.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravity direction = M_PI
    *********************************************/
   void getGravityDirection_Top()
   {
      // setup
      StubPositionX0Y6378000 initialPosition;
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double gravityDirection = 999.9;

      //exercise
      gravityDirection = orbital.getGravityDirection();
      // verify
      assertEquals(gravityDirection, M_PI);
   }
   
   /*********************************************
    * name:    getGravityDirection_Right
    * input:   Pos(6378000.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravity direction = PI/2
    *********************************************/
   void getGravityDirection_Right()
   {
      // setup
      StubPositionX6378000Y0 initialPosition;
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double gravityDirection = 999.9;

      //exercise
      gravityDirection = orbital.getGravityDirection();
      // verify
      assertEquals(gravityDirection, -M_PI_2);
   }
   
   /*****************************************************************
   *****************************************************************
   * PUBLIC METHODS
   *****************************************************************
   *****************************************************************/

   /*********************************************
    * name:    UPDATE NO VELOCITY
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  Pos(0.0, 0.0), Vel(0.0, 0.0) Didn't move
    *********************************************/
   void update_noVelocity()
   {
      // setup
      Position initialPosition;
      initialPosition.x = 0.0;
      initialPosition.y = 0.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      Angle initialAngle;
      initialAngle.radians = 0.0;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);

      // exercise
      orbital.update();

      // verify
      assertEquals(orbital.pos.x, 0.0);
      assertEquals(orbital.pos.y, 0.0);
      assertEquals(orbital.vel.dx, 0.0);
      assertEquals(orbital.vel.dy, 0.0);
      assertEquals(orbital.angle.radians, 0.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 0);
      assertEquals(orbital.hasCrashed, false);
   }  // teardown
};
