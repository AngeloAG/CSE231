/***********************************************************************
 * Source File:
 *    STARLINK
 * Author:
 *    Jacob Mower
 *    Angelo Arellano Gaona
 *    Connor Hopkins
 * Summary:
 *    Starlink class
 ************************************************************************/
#include "starlink.h"

/*******************************************************************************
* Starlink :: DEFAULT CONSTRUCTOR
*******************************************************************************/
Starlink::Starlink() :
   Orbital(new Position(0.0, STARTING_HEIGHT_STARLINK), 2, 6.0,
      new Velocity(5800.0, 0.0), new Angle()) {}

/*******************************************************************************
* STARLINK :: CONSTRUCTOR
*******************************************************************************/
Starlink::Starlink(Position* initialPos,
   Velocity* initialVelocity, Angle* initialAngle) :
   Orbital(initialPos, 2, 6.0, initialVelocity, initialAngle) {}

/*******************************************************************************
* STARLINK :: GET STARLINK PARTS
*     Returns the parts the STARLINK breaks into
*******************************************************************************/
list<Orbital*> Starlink::getParts() const
{
   list<Orbital*> starlinkParts;

   Angle* angles [2];
   Position* positions [2];
   Velocity* velocities [2];

   double randomStartAngle = 0.0;
   if (useRandom)
      randomStartAngle = random(0.0, 360.0);

   for (int i = 0; i < 2; i++)
   {
      angles[i] = new Angle(randomStartAngle +
                                (360/2 * i));
      
      positions[i] = new Position(*this->pos);
      positions[i]->addPixelsX(4 * cos(angles[i]->getRadians()));
      positions[i]->addPixelsY(4 * sin(angles[i]->getRadians()));
      
      velocities[i] = new Velocity(*this->vel);
      double partSpeed = random(5000, 9000);
      Acceleration partAcceleration(*angles[i], partSpeed);
      velocities[i]->add(partAcceleration, TIME_PER_FRAME);
   }
   
   starlinkParts.push_back(new StarlinkBody(positions[0], velocities[0],
                                  angles[0]));
   starlinkParts.push_back(new StarlinkArray(positions[1], velocities[1],
                                  angles[1]));
   return starlinkParts;
}

/*******************************************************************************
* STARLINK :: DRAW
*     Draws the STARLINK in the screen
*******************************************************************************/
void Starlink::draw(ogstream& ogstream) const
{
   ogstream.drawStarlink(*this->pos, this->angle->getDegrees());
}
