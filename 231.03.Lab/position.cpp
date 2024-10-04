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

/*************************************
 * ASSIGN OPERATOR FROM STRING
 **************************************/
Position& Position::operator = (const string& rhs) 
{
   set(rhs[0] - 'a', rhs[1] - '1');
   return *this;
}

/*************************************
 * ADD AND ASSIGN OPERATOR FROM DELTA
 **************************************/
Position& Position::operator += (const Delta& rhs)
{
   if (isValid())
   {
      adjustCol(rhs.dCol);
      adjustRow(rhs.dRow);
   }
   return *this;
}

/*************************************
 * ADD OPERATOR FROM DELTA
 **************************************/
Position Position::operator + (const Delta & rhs) const
{
   Position newPos(*this);
   newPos += rhs;
   return newPos;
}

/*************************************
 * GET COL
 * Returns if the current position is valid 
 * the column is returned 0 - 7, otherwise -1
 **************************************/
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

/*************************************
 * GET ROw
 * Returns if the current position is valid
 * the row is returned 0 - 7, otherwise -1
 **************************************/
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

/*************************************
 * ADJUST ROW
 * Moves the current position the 
 * provided amount of rows. If it gets
 * off the board, it is set to the invalid
 * location
 **************************************/
void Position::adjustRow(int dRow)
{
   int newRow = getRow() + dRow;
   if (newRow > 0 && newRow < 8)
      colRow += dRow;
   else
      colRow = 0xff;
}

/*************************************
 * ADJUST COL
 * Moves the current position the
 * provided amount of columns. If it gets
 * off the board, it is set to the invalid
 * location
 **************************************/
void Position::adjustCol(int dCol)
{
   int newCol = getCol() + dCol;
   if (newCol > 0 && newCol < 8)
      colRow += dCol * 16;
   else
      colRow = 0xff;
}