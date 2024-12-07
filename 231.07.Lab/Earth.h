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
    Earth() : Orbital(new Position(), 0, 2.0/*6378000.0*/, new Velocity(),
                      new Angle()) {                         }
    virtual ~Earth() { delete pos; } // Prevent memory leaks

    virtual list<Orbital*> getParts() const { return list<Orbital*>(); }

    virtual void update()
    {
        this->angle->add(-(2.0 * M_PI / FRAME_RATE) *
            (TIME_DIALATION / SECONDS_PER_DAY));
    }

    virtual void detectCollisions(const list<Orbital*>& orbitals) {        }

    virtual void draw(ogstream& ogstream) const { ogstream.drawEarth(*this->pos,
                                                  this->angle->getRadians());   }
};