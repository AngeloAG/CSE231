/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testVelocity.h"
#include "testAngle.h"
#include "testAcceleration.h"
#include "testEntity.h"
#include "testOrbital.h"
#include "testShip.h"
#include "testGame.h"
#include "testSatellite.h"

#ifdef _WIN32
#include <windows.h>
#include <iostream>
using namespace std;
#endif

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32

   TestPosition().run();
   TestVelocity().run();
   TestAcceleration().run();
   TestAngle().run();
   TestEntity().run();
   TestOrbital().run();
   TestShip().run();
   TestGPS().run();
   TestHubble().run();
   TestStarlink().run();
   TestSputnik().run();
   TestCrewDragon().run();
   TestBullet().run();
   TestFragment().run();
   TestGame().run();
}
