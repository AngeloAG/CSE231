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

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include <math.h>       // for M_PI
#include "test.h"
#include <iostream>
using namespace std;

const double FRAME_RATE      = 15.0;
const int NUMBER_OF_STARS    = 10000;
const double STARTING_HEIGHT = 42164000.0;
const double GRAVITY_AT_SEA  = 9.80665;
const double EARTH_RADIUS    = 6378000;
const double TIME_DIALATION  = 24 * 60; //hours * minutes
const double TIME_PER_FRAME  = TIME_DIALATION / FRAME_RATE;
const double SECONDS_PER_DAY = 86400.0;


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
      ptHubble.setMeters(0.0, STARTING_HEIGHT);

      for (int i = 0; i < NUMBER_OF_STARS; i++) {
         ptStar[i].setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
         ptStar[i].setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
         phaseStar[i] = i;
      }

      angleShip  = 0.0;
      angleEarth = 0.0;
      dx  = -3100.0;
      dy  = 0.0;
      ddx = 0.0;
      ddy = 0.0;
   }
   
   Position ptHubble;
   Position ptStar[NUMBER_OF_STARS];
   Position ptUpperRight;

   unsigned char phaseStar[NUMBER_OF_STARS];

   double angleShip;
   double angleEarth;
   double dx;
   double dy;
   double ddx;
   double ddy;
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
   pDemo->angleShip  += 0.02;
   
   double totalHeight = sqrt(pow(pDemo->ptHubble.getMetersX(), 2)  +
                             pow(pDemo->ptHubble.getMetersY(), 2)) -
                             EARTH_RADIUS;
   
   double gravity = GRAVITY_AT_SEA *
                    pow(EARTH_RADIUS/(EARTH_RADIUS + totalHeight), 2.0);

   double gravityDirection = atan2(0.0 - pDemo->ptHubble.getMetersX(),
                                   0.0 - pDemo->ptHubble.getMetersY());
   
   double ddx = gravity * sin(gravityDirection);
   double ddy = gravity * cos(gravityDirection);
   pDemo->dx += (ddx * TIME_PER_FRAME);
   pDemo->dy += (ddy * TIME_PER_FRAME);
   pDemo->ptHubble.addMetersX(pDemo->dx * TIME_PER_FRAME);
   pDemo->ptHubble.addMetersY(pDemo->dy * TIME_PER_FRAME);

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);

   // draw parts
   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

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
