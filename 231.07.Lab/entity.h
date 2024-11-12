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
class Position;
class ogstream;

class Entity {
   friend TestEntity;
protected:
   Position pos;
   
public:
   
   Entity(Position pos):pos(pos)                  {}
   
   virtual void draw(ogstream ogstream)           {}
   const Position& getPos() const {return pos;     }
   void setPos(Position& rhs) {this->pos = rhs;    }
   
};
