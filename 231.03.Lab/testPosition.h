/***********************************************************************
 * Header File:
 *    TEST POSITION
 * Author:
 *    Jacob Mower, Angelo Arellano Gaona
 * Summary:
 *    The unit tests for Position
 ************************************************************************/

#pragma once

#include "unitTest.h"

/***************************************************
 * POSITION TEST
 * Test the Position class
 ***************************************************/
class PositionTest : public UnitTest
{
public:
   void run()
   {
      // Ticket 1: Position Core
      getRow_zero();
      getCol_zero();
      getLocation_zero();
      isValid_zero();
      isInvalid_zero();
      getRow_middle();
      getCol_middle();
      getLocation_middle();
      isValid_middle();
      isInvalid_middle();
      getRow_end();
      getCol_end();
      getLocation_end();
      isValid_end();
      isInvalid_end();
      getRow_invalid();
      getCol_invalid();
      isValid_invalid();
      isInvalid_invalid();
      getRow_rowInvalid();
      getCol_rowInvalid();
      isValid_rowInvalid();
      isInvalid_rowInvalid();
      getRow_colInvalid();
      getCol_colInvalid();
      isValid_colInvalid();
      isInvalid_colInvalid();
      set_col();
      set_row();
      set_both();
      set_copy();
      equal_not();
      equal_equals();
      lessthan_lessthan();
      lessthan_equals();
      lessthan_greaterthan();

      // Ticket 2: Position Text
      set_text();
      set_string();
       
      // Ticket 3: Position Movement
      adjust_addColumn();
      adjust_addRow();
      adjust_offRight();
      adjust_offTop();
      adjust_offLeft();
      adjust_offBottom();
      adjust_invalid();
      
      report("Position");
   }
private:
   void getRow_zero();
   void getCol_zero();
   void getLocation_zero();
   void isValid_zero();
   void isInvalid_zero();
   
   void getRow_middle();
   void getCol_middle();
   void getLocation_middle();
   void isValid_middle();
   void isInvalid_middle();
   
   void getRow_end();
   void getCol_end();
   void getLocation_end();
   void isValid_end();
   void isInvalid_end();
   
   void getRow_invalid();
   void getCol_invalid();
   void isValid_invalid();
   void isInvalid_invalid();
   
   void getRow_rowInvalid();
   void getCol_rowInvalid();
   void isValid_rowInvalid();
   void isInvalid_rowInvalid();
   void getRow_colInvalid();
   void getCol_colInvalid();
   void isValid_colInvalid();
   void isInvalid_colInvalid();

   void set_col();
   void set_row();
   void set_both();
   void set_text();
   void set_string();
   void set_copy();

   void adjust_addColumn();
   void adjust_addRow();
   void adjust_offRight();
   void adjust_offTop();
   void adjust_offLeft();
   void adjust_offBottom();
   void adjust_invalid();

   void equal_not();
   void equal_equals();
   void lessthan_lessthan();
   void lessthan_equals();
   void lessthan_greaterthan();
};
