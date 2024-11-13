/***********************************************************************
 * Header File:
 *    TEST VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Unit tests for the Velocity class.
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "entity.h"
#include "position.h"
#include "unitTest.h"

class TestEntity : public UnitTest
{
public:
   void run()
   {
      constructorWithPos();
      entityGetPosition();
      entitySetPosition();
      
      report("Entity");
   }
   
private:
   
   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   pos = (11.1,22.2)
    * output:  pos=(11.1, 22.2))
    *********************************************/
   void constructorWithPos()
   {
      //setup
      Position pos;
      pos.x = 11.1;
      pos.y = 22.2;

      //exercise
      Entity ent(pos);
      
      //verify
      assertEquals(ent.pos.x, 11.1);
      assertEquals(ent.pos.y, 22.2);

      //teardown
   }
   
   /*********************************************
    * name:    Get position
    * input:   pos = (11.1,22.2)
    * output:  pos=(11.1, 22.2))
    *********************************************/
   void entityGetPosition()
   {
      //setup
      Position pos1;
      pos1.x = 11.1;
      pos1.y = 22.2;
      Entity ent(pos1);
      //exercise
      pos1 = ent.getPos();
      //verify
      assertEquals(pos1.x, 11.1);
      assertEquals(pos1.y, 22.2);
      //teardown
   }
   
   /*********************************************
    * name:    Set position
    * input:   pos = (11.1,22.2)
    * output:  pos=(11.1, 22.2))
    *********************************************/
   void entitySetPosition()
   {
      //setup
      Position pos;
      pos.x = 11.1;
      pos.y = 22.2;
      Entity ent(pos);
      ent.pos.x = 99.9;
      ent.pos.y = 99.9;
      Position pos1;
      pos1.x = 33.3;
      pos1.y = 44.4;
      //exercise
      ent.setPos(pos1);
      //verify
      assertEquals(ent.pos.x, 33.3);
      assertEquals(ent.pos.y, 44.4);
      //teardown
   }
   
};