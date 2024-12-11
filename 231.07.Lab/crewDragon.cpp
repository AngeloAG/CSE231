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
CrewDragon::CrewDragon() : Orbital(new Position(0.0, STARTING_HEIGHT_CREWDRAGON),
                                   0, 7.0, new Velocity(-7900.0, 0.0), new Angle()) { }

/*******************************************************************************
* GREW DRAGON :: CONSTRUCTOR
*******************************************************************************/
CrewDragon::CrewDragon(Position* initialPos, Velocity* initialVelocity,
                       Angle* initialAngle) : Orbital(initialPos, 0, 7.0,
                                                      initialVelocity,
                                                      initialAngle) {    }

/*******************************************************************************
* GREW DRAGON :: GET GPS PARTS
*     Returns the parts the GPS breaks into
*******************************************************************************/
list<Orbital*> CrewDragon::getParts() const
{
   list<Orbital*> crewDragonParts;

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
   
   crewDragonParts.push_back(new CrewDragonLeft(positions[0], velocities[0],
                                  angles[0]));
   crewDragonParts.push_back(new CrewDragonCenter(positions[1], velocities[1],
                                  angles[1]));
   crewDragonParts.push_back(new CrewDragonRight(positions[2], velocities[2],
                                  angles[2]));
   return crewDragonParts;
}

/*******************************************************************************
* GREW DRAGON :: DRAW
*     Draws the GPS in the screen
*******************************************************************************/
void CrewDragon::draw(ogstream& ogstream) const
{
   ogstream.drawCrewDragon(*this->pos, this->angle->getDegrees());
}
