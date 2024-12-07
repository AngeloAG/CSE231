/***********************************************************************
 * Header File:
 *    EARTH
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Earth class.
 ************************************************************************/

#include "orbital.h"

 /*********************************************
 * Earth
 * A single instance of an earth.
 *********************************************/
class Earth : public Orbital
{
public:
    Earth() : Orbital(new Position(), 0, 49.82, new Velocity(), new Angle()) { }
    virtual ~Earth() { } 

    virtual list<Orbital*> getParts() const { return list<Orbital*>(); }

    virtual void update()
    {
        this->angle->add(-(2.0 * M_PI / FRAME_RATE) *
             (TIME_DIALATION / SECONDS_PER_DAY));
    }

    virtual void detectCollisions(const list<Orbital*>& orbitals) {           }
    virtual void destroy(list<Orbital*>& orbitals)                {           }
    virtual void draw(ogstream& ogstream) const 
    { 
       ogstream.drawEarth(*this->pos, this->angle->getRadians());
    }
};