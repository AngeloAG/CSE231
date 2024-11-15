/***********************************************************************
 * Source File:
 *    Entity
 * Author:
 *    Jacob Mower
 *    Angelo Arellano Gaona
 *    Connor Hopkins
 * Summary:
 *    Base class for all things
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
   Entity(Position& pos): pos(pos)                 {}
   virtual void draw(ogstream& ogstream) const     {}
   const Position& getPos() const { return pos;    }
   void setPos(Position& rhs) { this->pos = rhs;   }

protected:
   Position& pos;   
};
