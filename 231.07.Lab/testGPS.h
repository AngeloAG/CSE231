/***********************************************************************
 * Header File:
 *    TEST GPS
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Unit tests for the GPS class.
 ************************************************************************/

#pragma once
#define _USE_MATH_DEFINES
#include "unitTest.h"
#include "GPS.h"


 /*********************************************
 * TEST GPS
 * Unit tests for GPS
 *********************************************/
class TestGPS : public UnitTest
{
public:
   void run()
   {
      defaultConstructor_gps1();
      defaultConstructor_gps2();
      defaultConstructor_gps3();
      defaultConstructor_gps4();
      defaultConstructor_gps5();
      defaultConstructor_gps6();

      report("GPS");
   }

private:
   /*****************************************************************
   *****************************************************************
   * CONSTRUCTORS
   *****************************************************************
   *****************************************************************/

   /*********************************************
    * name:    defaultConstructor_gps1
    * input:   GPS(1)
    * output:  Pos(0.0, 26560000.0), Vel(-3880.0, 0.0), Angle(0.0),
    *          radius 12.0, fragmentCount 2
    *********************************************/
   void defaultConstructor_gps1()
   {  // setup
      // exercise
      GPS gps(1);

      // verify
      assertEquals(gps.pos->x, 0.0);
      assertEquals(gps.pos->y, 26560000.0);
      assertEquals(gps.vel->dx, -3880.0);
      assertEquals(gps.vel->dy, 0.0);
      assertEquals(gps.angle->radians, 0.0);
      assertEquals(gps.fragmentCount, 2);
      assertEquals(gps.radius, 12.0);
   }

   /*********************************************
    * name:    defaultConstructor_gps2
    * input:   GPS(2)
    * output:  Pos(23001634.72, 13280000.0), Vel(-1940.0, 3360.18), Angle(0.0),
    *          radius 12.0, fragmentCount 2
    *********************************************/
   void defaultConstructor_gps2()
   {  // setup
      // exercise
      GPS gps(2);

      // verify
      assertEquals(gps.pos->x, 23001634.72);
      assertEquals(gps.pos->y, 13280000.0);
      assertEquals(gps.vel->dx, -1940.0);
      assertEquals(gps.vel->dy, 3360.18);
      assertEquals(gps.angle->radians, 0.0);
      assertEquals(gps.fragmentCount, 2);
      assertEquals(gps.radius, 12.0);
   }

   /*********************************************
    * name:    defaultConstructor_gps3
    * input:   GPS(3)
    * output:  Pos(-23001634.72, 13280000.0), Vel(1940.0, 3360.18), Angle(0.0),
    *          radius 12.0, fragmentCount 2
    *********************************************/
   void defaultConstructor_gps3()
   {  // setup
      // exercise
      GPS gps(3);

      // verify
      assertEquals(gps.pos->x, 23001634.72);
      assertEquals(gps.pos->y, -13280000.0);
      assertEquals(gps.vel->dx, 1940.0);
      assertEquals(gps.vel->dy, 3360.18);
      assertEquals(gps.angle->radians, 0.0);
      assertEquals(gps.fragmentCount, 2);
      assertEquals(gps.radius, 12.0);
   }

   /*********************************************
    * name:    defaultConstructor_gps4
    * input:   GPS(4)
    * output:  Pos(0.0, 26560000.0), Vel(3880.0, 0.0), Angle(0.0),
    *          radius 12.0, fragmentCount 2
    *********************************************/
   void defaultConstructor_gps4()
   {  // setup
      // exercise
      GPS gps(4);

      // verify
      assertEquals(gps.pos->x, 0.0);
      assertEquals(gps.pos->y, -26560000.0);
      assertEquals(gps.vel->dx, 3880.0);
      assertEquals(gps.vel->dy, 0.0);
      assertEquals(gps.angle->radians, 0.0);
      assertEquals(gps.fragmentCount, 2);
      assertEquals(gps.radius, 12.0);
   }

   /*********************************************
    * name:    defaultConstructor_gps5
    * input:   GPS(5)
    * output:  Pos(-23001634.72, -13280000.0), Vel(1940.0, -3360.18), Angle(0.0),
    *          radius 12.0, fragmentCount 2
    *********************************************/
   void defaultConstructor_gps5()
   {  // setup
      // exercise
      GPS gps(5);

      // verify
      assertEquals(gps.pos->x, -23001634.72);
      assertEquals(gps.pos->y, -13280000.0);
      assertEquals(gps.vel->dx, 1940.0);
      assertEquals(gps.vel->dy, -3360.18);
      assertEquals(gps.angle->radians, 0.0);
      assertEquals(gps.fragmentCount, 2);
      assertEquals(gps.radius, 12.0);
   }

   /*********************************************
    * name:    defaultConstructor_gps6
    * input:   GPS(6)
    * output:  Pos(-23001634.72, 13280000.0), Vel(-1940.0, -3360.18), Angle(0.0),
    *          radius 12.0, fragmentCount 2
    *********************************************/
   void defaultConstructor_gps6()
   {  // setup
      // exercise
      GPS gps(6);

      // verify
      assertEquals(gps.pos->x, -23001634.72);
      assertEquals(gps.pos->y, 13280000.0);
      assertEquals(gps.vel->dx, -1940.0);
      assertEquals(gps.vel->dy, -3360.18);
      assertEquals(gps.angle->radians, 0.0);
      assertEquals(gps.fragmentCount, 2);
      assertEquals(gps.radius, 12.0);
   }
};
