/***********************************************************************
 * Source File:
 *    Entity
 * Author:
 *    Jacob Mower
 *    Angelo Arellano Gaona
 *    Connor Hopkins
 * Summary:
 *    Base class for all things.
 ************************************************************************/

#pragma once
#include "position.h"
#include "uiDraw.h"

class ogstream;

/*********************************************
* Enity
* A single instance of an entity.
*********************************************/
class Entity {
   friend TestEntity;
   friend TestOrbital;
public:
    Entity()                        { pos = new Position(); }
    Entity(Position* pos): pos(pos) {                       }
    virtual ~Entity()               { delete pos;           }

    virtual void draw(ogstream& ogstream) const {                              }
    const Position& getPos()              const { return *pos;                 }
    void setPos(Position* rhs)                  { delete pos; this->pos = rhs; }

protected:
   Position* pos;   // For stubs
};
