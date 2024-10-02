/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#include "position.h"
#include <iostream>

/******************************************
 * POSITION INSERTION OPERATOR
 ******************************************/
ostream & operator << (ostream & out, const Position & rhs)
{
   out << "error";
   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream & operator >> (istream & in,  Position & rhs)
{
   return in;   
}

int Position::getCol() const
{
   int col = (int)((colRow & 0xf0) >> 4);
   int row = (int)((colRow & 0x0f) >> 0);
   if (col < 8 && row < 8)
   {
      return col;
   }

   return -1;
}

int Position::getRow() const 
{ 
   int row = (int)((colRow & 0x0f) >> 0);
   int col = (int)((colRow & 0xf0) >> 4);
   if (row < 8 && col < 8)
   {
      return row;
   }

   return -1;
}