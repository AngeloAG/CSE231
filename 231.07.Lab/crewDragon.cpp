
#include "crewDragon.h"

/*******************************************************************************
* GREW DRAGON :: CONSTRUCTOR
*******************************************************************************/
CrewDragon::CrewDragon(Position* initialPos, int fragmentCount, double radius,
   Velocity* initialVelocity, Angle* initialAngle) :
   Orbital(initialPos, fragmentCount, radius, initialVelocity, initialAngle) {}

/*******************************************************************************
* GREW DRAGON :: GET GPS PARTS
*     Returns the parts the GPS breaks into
*******************************************************************************/
list<Orbital*>& CrewDragon::getParts() const
{
   list<Orbital*> emptyList; // This is just a placeholder for next labs
   return emptyList;
}

/*******************************************************************************
* GREW DRAGON :: DRAW
*     Draws the GPS in the screen
*******************************************************************************/
void CrewDragon::draw(ogstream& ogstream) const
{
   ogstream.drawCrewDragon(*this->pos, this->angle->getDegrees());
}