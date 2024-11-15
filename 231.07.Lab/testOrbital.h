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
      getGravityDirection_Middle();
      getGravityDirection_Top();
      getGravityDirection_Bottom();
      getGravityDirection_Right();
      getGravityDirection_Left();
      getGravityFromHeight_SeaLevel();
      getGravityFromHeight_InSpace();
      
      getGravityAcceleration_earthSurfaceX();
      getGravityAcceleration_earthSurfaceY();
      getGravityAcceleration_spaceXY();

      move_Right();
      move_Up();
      move_RightAndUp();
      move_NoMovement();

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
      Position* initialPosition = new Position();
      initialPosition->x = 11.1;
      initialPosition->y = 22.2;
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
      assertEquals(orbital.pos->x, 11.1);
      assertEquals(orbital.pos->y, 22.2);
      assertEquals(orbital.vel.dx, 9.9);
      assertEquals(orbital.vel.dy, 8.8);
      assertEquals(orbital.angle.radians, 0.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 5);
      assertEquals(orbital.hasCrashed, false);
   }  

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
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, -6378000.0);
   }  // teardown

   /*********************************************
    * name:    GETCURRENTHEIGHT EARTH SURFACE X
    * input:   Pos(6378000.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = 0.0 (At sea level on earth's surface)
    *********************************************/
   void getCurrentHeight_earthSurfaceX()
   {
      // setup
      StubPositionX6378000Y0* initialPosition = new StubPositionX6378000Y0();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 0.0);
   }  // teardown

   /*********************************************
    * name:    GETCURRENTHEIGHT EARTH SURFACE Y
    * input:   Pos(0.0, 6378000.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = 0.0 (At sea level on earth's surface)
    *********************************************/
   void getCurrentHeight_earthSurfaceY()
   {
      // setup
      StubPositionX0Y6378000* initialPosition = new StubPositionX0Y6378000();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 0.0);
   }  // teardown

   /*********************************************
    * name:    GETCURRENTHEIGHT IN SPACE X
    * input:   Pos(6378010.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = 10.0 (10 meters over the earth)
    *********************************************/
   void getCurrentHeight_inSpaceX()
   {
      // setup
      StubPositionX6378010Y0* initialPosition = new StubPositionX6378010Y0();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 10.0);
   }  // teardown

   /*********************************************
    * name:    GETCURRENTHEIGHT IN SPACE Y
    * input:   Pos(0.0, 6378010.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = 10.0 (10 meters over the earth)
    *********************************************/
   void getCurrentHeight_inSpaceY()
   {
      // setup
      StubPositionX0Y6378010* initialPosition = new StubPositionX0Y6378010();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 10.0);
   }  // teardown

   /*********************************************
    * name:    GETCURRENTHEIGHT IN SPACE XY
    * input:   Pos(6378010.0, 6378010.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  currentHeight = 2641868.2430 (meters over the earth)
    *********************************************/
   void getCurrentHeight_inSpaceXY()
   {
      // setup
      StubPositionX6378010Y6378010* initialPosition = new StubPositionX6378010Y6378010();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 2641868.2430);
   }  // teardown

   /*********************************************
    * name:    getGravityDirection_Middle
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravity direction = 0.0
    *********************************************/
   void getGravityDirection_Middle()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double gravityDirection = 999.9;

      //exercise
      gravityDirection = orbital.getGravityDirection();
      // verify
      assertEquals(gravityDirection, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    getGravityDirection_Top
    * input:   Pos(0.0, 6378000.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravity direction = M_PI
    *********************************************/
   void getGravityDirection_Top()
   {
      // setup
      StubPositionX0Y6378000* initialPosition = new StubPositionX0Y6378000();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double gravityDirection = 999.9;

      //exercise
      gravityDirection = orbital.getGravityDirection();
      // verify
      assertEquals(gravityDirection, M_PI);
   }  // teardown

   /*********************************************
    * name:    getGravityDirection_Bottom
    * input:   Pos(0.0, -6378000.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravity direction = 0.0
    *********************************************/
   void getGravityDirection_Bottom()
   {
      // setup
      StubPositionX0YMINUS6378000* initialPosition =
                                   new StubPositionX0YMINUS6378000();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double gravityDirection = 999.9;

      //exercise
      gravityDirection = orbital.getGravityDirection();
      // verify
      assertEquals(gravityDirection, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    getGravityDirection_Right
    * input:   Pos(6378000.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravity direction = PI/2
    *********************************************/
   void getGravityDirection_Right()
   {
      // setup
      StubPositionX6378000Y0* initialPosition = new StubPositionX6378000Y0();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double gravityDirection = 999.9;

      //exercise
      gravityDirection = orbital.getGravityDirection();
      // verify
      assertEquals(gravityDirection, -M_PI_2);
   }  // teardown

   /*********************************************
    * name:    getGravityDirection_Left
    * input:   Pos(-6378000.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravity direction = PI + PI/2
    *********************************************/
   void getGravityDirection_Left()
   {
      // setup
      StubPositionXMINUS6378000Y0* initialPosition =
                                   new StubPositionXMINUS6378000Y0();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      double gravityDirection = 999.9;

      //exercise
      gravityDirection = orbital.getGravityDirection();
      // verify
      assertEquals(gravityDirection, M_PI_2);
   }  // teardown

   /*********************************************
    * name:    GET GRAVITY ACCELERATION EARTH SURFACE X
    * input:   Pos(6378000.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravityAcceleration ddx=-9.8066 ddy=0.0 (At sea level on earth's surface)
    *********************************************/
   void getGravityAcceleration_earthSurfaceX()
   {
      // setup
      StubPositionX6378000Y0* initialPosition = new StubPositionX6378000Y0();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      Acceleration gravityAcceleration;
      gravityAcceleration.ddx = 999.9;
      gravityAcceleration.ddy = 888.8;

      //exercise
      gravityAcceleration = orbital.getGravityAcceleration();
      // verify
      assertEquals(gravityAcceleration.ddx, -9.8066);
      assertEquals(gravityAcceleration.ddy, 0.0);
   }

   /*********************************************
    * name:    GET GRAVITY ACCELERATION EARTH SURFACE Y
    * input:   Pos(0.0, 6378000.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravityAcceleration ddx=0.0 ddy=-9.8066 (At sea level on earth's surface)
    *********************************************/
   void getGravityAcceleration_earthSurfaceY()
   {
      // setup
      StubPositionX0Y6378000* initialPosition = new StubPositionX0Y6378000();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      Acceleration gravityAcceleration;
      gravityAcceleration.ddx = 999.9;
      gravityAcceleration.ddy = 888.8;

      //exercise
      gravityAcceleration = orbital.getGravityAcceleration();
      // verify
      assertEquals(gravityAcceleration.ddy, -9.8066);
      assertEquals(gravityAcceleration.ddx, 0.0);
   }  // teardown

   /*********************************************
    * name:    GET GRAVITY ACCELERATION SPACE XY
    * input:   Pos(6378000.0, 6378000.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  gravityAcceleration ddx=-3.4671 ddy-3.4671 (way up in space)
    *********************************************/
   void getGravityAcceleration_spaceXY()
   {
      // setup
      StubPositionX6378010Y6378010* initialPosition =
                                    new StubPositionX6378010Y6378010();
      DummyVelocity initialVelocity;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      Acceleration gravityAcceleration;
      gravityAcceleration.ddx = 999.9;
      gravityAcceleration.ddy = 888.8;

      //exercise
      gravityAcceleration = orbital.getGravityAcceleration();
      // verify
      assertEquals(gravityAcceleration.ddx, -3.4671);
      assertEquals(gravityAcceleration.ddy, -3.4671);
   }  // teardown

   /*****************************************************************
   *****************************************************************
   * INLINE FUNCTIONS
   *****************************************************************
   *****************************************************************/

   /*********************************************
    * name:    GET GRAVITY FROM HEIGHT AT SEA LEVEL
    * input:   height = 0.0
    * output:  gravity = 9.8066
    *********************************************/
   void getGravityFromHeight_SeaLevel()
   {
      // setup
      double height  = 0.0;
      double gravity = 999.9;

      //exercise
      gravity = getGravityFromHeight(height);
      // verify
      assertEquals(height, 0.0);
      assertEquals(gravity, 9.8066);
   }  // teardown

   /*********************************************
    * name:    GET GRAVITY FROM HEIGHT IN SPACE
    * input:   height = 1000000.0
    * output:  gravity = 7.3284
    *********************************************/
   void getGravityFromHeight_InSpace()
   {
      // setup
      double height  = 1000000.0;
      double gravity = 999.9;

      //exercise
      gravity = getGravityFromHeight(height);
      // verify
      assertEquals(height, 1000000.0);
      assertEquals(gravity, 7.3284);
   }  // teardown
   
   /*****************************************************************
   *****************************************************************
   * PUBLIC METHODS
   *****************************************************************
   *****************************************************************/

   /*********************************************
    * name:    MOVE TO THE RIGHT
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  Pos(1.5, 0.0), Vel(30.0, 0.0) Moved to the right
    *********************************************/
   void move_Right()
   {
      // setup
      Position* initialPosition = new Position();
      initialPosition->x = 0.0;
      initialPosition->y = 0.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);

      Acceleration acc;
      acc.ddx = 900.0;
      acc.ddy = 0.0;

      // exercise
      orbital.move(acc, 0.033333333);

      // verify
      assertEquals(orbital.pos->x, 1.5);
      assertEquals(orbital.pos->y, 0.0);
      assertEquals(orbital.vel.dx, 30.0);
      assertEquals(orbital.vel.dy, 0.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 0);
      assertEquals(orbital.hasCrashed, false);
   }  // teardown

   /*********************************************
    * name:    MOVE UP
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  Pos(0.0, 1.5), Vel(0.0, 30.0) Moved up
    *********************************************/
   void move_Up()
   {
      // setup
      Position* initialPosition = new Position();
      initialPosition->x = 0.0;
      initialPosition->y = 0.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);

      Acceleration acc;
      acc.ddx = 0.0;
      acc.ddy = 900.0;

      // exercise
      orbital.move(acc, 0.033333333);

      // verify
      assertEquals(orbital.pos->x, 0.0);
      assertEquals(orbital.pos->y, 1.5);
      assertEquals(orbital.vel.dx, 0.0);
      assertEquals(orbital.vel.dy, 30.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 0);
      assertEquals(orbital.hasCrashed, false);
   }  // teardown

   /*********************************************
    * name:    MOVE UP AND RIGHT
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  Pos(1.5, 0.0), Vel(30.0, 0.0) Moved to the right
    *********************************************/
   void move_RightAndUp()
   {
      // setup
      Position* initialPosition = new Position();
      initialPosition->x = 0.0;
      initialPosition->y = 0.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);

      Acceleration acc;
      acc.ddx = 900.0;
      acc.ddy = 900.0;

      // exercise
      orbital.move(acc, 0.033333333);

      // verify
      assertEquals(orbital.pos->x, 1.5);
      assertEquals(orbital.pos->y, 1.5);
      assertEquals(orbital.vel.dx, 30.0);
      assertEquals(orbital.vel.dy, 30.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 0);
      assertEquals(orbital.hasCrashed, false);
   }  // teardown

   /*********************************************
    * name:    MOVE NO WHERE
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    * output:  Pos(0.0, 0.0), Vel(0.0, 0.0) Not moved
    *********************************************/
   void move_NoMovement()
   {
      // setup
      Position* initialPosition = new Position();
      initialPosition->x = 0.0;
      initialPosition->y = 0.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);

      Acceleration acc;
      acc.ddx = 0.0;
      acc.ddy = 0.0;

      // exercise
      orbital.move(acc, 0.033333333);

      // verify
      assertEquals(orbital.pos->x, 0.0);
      assertEquals(orbital.pos->y, 0.0);
      assertEquals(orbital.vel.dx, 0.0);
      assertEquals(orbital.vel.dy, 0.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 0);
      assertEquals(orbital.hasCrashed, false);
   }  // teardown
};
