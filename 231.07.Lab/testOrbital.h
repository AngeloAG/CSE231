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

#include <ranges>

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

      detectCollision_BarelyTouchingHorizontal();
      detectCollision_BarelyTouchingVertical();
      detectCollision_BarelyTouchingDiagonal();
      detectCollision_NoTouchingHorizontal();
      detectCollision_OnTopOfEachOther();

      destroy_None();
      destroy_One();
      destroy_Many();
      destroy_ManyPartsAndFragments();
      destroy_ManyFragmentsNoParts();
      
      getFragments_1();
      getFragments_0();
      getFragments_4();
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
      Velocity* initialVelocity = new Velocity();
      initialVelocity->dx = 9.9;
      initialVelocity->dy = 8.8;
      Angle* initialAngle = new Angle();
      initialAngle->radians = 0.0;
      double radius     = 10.0;
      int fragmentCount = 5;

      // exercise
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);

      // verify
      assertEquals(orbital.pos->x, 11.1);
      assertEquals(orbital.pos->y, 22.2);
      assertEquals(orbital.vel->dx, 9.9);
      assertEquals(orbital.vel->dy, 8.8);
      assertEquals(orbital.angle->radians, 0.0);
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
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity          = new DummyVelocity();
      DummyAngle* initialAngle                = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity          = new DummyVelocity();
      DummyAngle* initialAngle                = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity          = new DummyVelocity();
      DummyAngle* initialAngle                = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity          = new DummyVelocity();
      DummyAngle* initialAngle                = new DummyAngle();
      double radius     = 10.0;
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
      StubPositionX6378010Y6378010* initialPosition =
                                       new StubPositionX6378010Y6378010();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle       = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle       = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle       = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle       = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle       = new DummyAngle();
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
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle       = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle       = new DummyAngle();
      double radius     = 10.0;
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
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle       = new DummyAngle();
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
    *          Acc(2.0, 0.0) time=1
    * output:  Pos(2.0, 0.0), Vel(2.0, 0.0) Moved to the right
    *********************************************/
   void move_Right()
   {
      // setup
      Position* initialPosition = new Position();
      initialPosition->x = 0.0;
      initialPosition->y = 0.0;
      Velocity* initialVelocity = new Velocity();
      initialVelocity->dx = 0.0;
      initialVelocity->dy = 0.0;
      DummyAngle* initialAngle = new DummyAngle();
      double radius     = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      Acceleration acc;
      acc.ddx = 2.0;
      acc.ddy = 0.0;

      // exercise
      orbital.move(acc, 1.0);

      // verify
      assertEquals(orbital.pos->x, 2.0);
      assertEquals(orbital.pos->y, 0.0);
      assertEquals(orbital.vel->dx, 2.0);
      assertEquals(orbital.vel->dy, 0.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 0);
      assertEquals(orbital.hasCrashed, false);
   }  // teardown

   /*********************************************
    * name:    MOVE UP
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    *          Acc(0.0, 2.0) time=1
    * output:  Pos(0.0, 2.0), Vel(0.0, 2.0) Moved up
    *********************************************/
   void move_Up()
   {
      // setup
      Position* initialPosition = new Position();
      initialPosition->x = 0.0;
      initialPosition->y = 0.0;
      Velocity* initialVelocity = new Velocity();
      initialVelocity->dx = 0.0;
      initialVelocity->dy = 0.0;
      DummyAngle* initialAngle = new DummyAngle();
      double radius     = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      Acceleration acc;
      acc.ddx = 0.0;
      acc.ddy = 2.0;

      // exercise
      orbital.move(acc, 1.0);

      // verify
      assertEquals(orbital.pos->x, 0.0);
      assertEquals(orbital.pos->y, 2.0);
      assertEquals(orbital.vel->dx, 0.0);
      assertEquals(orbital.vel->dy, 2.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 0);
      assertEquals(orbital.hasCrashed, false);
   }  // teardown

   /*********************************************
    * name:    MOVE UP AND RIGHT
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    *          Acc(2.0, 2.0) time=1
    * output:  Pos(2.0, 2.0), Vel(2.0, 2.0) Moved to the right
    *********************************************/
   void move_RightAndUp()
   {
      // setup
      Position* initialPosition = new Position();
      initialPosition->x = 0.0;
      initialPosition->y = 0.0;
      Velocity* initialVelocity = new Velocity();
      initialVelocity->dx = 0.0;
      initialVelocity->dy = 0.0;
      DummyAngle* initialAngle = new DummyAngle();
      double radius     = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      Acceleration acc;
      acc.ddx = 2.0;
      acc.ddy = 2.0;

      // exercise
      orbital.move(acc, 1);

      // verify
      assertEquals(orbital.pos->x, 2.0);
      assertEquals(orbital.pos->y, 2.0);
      assertEquals(orbital.vel->dx, 2.0);
      assertEquals(orbital.vel->dy, 2.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 0);
      assertEquals(orbital.hasCrashed, false);
   }  // teardown

   /*********************************************
    * name:    MOVE NO WHERE
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    *          Acc(0.0, 0.0) time=1
    * output:  Pos(0.0, 0.0), Vel(0.0, 0.0) Not moved
    *********************************************/
   void move_NoMovement()
   {
      // setup
      Position* initialPosition = new Position();
      initialPosition->x = 0.0;
      initialPosition->y = 0.0;
      Velocity* initialVelocity = new Velocity();
      initialVelocity->dx = 0.0;
      initialVelocity->dy = 0.0;
      DummyAngle* initialAngle = new DummyAngle();
      double radius     = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      Acceleration acc;
      acc.ddx = 0.0;
      acc.ddy = 0.0;

      // exercise
      orbital.move(acc, 1.0);

      // verify
      assertEquals(orbital.pos->x, 0.0);
      assertEquals(orbital.pos->y, 0.0);
      assertEquals(orbital.vel->dx, 0.0);
      assertEquals(orbital.vel->dy, 0.0);
      assertEquals(orbital.radius, 10.0);
      assertEquals(orbital.fragmentCount, 0);
      assertEquals(orbital.hasCrashed, false);
   }  // teardown

   /*********************************************
    * name:    DETECT COLLISION BARELY TOUCHING HORIZONTAL
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0),
    *          radius1 3189000.0, fragmentCount1 0
    *          Pos2(6378000.0, 0.0), Vel2(0.0, 0.0), Angle2(0.0),
    *          radius2 3189000.0, fragmentCount2 0
    * output:  orbital1 hasCrashed = true; orbital2 hasCrashed = false;
    *********************************************/
   void detectCollision_BarelyTouchingHorizontal()
   {
      // setup
      StubPosition00* initialPosition1 = new StubPosition00();
      DummyVelocity* initialVelocity1  = new DummyVelocity();
      DummyAngle* initialAngle1        = new DummyAngle();
      double radius1 = 3189000.0;
      int fragmentCount1 = 0;
      DummyOrbital* orbital1 = new DummyOrbital(initialPosition1, fragmentCount1,
                                                radius1, initialVelocity1,
                                                initialAngle1);
      orbital1->hasCrashed = false;

      StubPositionX6378000Y0* initialPosition2 = new StubPositionX6378000Y0();
      DummyVelocity* initialVelocity2 = new DummyVelocity();
      DummyAngle* initialAngle2       = new DummyAngle();
      double radius2 = 3189000.0;
      int fragmentCount2 = 0;
      DummyOrbital* orbital2 = new DummyOrbital(initialPosition2, fragmentCount2,
                                                radius2, initialVelocity2,
                                                initialAngle2);
      orbital2->hasCrashed = false;

      list<Orbital*> orbitals;
      orbitals.push_back(orbital1);
      orbitals.push_back(orbital2);

      // exercise
      orbital1->detectCollisions(orbitals);

      // verify
      assertEquals(orbital1->hasCrashed, true);
      assertEquals(orbital2->hasCrashed, false);
   }  // teardown

   /*********************************************
    * name:    DETECT COLLISION BARELY TOUCHING VERTICAL
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0),
    *          radius1 3189000.0, fragmentCount1 0
    *          Pos2(0.0, 6378000.0), Vel2(0.0, 0.0), Angle2(0.0),
    *          radius2 3189000.0, fragmentCount2 0
    * output:  orbital1 hasCrashed = true; orbital2 hasCrashed = false;
    *********************************************/
   void detectCollision_BarelyTouchingVertical()
   {
      // setup
      StubPosition00* initialPosition1 = new StubPosition00();
      DummyVelocity* initialVelocity1  = new DummyVelocity();
      DummyAngle* initialAngle1        = new DummyAngle();
      double radius1 = 3189000.0;
      int fragmentCount1 = 0;
      DummyOrbital* orbital1 = new DummyOrbital(initialPosition1, fragmentCount1,
                                                radius1, initialVelocity1,
                                                initialAngle1);
      orbital1->hasCrashed = false;

      StubPositionX0Y6378000* initialPosition2 = new StubPositionX0Y6378000();
      DummyVelocity* initialVelocity2          = new DummyVelocity();
      DummyAngle* initialAngle2                = new DummyAngle();
      double radius2 = 3189000.0;
      int fragmentCount2 = 0;
      DummyOrbital* orbital2 = new DummyOrbital(initialPosition2, fragmentCount2,
                                                radius2, initialVelocity2,
                                                initialAngle2);
      orbital2->hasCrashed = false;

      list<Orbital*> orbitals;
      orbitals.push_back(orbital1);
      orbitals.push_back(orbital2);

      // exercise
      orbital1->detectCollisions(orbitals);

      // verify
      assertEquals(orbital1->hasCrashed, true);
      assertEquals(orbital2->hasCrashed, false);
   }  // teardown

   /*********************************************
    * name:    DETECT COLLISION BARELY TOUCHING DIAGONAL
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0),
    *          radius1 4509935.0, fragmentCount1 0
    *          Pos2(6378010.0, 6378010.0), Vel2(0.0, 0.0), Angle2(0.0),
    *          radius2 4509935.0, fragmentCount2 0
    * output:  orbital1 hasCrashed = true; orbital2 hasCrashed = false;
    *********************************************/
   void detectCollision_BarelyTouchingDiagonal()
   {
      // setup
      StubPosition00* initialPosition1 = new StubPosition00();
      DummyVelocity* initialVelocity1  = new DummyVelocity();
      DummyAngle* initialAngle1        = new DummyAngle();
      double radius1     = 4509935.0;
      int fragmentCount1 = 0;
      DummyOrbital* orbital1 = new DummyOrbital(initialPosition1, fragmentCount1,
                                                radius1, initialVelocity1,
                                                initialAngle1);
      orbital1->hasCrashed = false;

      StubPositionX6378010Y6378010* initialPosition2 =
                                        new StubPositionX6378010Y6378010();
      DummyVelocity* initialVelocity2 = new DummyVelocity();
      DummyAngle* initialAngle2       = new DummyAngle();
      double radius2 = 4509935.0;
      int fragmentCount2 = 0;
      DummyOrbital* orbital2 = new DummyOrbital(initialPosition2, fragmentCount2,
                                                radius2, initialVelocity2,
                                                initialAngle2);
      orbital2->hasCrashed = false;

      list<Orbital*> orbitals;
      orbitals.push_back(orbital1);
      orbitals.push_back(orbital2);

      // exercise
      orbital1->detectCollisions(orbitals);

      // verify
      assertEquals(orbital1->hasCrashed, true);
      assertEquals(orbital2->hasCrashed, false);
   }  // teardown

   /*********************************************
    * name:    DETECT COLLISION NO TOUCHING HORIZONTAL
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0),
    *          radius1 10.0, fragmentCount1 0
    *          Pos2(6378000.0, 0.0), Vel2(0.0, 0.0), Angle2(0.0),
    *          radius2 10.0, fragmentCount2 0
    * output:  orbital1 hasCrashed = false; orbital2 hasCrashed = false;
    *********************************************/
   void detectCollision_NoTouchingHorizontal()
   {
      // setup
      StubPosition00* initialPosition1 = new StubPosition00();
      DummyVelocity* initialVelocity1  = new DummyVelocity();
      DummyAngle* initialAngle1        = new DummyAngle();
      double radius1 = 10.0;
      int fragmentCount1 = 0;
      DummyOrbital* orbital1 = new DummyOrbital(initialPosition1, fragmentCount1,
                                                radius1, initialVelocity1,
                                                initialAngle1);
      orbital1->hasCrashed = false;

      StubPositionX6378000Y0* initialPosition2 = new StubPositionX6378000Y0();
      DummyVelocity* initialVelocity2          = new DummyVelocity();
      DummyAngle* initialAngle2                = new DummyAngle();
      double radius2 = 10.0;
      int fragmentCount2 = 0;
      DummyOrbital* orbital2 = new DummyOrbital(initialPosition2, fragmentCount2,
                                                radius2, initialVelocity2,
                                                initialAngle2);
      orbital2->hasCrashed = false;

      list<Orbital*> orbitals;
      orbitals.push_back(orbital1);
      orbitals.push_back(orbital2);

      // exercise
      orbital1->detectCollisions(orbitals);

      // verify
      assertEquals(orbital1->hasCrashed, false);
      assertEquals(orbital2->hasCrashed, false);
   }  // teardown

    /*********************************************
    * name:    DETECT COLLISION ON TOP OF EACH OTHER
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0),
    *          radius1 10.0, fragmentCount1 0
    *          Pos2(0.0, 0.0), Vel2(0.0, 0.0), Angle2(0.0),
    *          radius2 10.0, fragmentCount2 0
    * output:  orbital1 hasCrashed = true; orbital2 hasCrashed = false;
    *********************************************/
   void detectCollision_OnTopOfEachOther()
   {
      // setup
      StubPosition00* initialPosition1 = new StubPosition00();
      DummyVelocity* initialVelocity1  = new DummyVelocity();
      DummyAngle* initialAngle1        = new DummyAngle();
      double radius1 = 10.0;
      int fragmentCount1 = 0;
      DummyOrbital* orbital1 = new DummyOrbital(initialPosition1, fragmentCount1,
                                                radius1, initialVelocity1,
                                                initialAngle1);
      orbital1->hasCrashed = false;

      StubPosition00* initialPosition2 = new StubPosition00();
      DummyVelocity* initialVelocity2  = new DummyVelocity();
      DummyAngle* initialAngle2        = new DummyAngle();
      double radius2 = 10.0;
      int fragmentCount2 = 0;
      DummyOrbital* orbital2 = new DummyOrbital(initialPosition2, fragmentCount2,
                                                radius2, initialVelocity2,
                                                initialAngle2);
      orbital2->hasCrashed = false;

      list<Orbital*> orbitals;
      orbitals.push_back(orbital1);
      orbitals.push_back(orbital2);

      // exercise
      orbital1->detectCollisions(orbitals);

      // verify
      assertEquals(orbital1->hasCrashed, true);
      assertEquals(orbital2->hasCrashed, false);
   }  // teardown

    /*********************************************
    * name:    DESTORY ONE
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0),
    *          radius1 10.0, fragmentCount1 0
    * output:  orbitals is empty
    *********************************************/
   void destroy_One()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      double radius     = 10.0;
      int fragmentCount = 0;
      StubOrbital_OnePart* orbital = new StubOrbital_OnePart(initialPosition,
                                                             fragmentCount,
                                                             radius,
                                                             initialVelocity,
                                                             initialAngle);
      orbital->hasCrashed = false;

      list<Orbital*> orbitals;
      orbitals.push_back(orbital);

      // exercise
      orbital->destroy(orbitals);

      // verify
      assertUnit(std::find(orbitals.begin(), orbitals.end(), orbital) ==
                           orbitals.end());
      assertUnit(orbitals.size() == 1);
   }  // teardown

    /*********************************************
    * name:    DESTORY NONE
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0),
    *          radius1 10.0, fragmentCount1 0
    * output:  orbitals is empty
    *********************************************/
   void destroy_None()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      double radius = 10.0;
      int fragmentCount = 0;
      StubOrbital_NoParts* orbital = new StubOrbital_NoParts(initialPosition,
                                                             fragmentCount,
                                                             radius,
                                                             initialVelocity,
                                                             initialAngle);
      orbital->hasCrashed = false;

      list<Orbital*> orbitals;

      // exercise
      orbital->destroy(orbitals);

      // verify
      assertUnit(std::find(orbitals.begin(), orbitals.end(), orbital) ==
         orbitals.end());
      assertUnit(orbitals.size() == 0);
   }  // teardown

    /*********************************************
    * name:    DESTORY MANY
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0),
    *          radius1 10.0, fragmentCount1 0
    * output:  orbitals is empty
    *********************************************/
   void destroy_Many()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      double radius = 10.0;
      int fragmentCount = 0;
      StubOrbital_ThreeParts* orbital = new StubOrbital_ThreeParts(initialPosition,
                                                                   fragmentCount,
                                                                   radius,
                                                                   initialVelocity,
                                                                   initialAngle);
      orbital->hasCrashed = false;

      list<Orbital*> orbitals;
      orbitals.push_back(orbital);

      // exercise
      orbital->destroy(orbitals);

      // verify
      assertUnit(std::find(orbitals.begin(), orbitals.end(), orbital) ==
         orbitals.end());
      assertUnit(orbitals.size() == 3);
   }  // teardown
   
   /*********************************************
   * name:    DESTORY MANY Parts and Fragments
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0),
   *          radius1 10.0, fragmentCount1 3
   * output:  orbitals is empty
   *********************************************/
   void destroy_ManyPartsAndFragments()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      StubOrbital_ThreeFragmentThreeParts* orbital =
        new StubOrbital_ThreeFragmentThreeParts(initialPosition, initialVelocity,
                                                initialAngle);
      orbital->hasCrashed = false;

      list<Orbital*> orbitals;
      orbitals.push_back(orbital);

      // exercise
      orbital->destroy(orbitals);

      // verify
      assertUnit(std::find(orbitals.begin(), orbitals.end(), orbital) ==
         orbitals.end());
      assertUnit(orbitals.size() == 6);
   }  // teardown
   
   /*********************************************
   * name:    DESTORY MANY  Fragments No Parts
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0),
   *          radius1 10.0, fragmentCount1 3
   * output:  orbitals is empty
   *********************************************/
   void destroy_ManyFragmentsNoParts()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      StubOrbital_ThreeFragmentZeroParts* orbital =
        new StubOrbital_ThreeFragmentZeroParts(initialPosition, initialVelocity,
                                               initialAngle);
      orbital->hasCrashed = false;

      list<Orbital*> orbitals;
      orbitals.push_back(orbital);

      // exercise
      orbital->destroy(orbitals);

      // verify
      assertUnit(std::find(orbitals.begin(), orbitals.end(), orbital) ==
         orbitals.end());
      assertUnit(orbitals.size() == 3);
   }  // teardown

   /*********************************************
   * name:    GET FRAGMENTS 1
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
   * output:  fragments has 1
   *********************************************/
   void getFragments_1()
   {
     // setup
     StubPosition00* initialPosition  = new StubPosition00();
     DummyVelocity* initialVelocity   = new DummyVelocity();
     DummyAngle* initialAngle         = new DummyAngle();
     StubOrbital_OneFragment* orbital = new StubOrbital_OneFragment(
                                                    initialPosition,
                                                    initialVelocity,
                                                    initialAngle);
     orbital->hasCrashed = false;
     orbital->useRandom = false;
     orbital->radius = 0;

     list<Orbital*> fragments;
      
     // exercise
     fragments = orbital->getFragments();

     // verifY
      assertEquals(fragments.front()->pos->x, 0.0);
     assertEquals(fragments.front()->pos->y, 160.0);
     assertUnit  (fragments.size() == 1);
   }  // teardown

   /*********************************************
   * name:    GET FRAGMENTS 0
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
   * output:  fragments has 0
   *********************************************/
   void getFragments_0()
   {
     // setup
     StubPosition00* initialPosition   = new StubPosition00();
     DummyVelocity* initialVelocity    = new DummyVelocity();
     DummyAngle* initialAngle          = new DummyAngle();
     StubOrbital_ZeroFragment* orbital = new StubOrbital_ZeroFragment(
                                                      initialPosition,
                                                      initialVelocity,
                                                      initialAngle);
     orbital->hasCrashed = false;
     orbital->useRandom = false;
     orbital->radius = 0;

     list<Orbital*> fragments;
      
     // exercise
     fragments = orbital->getFragments();

     // verify
     assertUnit(fragments.size() == 0);
   }  // teardown
   
   /*********************************************
   * name:    GET FRAGMENTS 4
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
   * output:  fragments has 4
   *********************************************/
   void getFragments_4()
   {
     // setup
     StubPosition00* initialPosition    = new StubPosition00();
     DummyVelocity* initialVelocity     = new DummyVelocity();
     DummyAngle* initialAngle           = new DummyAngle();
      StubOrbital_FourFragment* orbital = new StubOrbital_FourFragment(
                                                       initialPosition,
                                                       initialVelocity,
                                                       initialAngle);
     orbital->hasCrashed = false;
     orbital->useRandom = false;
     orbital->radius = 0;

     list<Orbital*> fragments;
      
     // exercise
     fragments = orbital->getFragments();

     // verify
     auto it = fragments.begin();
     std::advance(it, 1);
      assertEquals(fragments.front()->pos->x, 0.0);
     assertEquals(fragments.front()->pos->y, 160.0);
      assertEquals((*it)->pos->x, 160.0);
     assertEquals((*it)->pos->y, 0.0);
      
     std::advance(it, 1);
      assertEquals((*it)->pos->x, 0.0);
     assertEquals((*it)->pos->y, -160.0);
      assertEquals(fragments.back()->pos->x, -160.0);
     assertEquals(fragments.back()->pos->y, 0.0);
     assertUnit(fragments.size() == 4);
   }  // teardown
};

/*********************************************
* TEST Bullet
* Unit tests for bullet
*********************************************/
class TestBullet : public UnitTest
{
public:
   void run()
   {
      updateBullet_beforeExpiration();
      updateBullet_duringExpiration();
      updateBullet_afterExpiration();
      
      report("Bullet");
   }
private:
   
   /*********************************************
   * name:    Update Bullet before expiration
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0) lifespan: 0
   * output: hasCrashed = false
   *********************************************/
   void updateBullet_beforeExpiration()
   {
     // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      Bullet* bullet = new Bullet(initialPosition, initialVelocity, initialAngle);
      bullet->hasCrashed = false;
      bullet->lifespan   = 0;

      // exercise
      bullet->update();
      
      // verify
      assertEquals(bullet->lifespan, 1);
      assertEquals(bullet->hasCrashed, false);
   }  // teardown
   
   /*********************************************
   * name:    Update Bullet during expiration
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0) lifespan: 70
   * output: hasCrashed = true
   *********************************************/
   void updateBullet_duringExpiration()
   {
     // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      Bullet* bullet = new Bullet(initialPosition, initialVelocity, initialAngle);
      bullet->hasCrashed = false;
      bullet->lifespan   = 70;

      // exercise
      bullet->update();
      
      // verify
      assertEquals(bullet->lifespan, 71);
      assertEquals(bullet->hasCrashed, true);
   }  // teardown
   
   /*********************************************
   * name:    Update Bullet after expiration
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0) lifespan: 7100
   * output: hasCrashed = true
   *********************************************/
   void updateBullet_afterExpiration()
   {
     // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      Bullet* bullet = new Bullet(initialPosition, initialVelocity, initialAngle);
      bullet->hasCrashed = false;
      bullet->lifespan   = 7100;

      // exercise
      bullet->update();
      
      // verify
      assertEquals(bullet->lifespan, 7101);
      assertEquals(bullet->hasCrashed, true);
   }  // teardown
};






/*********************************************
* TEST Fragment
* Unit tests for Bullet
*********************************************/
class TestFragment : public UnitTest
{
public:
   void run()
   {
      updateFragment_beforeExpiration();
      updateFragment_duringExpiration();
      updateFragment_afterExpiration();
      
      report("Fragment");
   }
private:
   
   /*********************************************
   * name:    Update Fragment before expiration
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0) lifespan: 0
   * output: hasCrashed = false
   *********************************************/
   void updateFragment_beforeExpiration()
   {
     // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      Fragment* fragment = new Fragment(initialPosition, initialVelocity, initialAngle);
      fragment->hasCrashed = false;
      fragment->lifespan   = 0;

      // exercise
      fragment->update();
      
      // verify
      assertEquals(fragment->lifespan, 1);
      assertEquals(fragment->hasCrashed, false);
   }  // teardown
   
   /*********************************************
   * name:    Update Fragment during expiration
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0) lifespan: 70
   * output: hasCrashed = true
   *********************************************/
   void updateFragment_duringExpiration()
   {
     // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      Fragment* fragment = new Fragment(initialPosition, initialVelocity, initialAngle);
      fragment->hasCrashed = false;
      fragment->lifespan = 80;

      // exercise
      fragment->update();
      
      // verify
      assertEquals(fragment->lifespan, 81);
      assertEquals(fragment->hasCrashed, true);
   }  // teardown
   
   /*********************************************
   * name:    Update Fragment after expiration
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0) lifespan: 7100
   * output: hasCrashed = true
   *********************************************/
   void updateFragment_afterExpiration()
   {
     // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      Fragment* fragment = new Fragment(initialPosition, initialVelocity, initialAngle);
      fragment->hasCrashed = false;
      fragment->lifespan   = 7100;

      // exercise
      fragment->update();
      
      // verify
      assertEquals(fragment->lifespan, 7101);
      assertEquals(fragment->hasCrashed, true);
   }  // teardown
};
