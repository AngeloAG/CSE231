/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/

#pragma once

#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "unitTest.h"

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestPosition : public UnitTest
{
public:
   void run()
   {
      // Constructors
      construct_default();
      construct_nonDefault();
      construct_copy();
      assign();
 
      // Setters
      setMetersX();
      setMetersY();
      
      // Getters
      getMetersX();
      getMetersY();

      // add
      add_stationary();
      add_noTime();
      add_moving1Second();
      add_moving4Seconds();
      add_accelerating1Second();
      add_accelerating4Seconds();
      add_1Second();
      add_4Seconds();

      report("Position");
   }
   
private:

   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos=(0, 0))
    *********************************************/
   void construct_default()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      // exercise
      Position pos;
      // verify
      assertEquals(pos.x, 0.0);
      assertEquals(pos.y, 0.0);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    NON-DEFAULT CONSTRUCTOR
    * input:   x=120.0, y=360.0
    * output:  pos=(120.0, 360.0)
    *********************************************/
   void construct_nonDefault()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      double x = 120.0;
      double y = 360.0;
      // exercise
      Position pos(x, y);
      // verify
      assertEquals(pos.x, 120.0);
      assertEquals(pos.y, 360.0);
      assertEquals(pos.metersFromPixels, 99.9);
      assertEquals(x, 120.0);
      assertEquals(y, 360.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    COPY CONSTRUCTOR
    * input:   posRHS = (1234.5, 6789.0)
    * output:  pos = (1234.5, 6789.0)
    *********************************************/
   void construct_copy()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position posRHS;
      posRHS.x = 1234.5;
      posRHS.y = 6789.0;
      // exercise
      Position pos(posRHS);
      // verify
      assertEquals(posRHS.x, 1234.5);
      assertEquals(posRHS.y, 6789.0);
      assertEquals(posRHS.metersFromPixels, 99.9);
      assertEquals(pos.x, 1234.5);
      assertEquals(pos.y, 6789.0);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    ASSIGNMENT OPERATOR
    * input:   posLHS=(-99.9, -88.8)  posRHS=(24.68, -13,57)
    * output:  posLHS=(24.68, -13,57)
    *********************************************/
   void assign()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position posLHS;
      posLHS.x = -99.9;
      posLHS.y = -88.8;
      Position posRHS;
      posRHS.x = 24.68;
      posRHS.y = -13.57;
      // exercise
      posLHS = posRHS;
      // verify
      assertEquals(posRHS.x, 24.68);
      assertEquals(posRHS.y, -13.57);
      assertEquals(posRHS.metersFromPixels, 99.9);
      assertEquals(posLHS.x, 24.68);
      assertEquals(posLHS.y, -13.57);
      assertEquals(posLHS.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }
   
   /*********************************************
    * name:    GET METERS X
    * input:   pos=(4500.0, 2500.0)
    * output:  x=4500.0
    *********************************************/
   void getMetersX()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double x = pos.getMetersX();
      // verify
      assertEquals(x, 4500.0);
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2500.0);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    GET METERS Y
    * input:   pos=(4500.0, 2500.0)
    * output:  y=4500.0
    *********************************************/
   void getMetersY()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double y = pos.getMetersY();
      // verify
      assertEquals(pos.x, 4500.0);
      assertEquals(pos.y, 2500.0);
      assertEquals(pos.metersFromPixels, 99.9);
      assertEquals(y, 2500.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    SET METERS Y
    * input:   pos=(999.9, 888.8) x = 123.4
    * output:  pos=(123.4, 888.8)
    *********************************************/
   void setMetersX()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      // exercise
      pos.setMetersX(123.4);
      // verify
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 888.8);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    GET METERS Y ZOOM
    * input:   pos=(999.9, 888.8) y = 123.4
    * output:  pos=(999.9, 123.4)
    *********************************************/
   void setMetersY()
   {  // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 999.9;
      pos.y = 888.8;
      // exercise
      pos.setMetersY(123.4);
      // verify
      assertEquals(pos.x, 999.9);
      assertEquals(pos.y, 123.4);
      assertEquals(pos.metersFromPixels, 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   /*********************************************
    * name:    ADD STATIONARY
    * input:   pos=(2.3, 4.5) a=(0.0, 0.0), v=(0.0, 0.0) t=4.0
    * output:  (2.3, 4.5)
    *********************************************/
   void add_stationary()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      Velocity v;
      v.dx = 0.0;
      v.dy = 0.0;
      double t = 4.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 2.3); // 2.3 + 0.0*4 + 0.5*0.0*4^2
      assertEquals(pos.y, 4.5); // 4.5 + 0.0*4 + 0.5*0.0*4^2
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.0);
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 0.0);
      assertEquals(t, 4.0);
   }  // teardown

   /*********************************************
    * name:    ADD NO TIME
    * input:   pos=(2.3, 4.5) a=(6.0, 7.0), v=(8.0, 10.0) t=0.0
    * output:  (2.3, 4.5)
    *********************************************/
   void add_noTime()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 7.0;
      Velocity v;
      v.dx = 8.0;
      v.dy = 10.0;
      double t = 0.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 2.3);  // 2.3 +  8.0*0 + 0.5*6.0*0^2
      assertEquals(pos.y, 4.5);  // 4.5 + 10.0*0 + 0.5*7.0*0^2
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 7.0);
      assertEquals(v.dx, 8.0);
      assertEquals(v.dy, 10.0);
      assertEquals(t, 0.0);
   }  // teardown

   /*********************************************
    * name:    ADD NO ACCELERATION ONE SECOND
    * input:   pos=(2.3, 4.5) a=(0.0, 0.0), v=(8.0, 10.0) t=1.0
    * output:  (10.3, 14.5)
    *********************************************/
   void add_moving1Second()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      Velocity v;
      v.dx = 8.0;
      v.dy = 10.0;
      double t = 1.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 10.3);   // 2.3 +  8.0*1 + 0.5*0.0*1^2
      assertEquals(pos.y, 14.5);   // 4.5 + 10.0*1 + 0.5*0.0*1^2
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.0);
      assertEquals(v.dx, 8.0);
      assertEquals(v.dy, 10.0);
      assertEquals(t, 1.0);
   }  // teardown

   /*********************************************
    * name:    ADD NO ACCELERATION FOUR SECOND
    * input:   pos=(2.3, 4.5) a=(0.0, 0.0), v=(8.0, 10.0) t=4.0
    * output:  (34.3, 44.5)
    *********************************************/
   void add_moving4Seconds()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      Velocity v;
      v.dx = 8.0;
      v.dy = 10.0;
      double t = 4.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 34.3);   // 2.3 +  8.0*4 + 0.5*0.0*4^2
      assertEquals(pos.y, 44.5);   // 4.5 + 10.0*4 + 0.5*0.0*4^2
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.0);
      assertEquals(v.dx, 8.0);
      assertEquals(v.dy, 10.0);
      assertEquals(t, 4.0);
   }  // teardown

   /*********************************************
    * name:    ADD  ACCELERATION NO VELOCITY ONE SECOND
    * input:   pos=(2.3, 4.5) a=(6.0, 8.0), v=(0.0, 0.0) t=1.0
    * output:  (5.3, 8.5)
    *********************************************/
   void add_accelerating1Second()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 8.0;
      Velocity v;
      v.dx = 0.0;
      v.dy = 0.0;
      double t = 1.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 5.3);    // 2.3 +  0.0*4 + 0.5*6.0*1^2
      assertEquals(pos.y, 8.5);    // 4.5 +  0.0*4 + 0.5*8.0*1^2
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 8.0);
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 0.0);
      assertEquals(t, 1.0);
   }  // teardown

   /*********************************************
    * name:    ADD  ACCELERATION NO VELOCITY FOUR SECOND
    * input:   pos=(2.3, 4.5) a=(6.0, 8.0), v=(0.0, 0.0) t=4.0
    * output:  (50.3, 68.5)
    *********************************************/
   void add_accelerating4Seconds()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 8.0;
      Velocity v;
      v.dx = 0.0;
      v.dy = 0.0;
      double t = 4.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 50.3);    // 2.3 +  0.0*4 + 0.5*6.0*4^2
      assertEquals(pos.y, 68.5);    // 4.5 +  0.0*4 + 0.5*8.0*4^2
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 8.0);
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 0.0);
      assertEquals(t, 4.0);
   }  // teardown

   /*********************************************
    * name:    ADD  ACCELERATION  VELOCITY ONE SECOND
    * input:   pos=(2.3, 4.5) a=(6.0, 8.0), v=(3.0, 5.0) t=1.0
    * output:  (8.3, 13.5)
    *********************************************/
   void add_1Second()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 8.0;
      Velocity v;
      v.dx = 3.0;
      v.dy = 5.0;
      double t = 1.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 8.3);    // 2.3 +  3.0*1 + 0.5*6.0*1^2
      assertEquals(pos.y, 13.5);   // 4.5 +  5.0*1 + 0.5*8.0*1^2
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 8.0);
      assertEquals(v.dx, 3.0);
      assertEquals(v.dy, 5.0);
      assertEquals(t, 1.0);
   }  // teardown

   /*********************************************
    * name:    ADD  ACCELERATION  VELOCITY FOUR SECOND
    * input:   pos=(2.3, 4.5) a=(6.0, 8.0), v=(3.0, 5.0) t=4.0
    * output:  (62.3, 88.5)
    *********************************************/
   void add_4Seconds()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 8.0;
      Velocity v;
      v.dx = 3.0;
      v.dy = 5.0;
      double t = 4.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 62.3);  // 2.3 + (3.0 * 4) + (0.5 * 6.0 * 16.0)
      assertEquals(pos.y, 88.5);  // 4.5 + (5.0 * 4) + (0.5 * 8.0 * 16.0)
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 8.0);
      assertEquals(v.dx, 3.0);
      assertEquals(v.dy, 5.0);
      assertEquals(t, 4.0);
   }  // teardown
};
