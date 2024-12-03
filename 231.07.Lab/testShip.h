/***********************************************************************
 * Header File:
 *    TEST SHIP
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Unit tests for the Ship class.
 ************************************************************************/

#pragma once
#define _USE_MATH_DEFINES
#include "unitTest.h"
#include "ship.h"


/*********************************************
* TEST ORBITAL
* Unit tests for orbital
*********************************************/
class TestShip : public UnitTest
{
public:
   void run()
   {
      thrust_FromZeroUp();
      thrust_FromZeroRight();
      thrust_FromZeroUpRight();
      thrust_MovingBackwardsStop();
      turn_Left();
      turn_Right();

      report("Ship");
   }

private:
   /*****************************************************************
   *****************************************************************
   * PRIVATE METHODS
   *****************************************************************
   *****************************************************************/

   /*********************************************
    * name:    thrust_FromZeroUp
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 5
    * output:  Pos(0.0, 0.0), Vel(0.0, 96.0), Angle(0.0),
    *          radius 10.0, fragmentCount 5
    *********************************************/
   void thrust_FromZeroUp()
   {  // setup
      Position* initialPosition = new StubPosition00();
      Velocity* initialVelocity = new Velocity();
      initialVelocity->dx = 0.0;
      initialVelocity->dy = 0.0;
      StubAngleUp* initialAngle = new StubAngleUp();
      double radius = 10.0;
      int fragmentCount = 0;
      Ship ship(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);
      ship.isThrust = false;

      // exercise
      ship.thrust();

      // verify
      assertEquals(ship.pos->x, 0.0);
      assertEquals(ship.pos->y, 0.0);
      assertEquals(ship.vel->dx, 0.0);
      assertEquals(ship.vel->dy, 96.0);
      assertEquals(ship.isThrust, true);
   }

   /*********************************************
    * name:    thrust_FromZeroRight
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(M_PI_2),
    *          radius 10.0, fragmentCount 5
    * output:  Pos(0.0, 0.0), Vel(96.0, 0.0), Angle(M_PI_2),
    *          radius 10.0, fragmentCount 5
    *********************************************/
   void thrust_FromZeroRight()
   {  // setup
      Position* initialPosition = new StubPosition00();
      Velocity* initialVelocity = new Velocity();
      initialVelocity->dx = 0.0;
      initialVelocity->dy = 0.0;
      StubAngleRight* initialAngle = new StubAngleRight();
      double radius = 10.0;
      int fragmentCount = 0;
      Ship ship(initialPosition, fragmentCount, radius,
         initialVelocity, initialAngle);
      ship.isThrust = false;

      // exercise
      ship.thrust();

      // verify
      assertEquals(ship.pos->x, 0.0);
      assertEquals(ship.pos->y, 0.0);
      assertEquals(ship.vel->dx, 96.0);
      assertEquals(ship.vel->dy, 0.0);
      assertEquals(ship.isThrust, true);
   }

   /*********************************************
    * name:    thrust_FromZeroUpRight
    * input:   Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(M_PI_4),
    *          radius 10.0, fragmentCount 5
    * output:  Pos(0.0, 0.0), Vel(67.8822, 67.8822), Angle(M_PI_4),
    *          radius 10.0, fragmentCount 5
    *********************************************/
   void thrust_FromZeroUpRight()
   {  // setup
      Position* initialPosition = new StubPosition00();
      Velocity* initialVelocity = new Velocity();
      initialVelocity->dx = 0.0;
      initialVelocity->dy = 0.0;
      StubAngleDiagonalUpRight* initialAngle = new StubAngleDiagonalUpRight();
      double radius = 10.0;
      int fragmentCount = 0;
      Ship ship(initialPosition, fragmentCount, radius,
         initialVelocity, initialAngle);
      ship.isThrust = false;

      // exercise
      ship.thrust();

      // verify
      assertEquals(ship.pos->x, 0.0);
      assertEquals(ship.pos->y, 0.0);
      assertEquals(ship.vel->dx, 67.8822);
      assertEquals(ship.vel->dy, 67.8822);
      assertEquals(ship.isThrust, true);
   }

   /*********************************************
    * name:    thrust_MovingBackwardsStop
    * input:   Pos(0.0, 0.0), Vel(-67.8822, -67.8822), Angle(M_PI_4),
    *          radius 10.0, fragmentCount 5
    * output:  Pos(0.0, 0.0), Vel(0.0, 0.0), Angle(M_PI_4),
    *          radius 10.0, fragmentCount 5
    *********************************************/
   void thrust_MovingBackwardsStop()
   {  // setup
      Position* initialPosition = new StubPosition00();
      Velocity* initialVelocity = new Velocity();
      initialVelocity->dx = -67.8822;
      initialVelocity->dy = -67.8822;
      StubAngleDiagonalUpRight* initialAngle = new StubAngleDiagonalUpRight();
      double radius = 10.0;
      int fragmentCount = 0;
      Ship ship(initialPosition, fragmentCount, radius,
         initialVelocity, initialAngle);
      ship.isThrust = false;

      // exercise
      ship.thrust();

      // verify
      assertEquals(ship.pos->x, 0.0);
      assertEquals(ship.pos->y, 0.0);
      assertEquals(ship.vel->dx, 0.0);
      assertEquals(ship.vel->dy, 0.0);
      assertEquals(ship.isThrust, true);
   }

   /*********************************************
    * name:    TURN LEFT
    * input:   Angle.radians(1.0)
    * output:  Angle.radians = 0.9
    *********************************************/
   void turn_Left()
   {
      // Setup
      StubPosition00* initialPosition = new StubPosition00();
      double radius     = 10.0;
      int fragmentCount = 0;
      DummyVelocity* initialVelocity = new DummyVelocity();
      Angle* initialAngle = new Angle();
      initialAngle->radians = 1.0;
      Ship ship(initialPosition, fragmentCount, radius,
                initialVelocity, initialAngle);

      // Exercise
      ship.turnLeft();

      // Verify
      assertEquals(ship.angle->radians, 0.9);
      assertEquals(ship.radius, 10.0);
      assertEquals(ship.fragmentCount, 0);
   }  // Teardown

   /*********************************************
    * name:    TURN RIGHT
    * input:   Angle.radians(1.0)
    * output:  Angle.radians = 1.1
    *********************************************/
   void turn_Right()
   {
      // Setup
      StubPosition00* initialPosition = new StubPosition00();
      double radius = 10.0;
      int fragmentCount = 0;
      DummyVelocity* initialVelocity = new DummyVelocity();
      Angle* initialAngle = new Angle();
      initialAngle->radians = 1.0;
      Ship ship(initialPosition, fragmentCount, radius,
         initialVelocity, initialAngle);

      // Exercise
      ship.turnRight();

      // Verify
      assertEquals(ship.angle->radians, 1.1);
      assertEquals(ship.radius, 10.0);
      assertEquals(ship.fragmentCount, 0);
   }  // Teardown
};
