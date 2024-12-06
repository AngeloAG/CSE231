/***********************************************************************
 * Source File:
 *    Hubble
 * Author:
 *    Jacob Mower
 *    Angelo Arellano Gaona
 *    Connor Hopkins
 * Summary:
 *    Hubble Class
 ************************************************************************/

#include "hubble.h"

/*******************************************************************************
* Hubble :: DEFAULT CONSTRUCTOR
*******************************************************************************/
Hubble::Hubble() : 
   Orbital(new Position(0.0, STARTING_HEIGHT_HUBBLE), 0, 10.0, 
      new Velocity(3100.0, 0.0), new Angle()) {}

/*******************************************************************************
* Hubble :: CONSTRUCTOR
*******************************************************************************/
Hubble::Hubble(Position* initialPos,
   Velocity* initialVelocity, Angle* initialAngle) :
   Orbital(initialPos, 0, 10.0, initialVelocity, initialAngle) {}

/*******************************************************************************
* Hubble :: GET Hubble PARTS
*     Returns the parts the Hubble breaks into
*******************************************************************************/
list<Orbital*> Hubble::getParts() const
{
   list<Orbital*> hubbleParts;

   Angle* angles [4];
   Position* positions [4];
   Velocity* velocities [4];

   double randomStartAngle = 0.0;
   if (useRandom)
      randomStartAngle = random(0.0, 360.0);

   for (int i = 0; i < 4; i++)
   {
      angles[i] = new Angle(randomStartAngle +
                                (360/4 * i));
      
      positions[i] = new Position(*this->pos);
      positions[i]->addPixelsX(4 * cos(angles[i]->getRadians()));
      positions[i]->addPixelsY(4 * sin(angles[i]->getRadians()));
      
      velocities[i] = new Velocity(*this->vel);
      double partSpeed = random(5000, 9000);
      Acceleration partAcceleration(*angles[i], partSpeed);
      velocities[i]->add(partAcceleration, TIME_PER_FRAME);
   }
   
   hubbleParts.push_back(new HubbleLeft(positions[0], velocities[0],
                                  angles[0]));
   hubbleParts.push_back(new HubbleComputer(positions[1], velocities[1],
                                  angles[1]));
   hubbleParts.push_back(new HubbleTelescope(positions[2], velocities[2],
                                  angles[2]));
   hubbleParts.push_back(new HubbleRight(positions[3], velocities[3],
                                  angles[3]));
   return hubbleParts;
}

/*******************************************************************************
* Hubble :: DRAW
*     Draws the Hubble in the screen
*******************************************************************************/
void Hubble::draw(ogstream& ogstream) const
{
   ogstream.drawHubble(*this->pos, this->angle->getDegrees());
}
