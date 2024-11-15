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
#include <iostream>

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      /*Position initalGpsPos(0.0, STARTING_HEIGHT);
      Velocity initialGpsVel(-3100.0, 0.0);
      double radius = 10.0;
      int fragmentCount = 10;
      Angle initalAngle;

      gps = new GPS(initalGpsPos, fragmentCount, radius, initialGpsVel, initalAngle);
      angleEarth = 0.0;*/

      for (int i = 0; i < NUMBER_OF_STARS; i++) {
         ptStar[i].setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
         ptStar[i].setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
         phaseStar[i] = i;
      }
   }
   
   //Orbital* gps;
   Position ptStar[NUMBER_OF_STARS];
   Position ptUpperRight;

   unsigned char phaseStar[NUMBER_OF_STARS];
   double angleEarth;
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

   // rotate the earth
   pDemo->angleEarth += -(2.0 * M_PI / FRAME_RATE) *
      (TIME_DIALATION / SECONDS_PER_DAY);

   //pDemo->gps->update();

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   //pDemo->gps->draw(gout);

   // draw parts

   // draw a single star
   for (int i = 0; i < NUMBER_OF_STARS; i ++) {
      gout.drawStar(pDemo->ptStar[i], pDemo->phaseStar[i]);
      pDemo->phaseStar[i]++;
   }

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
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
