///***********************************************************************
// * Header File:
// *    TEST SHIP
// * Author:
// *    Angelo Arellano
// *    Connor Hopkins
// *    Jacob Mower
// * Summary:
// *    Unit tests for the Ship class.
// ************************************************************************/
//
//#pragma once
//#define _USE_MATH_DEFINES
//#include "unitTest.h"
//#include "ship.h"
//
//
///*********************************************
//* TEST ORBITAL
//* Unit tests for orbital
//*********************************************/
//class TestShip : public UnitTest
//{
//public:
//   void run()
//   {
//      constructor_nonDefault();
//
//      report("Ship");
//   }
//
//private:
//   /*****************************************************************
//   *****************************************************************
//   * CONSTRUCTOR
//   *****************************************************************
//   *****************************************************************/
//
//   /*********************************************
//    * name:    thrust_ZeroUp
//    * input:   Pos(11.1, 22.2), Vel(9.9, 8.8), Angle(0.0),
//    *          radius 10.0, fragmentCount 5
//    * output:  Pos(11.1, 22.2), Vel(9.9, 8.8), Angle(0.0),
//    *          radius 10.0, fragmentCount 5
//    *********************************************/
//   void constructor_nonDefault()
//   {  // setup
//      Position* initialPosition = new Position();
//      initialPosition->x = 0.0;
//      initialPosition->y = 0.0;
//      Velocity initialVelocity;
//      initialVelocity.dx = 0.0;
//      initialVelocity.dy = 0.0;
//      DummyAngle initialAngle;
//      double radius = 10.0;
//      int fragmentCount = 0;
//      Ship ship(initialPosition, fragmentCount, radius,
//                           initialVelocity, initialAngle);
//
//      // exercise
//      ship.thrust();
//
//      // verify
//      assertEquals(ship.pos->x, 0.0);
//      assertEquals(ship.pos->y, 2304.0);
//      assertEquals(ship.vel.dx, 0.0);
//      assertEquals(ship.vel.dy, 96.0);
//      assertEquals(ship.angle.radians, 0.0);
//
//
//
//
//   }
//
//   /*****************************************************************
//   *****************************************************************
//   * PRIVATE METHODS
//   *****************************************************************
//   *****************************************************************/
//
//};
