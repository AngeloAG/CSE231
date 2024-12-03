
#include "GPS.h"

/*******************************************************************************
* GPS :: DEFAULT CONSTRUCTOR
*******************************************************************************/
GPS::GPS(int gpsId) :
   Orbital(new Position(), 2, 12.0,
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
GPS::GPS(Position* initialPos, int fragmentCount, double radius,
   Velocity* initialVelocity, Angle* initialAngle): 
     Orbital(initialPos, fragmentCount, radius, initialVelocity, initialAngle){}

/*******************************************************************************
* GPS :: GET GPS PARTS
*     Returns the parts the GPS breaks into
*******************************************************************************/
list<Orbital*>& GPS::getParts() const
{
   list<Orbital*> emptyList; // This is just a placeholder for next labs
   return emptyList;
}

/*******************************************************************************
* GPS :: DRAW
*     Draws the GPS in the screen
*******************************************************************************/
void GPS::draw(ogstream& ogstream) const
{
   ogstream.drawGPS(*this->pos, this->angle->getDegrees());
}