
#include "starlink.h"

/*******************************************************************************
* STARLINK :: CONSTRUCTOR
*******************************************************************************/
Starlink::Starlink(Position* initialPos, int fragmentCount, double radius,
   Velocity& initialVelocity, Angle* initialAngle) :
   Orbital(initialPos, fragmentCount, radius, initialVelocity, initialAngle) {}

/*******************************************************************************
* STARLINK :: GET STARLINK PARTS
*     Returns the parts the STARLINK breaks into
*******************************************************************************/
list<Orbital*>& Starlink::getParts() const
{
   list<Orbital*> emptyList; // This is just a placeholder for next labs
   return emptyList;
}

/*******************************************************************************
* STARLINK :: DRAW
*     Draws the STARLINK in the screen
*******************************************************************************/
void Starlink::draw(ogstream& ogstream) const
{
   ogstream.drawStarlink(*this->pos, this->angle->getDegrees());
}