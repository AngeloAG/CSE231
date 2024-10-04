/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move(): source(), dest(), promote(INVALID), capture(INVALID), moveType(MOVE), text(""), isWhite(true) {}

Move::Move(const char* s)
{
   char sourceChars[2];
   char destChars[2];

   sourceChars[0] = s[0];
   sourceChars[1] = s[1];
   destChars[0] = s[2];
   destChars[1] = s[3];

   source = Position(sourceChars);
   dest = Position(destChars);
   capture = INVALID;
   promote = INVALID;
   isWhite = true;
   moveType = MOVE;
   text = s;
}



