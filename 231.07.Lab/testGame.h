/***********************************************************************
 * Header File:
 *    TEST GAME
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Unit tests for the game class.
 ************************************************************************/

#pragma once
#define _USE_MATH_DEFINES
#include "unitTest.h"
#include "game.h"

#include <ranges>

 /*********************************************
 * TEST Game
 * Unit tests for game
 *********************************************/
class TestGame : public UnitTest
{
public:
   void run()
   {
      constructor_nonDefault();
      input_left();
      input_right();
      input_down();
      input_space();
      game_createBullet();

      report("Game");
   }

private: 
   /*****************************************************************
   *****************************************************************
   * CONSTRUCTOR
   *****************************************************************
   *****************************************************************/

   /*********************************************
    * name:    NON-DEFAULT CONSTRUCTOR
    * input:   
    * output:  orbitals = 11, ship is not null
    *********************************************/
   void constructor_nonDefault()
   {  // setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);

      // exercise
      Game game(&ptUpperRight);

      // verify
      assertEquals(game.orbitals.size(), 11);
      assertUnit(game.ship != nullptr);
   }

   /*****************************************************************
   *****************************************************************
   * PUBLIC METHODS
   *****************************************************************
   *****************************************************************/
   
   /*********************************************
    * name:    INPUT LEFT PRESSED
    * input:   Interface is left true
    * output:  ship rotates left
    *********************************************/
   void input_left()
   {  // setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);
      Game game(&ptUpperRight);
      Interface* pUI = new Interface();
      pUI->isLeftPress = 1;
      pUI->isRightPress = 0;
      pUI->isDownPress = 0;
      pUI->isSpacePress = 0;

      // exercise
      game.input(pUI);

      // verify
      assertEquals(game.ship->angle->radians, 6.18318); // almost 2 PI
      assertEquals(game.ship->isThrust, false);

      delete pUI;
   }

   /*********************************************
    * name:    INPUT RIGHT PRESSED
    * input:   Interface is right true
    * output:  ship rotates right
    *********************************************/
   void input_right()
   {  // setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);
      Game game(&ptUpperRight);
      Interface* pUI = new Interface();
      pUI->isLeftPress = 0;
      pUI->isRightPress = 1;
      pUI->isDownPress = 0;
      pUI->isSpacePress = 0;

      // exercise
      game.input(pUI);

      // verify
      assertEquals(game.ship->angle->radians, 0.1); // a little to the right
      assertEquals(game.ship->isThrust, false);

      delete pUI;
   }

   /*********************************************
    * name:    INPUT DOWN PRESSED
    * input:   Interface is down true
    * output:  no rotation, thrust is on
    *********************************************/
   void input_down()
   {  // setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);
      Game game(&ptUpperRight);
      Interface* pUI = new Interface();
      pUI->isLeftPress = 0;
      pUI->isRightPress = 0;
      pUI->isDownPress = 1;
      pUI->isSpacePress = 0;

      // exercise
      game.input(pUI);

      // verify
      assertEquals(game.ship->angle->radians, 0.0); // no rotation
      assertEquals(game.ship->isThrust, true);

      delete pUI;
   }

   /*********************************************
    * name:    INPUT SPACE PRESSED
    * input:   Interface is space true
    * output:  no rotation, no thrust, one bullet added
    *********************************************/
   void input_space()
   {  // setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);
      Game game(&ptUpperRight);
      Interface* pUI = new Interface();
      pUI->isLeftPress = 0;
      pUI->isRightPress = 0;
      pUI->isDownPress = 0;
      pUI->isSpacePress = 1;

      // exercise
      game.input(pUI);

      // verify
      assertEquals(game.ship->angle->radians, 0.0); // no rotation
      assertEquals(game.ship->isThrust, false);
      assertEquals(game.orbitals.size(), 12); // one more orbital 

      delete pUI;
   }

   /*****************************************************************
   *****************************************************************
   * PRIVATE METHODS
   *****************************************************************
   *****************************************************************/

   /*********************************************
    * name:    CREATE BULLET
    * input:   
    * output:  creates one bullet in the orbitals list 
    *********************************************/
   void game_createBullet()
   {  // setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);
      Game game(&ptUpperRight);

      // exercise
      game.createBullet();

      // verify
      assertEquals(game.orbitals.size(), 12); // bullet added
      assertEquals(game.orbitals.back()->angle->radians, 0.0); // Moving in the same direction as the ship
   }
};