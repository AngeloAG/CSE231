/***********************************************************************
 * Header File:
 *    TEST All the satellites
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Unit tests for the satellite classes.
 ************************************************************************/

#pragma once
#define _USE_MATH_DEFINES
#include "unitTest.h"
#include "hubble.h"
#include "crewDragon.h"
#include "sputnik.h"
#include "starlink.h"
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

       getPartsGPS();
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
    
    /*********************************************
    * name:    GET PARTS GPS
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  3 GPS Parts
    *********************************************/
    void getPartsGPS()
    {
       // setup
       StubPosition00* initialPosition = new StubPosition00();
       DummyVelocity* initialVelocity  = new DummyVelocity();
       DummyAngle* initialAngle        = new DummyAngle();
       GPS* gps = new GPS(initialPosition, initialVelocity, initialAngle);
       gps->hasCrashed = false;
       gps->useRandom  = false;
       gps->radius     = 0;
       
       list<Orbital*> parts;
        
       // exercise
       parts = gps->getParts();
       
       // verify
       auto it = parts.begin();
       std::advance(it, 1);
        
       assertEquals(parts.front()->pos->x, 0.0);
       assertEquals(parts.front()->pos->y, 160.0);
       assertEquals((*it)->pos->x, 138.56406);
       assertEquals((*it)->pos->y, -80.0);
       assertEquals(parts.back()->pos->x, -138.56406);
       assertEquals(parts.back()->pos->y, -80.0);
       assertUnit(parts.size() == 3);
    }  // teardown
 };

/*********************************************
* TEST HUBBLE
* Unit tests for hubble
*********************************************/
class TestHubble : public UnitTest
{
public:
   void run()
   {
      defaultConstructor_hubble();
      getPartsHubble();

      
      report("Hubble");
   }
   
private:
   /*****************************************************************
    *****************************************************************
    * CONSTRUCTORS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    defaultConstructor_hubble
    * input:      default hubble
    * output:  Pos(0.0, -42164000.0), Vel(31000, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    *********************************************/
   void defaultConstructor_hubble()
   {  // setup
      // exercise
      Hubble hubble;
      
      // verify
      assertEquals(hubble.pos->x, 0.0);
      assertEquals(hubble.pos->y, -42164000.0);
      assertEquals(hubble.vel->dx, 3100.0);
      assertEquals(hubble.vel->dy, 0.0);
      assertEquals(hubble.angle->radians, 0.0);
      assertEquals(hubble.fragmentCount, 0);
      assertEquals(hubble.radius, 10.0);
   }
   
   /*********************************************
   * name:    GET PARTS Hubble
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
   * output:  4 Hubble Parts
   *********************************************/
   void getPartsHubble()
   {
     // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      Hubble* hubble = new Hubble(initialPosition, initialVelocity, initialAngle);
      hubble->hasCrashed = false;
      hubble->useRandom  = false;
      hubble->radius     = 0;

      list<Orbital*> parts;

      // exercise
      parts = hubble->getParts();

      // verify
      auto it = parts.begin();
      std::advance(it, 1);

      assertEquals(parts.front()->pos->x, 0.0);
      assertEquals(parts.front()->pos->y, 160.0);
      
      assertEquals((*it)->pos->x, 160.0);
      assertEquals((*it)->pos->y, 0.0);

      std::advance(it, 1);
      assertEquals((*it)->pos->x, 0.0);
      assertEquals((*it)->pos->y, -160.0);

      assertEquals(parts.back()->pos->x, -160.0);
      assertEquals(parts.back()->pos->y, 0.0);
      assertUnit(parts.size() == 4);
   }  // teardown
};

/*********************************************
* TEST Sputnik
* Unit tests for sputnik
*********************************************/
class TestSputnik : public UnitTest
{
public:
   void run()
   {
      defaultConstructor_sputnik();

      report("Sputnik");
   }
   
private:
   /*****************************************************************
    *****************************************************************
    * CONSTRUCTORS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    defaultConstructor_hubble
    * input:      default hubble
    * output:  Pos(0.0, -42164000.0), Vel(31000, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    *********************************************/
   void defaultConstructor_sputnik()
   {  // setup
      // exercise
      Sputnik sputnik;
      
      // verify
      assertEquals(sputnik.pos->x, -36515095.13);
      assertEquals(sputnik.pos->y, 21082000.0);
      assertEquals(sputnik.vel->dx, 2050.0);
      assertEquals(sputnik.vel->dy, 2684.68);
      assertEquals(sputnik.angle->radians, 0.0);
      assertEquals(sputnik.fragmentCount, 4);
      assertEquals(sputnik.radius, 4.0);
   }
};

/*********************************************
* TEST HUBBLE
* Unit tests for hubble
*********************************************/
class TestCrewDragon : public UnitTest
{
public:
   void run()
   {
      defaultConstructor_CrewDragon();
      getPartsCrewDragon();

      report("CrewDragon");
   }
   
private:
   /*****************************************************************
    *****************************************************************
    * CONSTRUCTORS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    defaultConstructor_hubble
    * input:      default hubble
    * output:  Pos(0.0, -42164000.0), Vel(31000, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    *********************************************/
   void defaultConstructor_CrewDragon()
   {  // setup
      // exercise
      CrewDragon crewdragon;
      
      // verify
      assertEquals(crewdragon.pos->x, 0.0);
      assertEquals(crewdragon.pos->y, 8000000.0);
      assertEquals(crewdragon.vel->dx, -7900.0);
      assertEquals(crewdragon.vel->dy, 0.0);
      assertEquals(crewdragon.angle->radians, 0.0);
      assertEquals(crewdragon.fragmentCount, 0);
      assertEquals(crewdragon.radius, 7.0);
   }
   
   /*********************************************
   * name:    GET PARTS CrewDragon
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
   * output:  3 Crew Dragon Parts
   *********************************************/
   void getPartsCrewDragon()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      CrewDragon* crewDragon = new CrewDragon(initialPosition, initialVelocity,
                                              initialAngle);
      crewDragon->hasCrashed = false;
      crewDragon->useRandom  = false;
      crewDragon->radius     = 0;

      list<Orbital*> parts;

      // exercise
      parts = crewDragon->getParts();

      // verify
      auto it = parts.begin();
      std::advance(it, 1);

      assertEquals(parts.front()->pos->x, 0.0);
      assertEquals(parts.front()->pos->y, 160.0);
      assertEquals((*it)->pos->x, 138.56406);
      assertEquals((*it)->pos->y, -80.0);
      assertEquals(parts.back()->pos->x, -138.56406);
      assertEquals(parts.back()->pos->y, -80.0);
      assertUnit(parts.size() == 3);
   }  // teardown
};

/*********************************************
* TEST STARLINIK
* Unit tests for STARLINK
*********************************************/
class TestStarlink : public UnitTest
{
public:
   void run()
   {
      defaultConstructor_Starlink();
      getPartsStarlink();

      report("Starlink");
   }
   
private:
   /*****************************************************************
    *****************************************************************
    * CONSTRUCTORS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    defaultConstructor_hubble
    * input:      default hubble
    * output:  Pos(0.0, -42164000.0), Vel(31000, 0.0), Angle(0.0),
    *          radius 10.0, fragmentCount 0
    *********************************************/
   void defaultConstructor_Starlink()
   {  // setup
      // exercise
      Starlink starlink;
      
      // verify
      assertEquals(starlink.pos->x, 0.0);
      assertEquals(starlink.pos->y, -13020000.0);
      assertEquals(starlink.vel->dx, 5800.0);
      assertEquals(starlink.vel->dy, 0.0);
      assertEquals(starlink.angle->radians, 0.0);
      assertEquals(starlink.fragmentCount, 2);
      assertEquals(starlink.radius, 6.0);
   }
   
   /*********************************************
   * name:    GET PARTS Starlink
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
   * output:  2 Starlink Parts
   *********************************************/
   void getPartsStarlink()
   {
     // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity  = new DummyVelocity();
      DummyAngle* initialAngle        = new DummyAngle();
      Starlink* starlink = new Starlink(initialPosition, initialVelocity,
                                        initialAngle);
      starlink->hasCrashed = false;
      starlink->useRandom  = false;
      starlink->radius     = 0;

      list<Orbital*> parts;

      // exercise
      parts = starlink->getParts();

      // verify
      auto it = parts.begin();
      std::advance(it, 1);

      assertEquals(parts.front()->pos->x, 0.0);
      assertEquals(parts.front()->pos->y, 160.0);
      
      assertEquals((*it)->pos->x, 0.0);
      assertEquals((*it)->pos->y, -160.0);
      
      assertUnit(parts.size() == 2);
   }  // teardown
};

