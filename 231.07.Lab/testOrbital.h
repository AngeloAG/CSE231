/***********************************************************************
 * Header File:
 *    TEST ACCELERATION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Unit tests for the Acceleration class.
 ************************************************************************/

#pragma once

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
    * input:   
    * output:  
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

   void getCurrentHeight_noHeight()
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
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, -6378000.0);
   }

   void getCurrentHeight_earthSurfaceX()
   {
      // setup
      Position initialPosition;
      initialPosition.x = 6378000.0;
      initialPosition.y = 0.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      Angle initialAngle;
      initialAngle.radians = 0.0;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 0.0);
   }

   void getCurrentHeight_earthSurfaceY()
   {
      // setup
      Position initialPosition;
      initialPosition.x = 0.0;
      initialPosition.y = 6378000.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      Angle initialAngle;
      initialAngle.radians = 0.0;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 0.0);
   }

   void getCurrentHeight_inSpaceX()
   {
      // setup
      Position initialPosition;
      initialPosition.x = 6378010.0;
      initialPosition.y = 0.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      Angle initialAngle;
      initialAngle.radians = 0.0;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 10.0);
   }

   void getCurrentHeight_inSpaceY()
   {
      // setup
      Position initialPosition;
      initialPosition.x = 0.0;
      initialPosition.y = 6378010.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      Angle initialAngle;
      initialAngle.radians = 0.0;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 10.0);
   }

   void getCurrentHeight_inSpaceXY()
   {
      // setup
      Position initialPosition;
      initialPosition.x = 6378010.0;
      initialPosition.y = 6378010.0;
      Velocity initialVelocity;
      initialVelocity.dx = 0.0;
      initialVelocity.dy = 0.0;
      Angle initialAngle;
      initialAngle.radians = 0.0;
      double radius = 10.0;
      int fragmentCount = 0;
      DummyOrbital orbital(initialPosition, fragmentCount, radius, initialVelocity, initialAngle);
      double currentHeight = 999.9;

      //exercise
      currentHeight = orbital.getCurrentHeight();
      // verify
      assertEquals(currentHeight, 2641868.2430);
   }

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
