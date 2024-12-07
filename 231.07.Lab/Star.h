/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Star class.
 ************************************************************************/

#include "entity.h"

/*********************************************
* Star
* A single instance of a star.
*********************************************/
class Star : Entity
{
public:
    Star() : Entity(new Position()), phase(0) {             }
    virtual ~Star() { delete pos; } // Prevent memory leaks

    virtual void draw(ogstream& ogstream) const
    { 
        ogstream.drawStar(*this->pos, phase);
    }
    const Position& getPos()              const { return *pos; }
    void setPos(Position* rhs) { delete pos; this->pos = rhs;  }
    void setPhase(unsigned char phase) { this->phase = phase;  }
    void incrementPhase()              { this->phase++;        }

private:
    unsigned char phase;
};