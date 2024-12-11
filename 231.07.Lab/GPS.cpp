/***********************************************************************
 * Source File:
 *    GPS
 * Author:
 *    Jacob Mower
 *    Angelo Arellano Gaona
 *    Connor Hopkins
 * Summary:
 *    GPS class
 ************************************************************************/

#include "GPS.h"

/*******************************************************************************
* GPS :: DEFAULT CONSTRUCTOR
*******************************************************************************/
GPS::GPS(int gpsId) : Orbital(new Position(), 2, 12.0,
                              new Velocity(), new Angle())
{
   switch (gpsId)
   {
   case 1:
      this->vel->setDX(-3880.0);
      this->vel->setDY(0.0);
      this->pos->setMeters(0.0, 26560000.0);
      break;
   case 2:
      this->vel->setDX(-1940.0);
      this->vel->setDY(3360.18);
      this->pos->setMeters(23001634.72, 13280000.0);
      break;
   case 3:
      this->vel->setDX(1940.0);
      this->vel->setDY(3360.18);
      this->pos->setMeters(23001634.72, -13280000.0);
      break;
   case 4:
      this->vel->setDX(3880.0);
      this->vel->setDY(0.0);
      this->pos->setMeters(0.0, -26560000.0);
      break;
   case 5:
      this->vel->setDX(1940.0);
      this->vel->setDY(-3360.18);
      this->pos->setMeters(-23001634.72, -13280000.0);
      break;
   case 6:
      this->vel->setDX(-1940.0);
      this->vel->setDY(-3360.18);
      this->pos->setMeters(-23001634.72, 13280000.0);
      break;
   default:
      break;
   }
}

/*******************************************************************************
* GPS :: CONSTRUCTOR
*******************************************************************************/
GPS::GPS(Position* initialPos, Velocity* initialVelocity, Angle* initialAngle) : 
         Orbital(initialPos, 2, 12.0, initialVelocity, initialAngle) {         }

/*******************************************************************************
* GPS :: GET GPS PARTS
*     Returns the parts the GPS breaks into
*******************************************************************************/
list<Orbital*> GPS::getParts() const
{
   list<Orbital*> gpsParts;

   Angle* angles [3];
   Position* positions [3];
   Velocity* velocities [3];

   double randomStartAngle = 0.0;
   if (useRandom)
      randomStartAngle = random(0.0, 360.0);

   for (int i = 0; i < 3; i++)
   {
      angles[i] = new Angle(randomStartAngle +
                                (360/3 * i));
      
      positions[i] = new Position(*this->pos);
      positions[i]->addPixelsX((4 + this->radius) * sin(angles[i]->getRadians()));
      positions[i]->addPixelsY((4 + this->radius) * cos(angles[i]->getRadians()));
      
      velocities[i] = new Velocity(this->vel->getDX(), this->vel->getDY());
      double partSpeed = random(50.0, 90.0);
      Acceleration partAcceleration(*angles[i], partSpeed);
      velocities[i]->add(partAcceleration, TIME_PER_FRAME);
   }
   
   gpsParts.push_back(new GPSLeft  (positions[0], velocities[0], angles[0]));
   gpsParts.push_back(new GPSCenter(positions[1], velocities[1], angles[1]));
   gpsParts.push_back(new GPSRight (positions[2], velocities[2], angles[2]));

   return gpsParts;
}

/*******************************************************************************
* GPS :: DRAW
*     Draws the GPS in the screen
*******************************************************************************/
void GPS::draw(ogstream& ogstream) const
{
   ogstream.drawGPS(*this->pos, this->angle->getDegrees());
}
