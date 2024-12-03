/***********************************************************************
 * Source File:
 *    Crew Dragon
 * Author:
 *    Jacob Mower
 *    Angelo Arellano Gaona
 *    Connor Hopkins
 * Summary:
 *    Crew Dragon class
 ************************************************************************/
#include "crewDragon.h"

/*******************************************************************************
* CrewDragon :: DEFAULT CONSTRUCTOR
*******************************************************************************/
CrewDragon::CrewDragon() :
   Orbital(new Position(0.0, STARTING_HEIGHT_CREWDRAGON), 0, 7.0,
      new Velocity(-7900.0, 0.0), new Angle()) {}

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
