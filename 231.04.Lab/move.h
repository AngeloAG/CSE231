/***********************************************************************
 * Header File:
 *    MOVE
 * Author:
 *    Jacob Mower, Angelo Arellano Gaona
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
public:
   enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

   friend TestMove;
   friend TestBoard;

   // constructor
   Move();
   Move(const char * s);
   Move(Position source, Position dest, bool isWhite, PieceType capture = INVALID, MoveType type = MOVE, PieceType promote = INVALID);
   bool operator == (const Move & rhs) const  { return rhs.text == this->text;    }
   bool operator != (const Move & rhs) const  { return rhs.text != this->text;    }
   bool operator <  (const Move & rhs) const  { return dest.getLocation() < rhs.dest.getLocation(); }
   const Move & operator = (const char * rhs) { read(string(rhs)); return *this; }
   Move & operator = (const Move & rhs);
   string getText() const;

private:
   char letterFromPieceType(PieceType pt)     const;
   PieceType pieceTypeFromLetter(char letter) const;
   void read(const string smithMove);



   Position  source;    // where the move originated from
   Position  dest;      // where the move finished
   PieceType promote;   // piece to be promoted to
   PieceType capture;   // did a capture happen this move?
   MoveType  moveType;  // what type of move is this?
   bool      isWhite;   // whose turn is it anyway?
   string    text;      // what is the textual version of the move?
};


