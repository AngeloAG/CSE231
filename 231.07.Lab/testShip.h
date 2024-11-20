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
      constructor_nonDefault();
      turn_Left();
      turn_Right();

      report("Ship");
   }

private:
   /*****************************************************************
   *****************************************************************
   * CONSTRUCTOR
   *****************************************************************
   *****************************************************************/

   /*********************************************
    * name:    thrust_ZeroUp
    * input:   Pos(11.1, 22.2), Vel(9.9, 8.8), Angle(0.0),
    *          radius 10.0, fragmentCount 5
    * output:  Pos(11.1, 22.2), Vel(9.9, 8.8), Angle(0.0),
    *          radius 10.0, fragmentCount 5
    *********************************************/
   void constructor_nonDefault()
   {  // setup
      Position* initialPosition = new Position();
      initialPosition->x = 0.0;
      initialPosition->y = 0.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      DummyAngle initialAngle;
      double radius = 10.0;
      int fragmentCount = 0;
      Ship ship(initialPosition, fragmentCount, radius,
                           initialVelocity, initialAngle);

      // exercise
      ship.thrust();

      // verify
      assertEquals(ship.pos->x, 0.0);
      assertEquals(ship.pos->y, 2304.0);
      assertEquals(ship.vel.dx, 0.0);
      assertEquals(ship.vel.dy, 96.0);
      assertEquals(ship.angle.radians, 0.0);
   }

   /*****************************************************************
   *****************************************************************
   * PRIVATE METHODS
   *****************************************************************
   *****************************************************************/

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
      DummyVelocity initialVelocity;
      Angle initialAngle;
      initialAngle.radians = 1.0;
      Ship ship(initialPosition, fragmentCount, radius,
                initialVelocity, initialAngle);

      // Exercise
      ship.turnLeft();

      // Verify
      assertEquals(ship.angle.radians, 0.9);
      assertEquals(ship.pos->x, 0.0);
      assertEquals(ship.pos->y, 0.0);
      assertEquals(ship.vel.dx, 0.0);
      assertEquals(ship.vel.dy, 0.0);
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
      DummyVelocity initialVelocity;
      Angle initialAngle;
      initialAngle.radians = 1.0;
      Ship ship(initialPosition, fragmentCount, radius,
         initialVelocity, initialAngle);

      // Exercise
      ship.turnRight();

      // Verify
      assertEquals(ship.angle.radians, 1.1);
      assertEquals(ship.pos->x, 0.0);
      assertEquals(ship.pos->y, 0.0);
      assertEquals(ship.vel.dx, 0.0);
      assertEquals(ship.vel.dy, 0.0);
      assertEquals(ship.radius, 10.0);
      assertEquals(ship.fragmentCount, 0);
   }  // Teardown
};
