/***********************************************************************
 * Source File:
 *    SPUTNIK
 * Author:
 *    Jacob Mower
 *    Angelo Arellano Gaona
 *    Connor Hopkins
 * Summary:
 *    Sputnik class
 ************************************************************************/

#include "sputnik.h"

/*******************************************************************************
* Sputnik :: DEFAULT CONSTRUCTOR
*******************************************************************************/
Sputnik::Sputnik() :
   Orbital(new Position(STARTING_HEIGHT_SPUTNIK_X, STARTING_HEIGHT_SPUTNIK_Y),
           4, 4.0, new Velocity(2050.0, 2684.68), new Angle()) {}

/*******************************************************************************
* SPUTNIK :: CONSTRUCTOR
*******************************************************************************/
Sputnik::Sputnik(Position* initialPos, Velocity* initialVelocity,
                 Angle* initialAngle) : Orbital(initialPos, 4, 4.0,
                                                initialVelocity,
                                                initialAngle) {    }

/*******************************************************************************
* SPUTNIK :: GET GPS PARTS
*     Returns the parts the SPUTNIK breaks into
*******************************************************************************/
list<Orbital*> Sputnik::getParts() const
{
   list<Orbital*> emptyList;
   return emptyList;
}

/*******************************************************************************
* SPUTNIK :: DRAW
*     Draws the SPUTNIK in the screen
*******************************************************************************/
void Sputnik::draw(ogstream& ogstream) const
{
   ogstream.drawSputnik(*this->pos, this->angle->getDegrees());
}
