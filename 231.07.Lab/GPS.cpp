
#include "GPS.h"

/*******************************************************************************
* GPS :: CONSTRUCTOR
*******************************************************************************/
GPS::GPS(Position* initialPos, int fragmentCount, double radius,
   Velocity& initialVelocity, Angle& initialAngle): 
     Orbital(initialPos, fragmentCount, radius, initialVelocity, initialAngle){}

/*******************************************************************************
* GPS :: GET GPS PARTS
* Description. Returns the parts the GPS breaks into
*******************************************************************************/
list<Orbital*>& GPS::getParts() const
{
   list<Orbital*> emptyList; // This is just a placeholder for next labs
   return emptyList;
}

/*******************************************************************************
* GPS :: DRAW
* Description. Draws the GPS in the screen
*******************************************************************************/
void GPS::draw(ogstream& ogstream) const
{
   ogstream.drawGPS(*this->pos, this->angle.getDegrees());
}