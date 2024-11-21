
#include "hubble.h"

/*******************************************************************************
* Hubble :: CONSTRUCTOR
*******************************************************************************/
Hubble::Hubble(Position* initialPos, int fragmentCount, double radius,
   Velocity& initialVelocity, Angle* initialAngle) :
   Orbital(initialPos, fragmentCount, radius, initialVelocity, initialAngle) {}

/*******************************************************************************
* Hubble :: GET Hubble PARTS
*     Returns the parts the Hubble breaks into
*******************************************************************************/
list<Orbital*>& Hubble::getParts() const
{
   list<Orbital*> emptyList; // This is just a placeholder for next labs
   return emptyList;
}

/*******************************************************************************
* Hubble :: DRAW
*     Draws the Hubble in the screen
*******************************************************************************/
void Hubble::draw(ogstream& ogstream) const
{
   ogstream.drawHubble(*this->pos, this->angle->getDegrees());
}