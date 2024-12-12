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
       destroy_GPS();
       destroy_GPS_Left();
       destroy_GPS_Right();
       destroy_GPS_Center();
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

    /*********************************************
    * name:    DESTROY GPS
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  3 GPS Parts and 2 fragments
    *********************************************/
    void destroy_GPS()
    {
       // setup
       StubPosition00* initialPosition = new StubPosition00();
       DummyVelocity* initialVelocity = new DummyVelocity();
       DummyAngle* initialAngle = new DummyAngle();
       GPS* gps = new GPS(initialPosition, initialVelocity, initialAngle);
       gps->hasCrashed = false;
       gps->useRandom = false;
       gps->radius = 0;
       Fragment   fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
       GPSLeft     gpsLeftToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
       GPSRight   gpsRightToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
       GPSCenter gpsCenterToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

       list<Orbital*> fragmentsAndParts;

       // exercise
       gps->destroy(fragmentsAndParts);

       // verify
       auto it = fragmentsAndParts.begin();
       assertUnit(typeid(*(*it++)) == typeid(gpsLeftToCompare));
       assertUnit(typeid(*(*it++)) == typeid(gpsCenterToCompare));
       assertUnit(typeid(*(*it++)) == typeid(gpsRightToCompare));
       assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
       assertUnit(typeid(*(*it)) == typeid(fragmentToCompare));
       assertUnit(fragmentsAndParts.size() == 5);
    }  // teardown

    /*********************************************
    * name:    DESTROY GPS_Left
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 GPS Parts and 3 fragments
    *********************************************/
    void destroy_GPS_Left()
    {
       // setup
       StubPosition00* initialPosition = new StubPosition00();
       DummyVelocity* initialVelocity = new DummyVelocity();
       DummyAngle* initialAngle = new DummyAngle();
       GPSLeft* gpsLeft = new GPSLeft(initialPosition, initialVelocity, initialAngle);
       gpsLeft->hasCrashed = false;
       gpsLeft->useRandom = false;
       gpsLeft->radius = 0;
       Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

       list<Orbital*> fragments;

       // exercise
       gpsLeft->destroy(fragments);

       // verify
       auto it = fragments.begin();
       assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
       assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
       assertUnit(typeid(*(*it  )) == typeid(fragmentToCompare));
       assertUnit(fragments.size() == 3);
    }  // teardown

    /*********************************************
    * name:    DESTROY GPS_Right
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 GPS Parts and 3 fragments
    *********************************************/
    void destroy_GPS_Right()
    {
       // setup
       StubPosition00* initialPosition = new StubPosition00();
       DummyVelocity* initialVelocity = new DummyVelocity();
       DummyAngle* initialAngle = new DummyAngle();
       GPSRight* gpsRight = new GPSRight(initialPosition, initialVelocity, initialAngle);
       gpsRight->hasCrashed = false;
       gpsRight->useRandom = false;
       gpsRight->radius = 0;
       Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

       list<Orbital*> fragments;

       // exercise
       gpsRight->destroy(fragments);

       // verify
       auto it = fragments.begin();
       assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
       assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
       assertUnit(typeid(*(*it  )) == typeid(fragmentToCompare));
       assertUnit(fragments.size() == 3);
    }  // teardown

    /*********************************************
    * name:    DESTROY GPS_Center
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 GPS Parts and 3 fragments
    *********************************************/
    void destroy_GPS_Center()
    {
       // setup
       StubPosition00* initialPosition = new StubPosition00();
       DummyVelocity* initialVelocity = new DummyVelocity();
       DummyAngle* initialAngle = new DummyAngle();
       GPSCenter* gpsCenter = new GPSCenter(initialPosition, initialVelocity, initialAngle);
       gpsCenter->hasCrashed = false;
       gpsCenter->useRandom = false;
       gpsCenter->radius = 0;
       Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

       list<Orbital*> fragments;

       // exercise
       gpsCenter->destroy(fragments);

       // verify
       auto it = fragments.begin();
       assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
       assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
       assertUnit(typeid(*(*it)) == typeid(fragmentToCompare));
       assertUnit(fragments.size() == 3);
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
      destroy_Hubble();
      destroy_Hubble_Left();
      destroy_Hubble_Right();
      destroy_Hubble_Computer();
      destroy_Hubble_Telescope();
      
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

    /*********************************************
    * name:    DESTROY Hubble
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  4 Hubble Parts and 0 fragments
    *********************************************/
   void destroy_Hubble()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      Hubble* hubble = new Hubble(initialPosition, initialVelocity, initialAngle);
      hubble->hasCrashed = false;
      hubble->useRandom = false;
      hubble->radius = 0;
      HubbleLeft      hubbleLeftToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
      HubbleComputer  hubbleComputerToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
      HubbleTelescope hubbleTelescopeToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
      HubbleRight     hubbleRightToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> parts;

      // exercise
      hubble->destroy(parts);

      // verify
      auto it = parts.begin();
      assertUnit(typeid(*(*it++)) == typeid(hubbleLeftToCompare));
      assertUnit(typeid(*(*it++)) == typeid(hubbleComputerToCompare));
      assertUnit(typeid(*(*it++)) == typeid(hubbleTelescopeToCompare));
      assertUnit(typeid(*(*it)) == typeid(hubbleRightToCompare));
      assertUnit(parts.size() == 4);
   }  // teardown

   /*********************************************
    * name:    DESTROY Hubble_Left
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 GPS Parts and 2 fragments
    *********************************************/
   void destroy_Hubble_Left()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      HubbleLeft* hubbleLeft = new HubbleLeft(initialPosition, initialVelocity, initialAngle);
      hubbleLeft->hasCrashed = false;
      hubbleLeft->useRandom = false;
      hubbleLeft->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> fragments;

      // exercise
      hubbleLeft->destroy(fragments);

      // verify
      auto it = fragments.begin();
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it)) == typeid(fragmentToCompare));
      assertUnit(fragments.size() == 2);
   }  // teardown

   /*********************************************
    * name:    DESTROY Hubble_Right
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 GPS Parts and 2 fragments
    *********************************************/
   void destroy_Hubble_Right()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      HubbleRight* hubbleRight = new HubbleRight(initialPosition, initialVelocity, initialAngle);
      hubbleRight->hasCrashed = false;
      hubbleRight->useRandom = false;
      hubbleRight->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> fragments;

      // exercise
      hubbleRight->destroy(fragments);

      // verify
      auto it = fragments.begin();
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it)) == typeid(fragmentToCompare));
      assertUnit(fragments.size() == 2);
   }  // teardown

   /*********************************************
    * name:    DESTROY Hubble_Computer
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 GPS Parts and 2 fragments
    *********************************************/
   void destroy_Hubble_Computer()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      HubbleComputer* hubbleComputer = new HubbleComputer(initialPosition, initialVelocity, initialAngle);
      hubbleComputer->hasCrashed = false;
      hubbleComputer->useRandom = false;
      hubbleComputer->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> fragments;

      // exercise
      hubbleComputer->destroy(fragments);

      // verify
      auto it = fragments.begin();
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it)) == typeid(fragmentToCompare));
      assertUnit(fragments.size() == 2);
   }  // teardown

   /*********************************************
    * name:    DESTROY Hubble_Telescope
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 GPS Parts and 3 fragments
    *********************************************/
   void destroy_Hubble_Telescope()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      HubbleTelescope* hubbleTelescope = new HubbleTelescope(initialPosition, initialVelocity, initialAngle);
      hubbleTelescope->hasCrashed = false;
      hubbleTelescope->useRandom = false;
      hubbleTelescope->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> fragments;

      // exercise
      hubbleTelescope->destroy(fragments);

      // verify
      auto it = fragments.begin();
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it)) == typeid(fragmentToCompare));
      assertUnit(fragments.size() == 3);
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
      destroy_Sputnik();

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

   /*********************************************
    * name:    DESTROY Sputnik
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 Hubble Parts and 4 fragments
    *********************************************/
   void destroy_Sputnik()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      Sputnik* sputnik = new Sputnik(initialPosition, initialVelocity, initialAngle);
      sputnik->hasCrashed = false;
      sputnik->useRandom = false;
      sputnik->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> parts;

      // exercise
      sputnik->destroy(parts);

      // verify
      auto it = parts.begin();
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));;
      assertUnit(typeid(*(*it  )) == typeid(fragmentToCompare));;
      assertUnit(parts.size() == 4);
   }  // teardown
};

/*********************************************
* TEST Crew Dragon
* Unit tests for Crew Dragon
*********************************************/
class TestCrewDragon : public UnitTest
{
public:
   void run()
   {
      defaultConstructor_CrewDragon();
      getPartsCrewDragon();


      destroy_CrewDragon();
      destroy_CrewDragon_Left();
      destroy_CrewDragon_Right();
      destroy_CrewDragon_Center();
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
      assertEquals(crewdragon.fragmentCount, 2);
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

   /*********************************************
   * name:    DESTROY Crew Dragon
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
   * output:  3 Hubble Parts and 2 fragments
   *********************************************/
   void destroy_CrewDragon()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      CrewDragon* crewDragon = new CrewDragon(initialPosition, initialVelocity, initialAngle);
      crewDragon->hasCrashed = false;
      crewDragon->useRandom = false;
      crewDragon->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
      CrewDragonLeft   crewDragonLeftToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
      CrewDragonCenter crewDragonCenterToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
      CrewDragonRight  crewDragonRightToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> parts;

      // exercise
      crewDragon->destroy(parts);

      // verify
      auto it = parts.begin();
      assertUnit(typeid(*(*it++)) == typeid(crewDragonLeftToCompare));
      assertUnit(typeid(*(*it++)) == typeid(crewDragonCenterToCompare));
      assertUnit(typeid(*(*it++)) == typeid(crewDragonRightToCompare));
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it  )) == typeid(fragmentToCompare));
      assertUnit(parts.size() == 5);
   }  // teardown

   /*********************************************
    * name:    DESTROY CrewDragon_Left
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 GPS Parts and 2 fragments
    *********************************************/
   void destroy_CrewDragon_Left()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      CrewDragonLeft* crewDragonLeft = new CrewDragonLeft(initialPosition, initialVelocity, initialAngle);
      crewDragonLeft->hasCrashed = false;
      crewDragonLeft->useRandom = false;
      crewDragonLeft->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> fragments;

      // exercise
      crewDragonLeft->destroy(fragments);

      // verify
      auto it = fragments.begin();
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it  )) == typeid(fragmentToCompare));
      assertUnit(fragments.size() == 2);
   }  // teardown

   /*********************************************
   * name:    DESTROY CrewDragon_Right
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
   * output:  0 GPS Parts and 2 fragments
   *********************************************/
   void destroy_CrewDragon_Right()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      CrewDragonRight* crewDragonRight = new CrewDragonRight(initialPosition, initialVelocity, initialAngle);
      crewDragonRight->hasCrashed = false;
      crewDragonRight->useRandom = false;
      crewDragonRight->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> fragments;

      // exercise
      crewDragonRight->destroy(fragments);

      // verify
      auto it = fragments.begin();
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it  )) == typeid(fragmentToCompare));
      assertUnit(fragments.size() == 2);
   }  // teardown

   /*********************************************
   * name:    DESTROY CrewDragon_Center
   * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
   * output:  0 GPS Parts and 4 fragments
   *********************************************/
   void destroy_CrewDragon_Center()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      CrewDragonCenter* crewDragonCenter = new CrewDragonCenter(initialPosition, initialVelocity, initialAngle);
      crewDragonCenter->hasCrashed = false;
      crewDragonCenter->useRandom = false;
      crewDragonCenter->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> fragments;

      // exercise
      crewDragonCenter->destroy(fragments);

      // verify
      auto it = fragments.begin();
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it  )) == typeid(fragmentToCompare));
      assertUnit(fragments.size() == 4);
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

      destroy_Starlink();
      destroy_Starlink_Body();
      destroy_Starlink_Array();
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

   /*********************************************
    * name:    DESTROY Starlink
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  2 GPS Parts and 2 fragments
    *********************************************/
   void destroy_Starlink()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      Starlink* starlink = new Starlink(initialPosition, initialVelocity, initialAngle);
      starlink->hasCrashed = false;
      starlink->useRandom = false;
      starlink->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
      StarlinkArray starlinkArrayToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());
      StarlinkBody starlinkBodyToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> fragmentsAndParts;

      // exercise
      starlink->destroy(fragmentsAndParts);

      // verify
      auto it = fragmentsAndParts.begin();
      assertUnit(typeid(*(*it++)) == typeid(starlinkBodyToCompare));
      assertUnit(typeid(*(*it++)) == typeid(starlinkArrayToCompare));
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it  )) == typeid(fragmentToCompare));
      assertUnit(fragmentsAndParts.size() == 4);
   }  // teardown

   /*********************************************
    * name:    DESTROY Starlink Body
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 GPS Parts and 3 fragments
    *********************************************/
   void destroy_Starlink_Body()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      StarlinkBody* starlinkBody = new StarlinkBody(initialPosition, initialVelocity, initialAngle);
      starlinkBody->hasCrashed = false;
      starlinkBody->useRandom = false;
      starlinkBody->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> fragments;

      // exercise
      starlinkBody->destroy(fragments);

      // verify
      auto it = fragments.begin();
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it  )) == typeid(fragmentToCompare));
      assertUnit(fragments.size() == 3);
   }  // teardown

   /*********************************************
    * name:    DESTROY Starlink Array
    * input:   Pos1(0.0, 0.0), Vel1(0.0, 0.0), Angle1(0.0)
    * output:  0 GPS Parts and 3 fragments
    *********************************************/
   void destroy_Starlink_Array()
   {
      // setup
      StubPosition00* initialPosition = new StubPosition00();
      DummyVelocity* initialVelocity = new DummyVelocity();
      DummyAngle* initialAngle = new DummyAngle();
      StarlinkArray* starlinkArray = new StarlinkArray(initialPosition, initialVelocity, initialAngle);
      starlinkArray->hasCrashed = false;
      starlinkArray->useRandom = false;
      starlinkArray->radius = 0;
      Fragment fragmentToCompare(new StubPosition00(), new DummyVelocity(), new DummyAngle());

      list<Orbital*> fragments;

      // exercise
      starlinkArray->destroy(fragments);

      // verify
      auto it = fragments.begin();
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it++)) == typeid(fragmentToCompare));
      assertUnit(typeid(*(*it  )) == typeid(fragmentToCompare));
      assertUnit(fragments.size() == 3);
   }  // teardown
};

