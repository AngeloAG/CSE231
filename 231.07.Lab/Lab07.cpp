/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#define _USE_MATH_DEFINES

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include <cmath>        // for M_PI
#include "orbital.h"    // for ORBITALS
#include "constants.h"
#include <vector>
#include "test.h"
#include "gps.h"
#include "hubble.h"
#include "sputnik.h"
#include "starlink.h"
#include "crewDragon.h"
#include "ship.h"
#include <iostream>
#include <list>  // for LIST

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight), angleEarth(0.0)
   {
      for (int i = 1; i < 7; i++)
      {
         gpsCount.push_back(new GPS(i));
      }

      hubble = new Hubble();
      sputnik = new Sputnik();
      starlink = new Starlink();
      crewDragon = new CrewDragon();
      ship = new Ship();

      // EARTH
      angleEarth = 0.0;

      for (int i = 0; i < NUMBER_OF_STARS; i++) {
         ptStar[i].setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
         ptStar[i].setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
         phaseStar[i] = i;
      }
   }
   ~Demo()
   {
      for (auto gps : gpsCount)
         delete gps;

      delete hubble; delete sputnik; delete starlink;
      delete crewDragon; delete ship;
   }
   Orbital* hubble;
   Orbital* sputnik;
   Orbital* starlink;
   Orbital* crewDragon;
   Ship* ship;
   Position ptStar[NUMBER_OF_STARS];
   Position ptUpperRight;

   unsigned char phaseStar[NUMBER_OF_STARS];
   double angleEarth;
   list <Orbital*>gpsCount;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // perform all the game logic
   //

      //
   // Input
   //
   if (pUI->isDown())
   {
      pDemo->ship->input(DOWN);
   }
   if (pUI->isLeft())
   {
      pDemo->ship->input(LEFT);
   }
   if (pUI->isRight())
   {
      pDemo->ship->input(RIGHT);
   }
   if (pUI->isSpace())
   {
      pDemo->ship->input(SPACE);
   }

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw a single star
   for (int i = 0; i < NUMBER_OF_STARS; i++) {
      gout.drawStar(pDemo->ptStar[i], pDemo->phaseStar[i]);
      pDemo->phaseStar[i]++;
   }

   // draw satellites
   for (auto gps : pDemo->gpsCount)
   {
      gps->draw(gout);
   }
   pDemo->hubble->draw(gout);
   pDemo->sputnik->draw(gout);
   pDemo->starlink->draw(gout);
   pDemo->crewDragon->draw(gout);
   pDemo->ship->draw(gout);

   // draw parts

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);

   // rotate the earth
   pDemo->angleEarth += -(2.0 * M_PI / FRAME_RATE) *
         (TIME_DIALATION / SECONDS_PER_DAY);

   // Update everything
   for (auto gps : pDemo->gpsCount)
   {
      gps->update();
   }

   pDemo->hubble->update();
   pDemo->sputnik->update();
   pDemo->starlink->update();
   pDemo->crewDragon->update();
   pDemo->ship->update();
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
