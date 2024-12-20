/***********************************************************************
 * Header File:
 *    MOVE
 * Author:
 *    Jacob Mower, Connor Hopkins, Angelo Arellano Gaona
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
   Move(Position source,Position dest,bool isWhite,PieceType capture = INVALID);
   bool operator == (const Move & rhs) const  { return rhs.text == this->text;  }
   bool operator != (const Move & rhs) const  { return rhs.text != this->text;  }
   bool operator <  (const Move & rhs) const  { return dest.getLocation() 
                                                < rhs.dest.getLocation(); }
   const Move & operator = (const char * rhs) { read(string(rhs)); return *this;}
   Move & operator = (const Move & rhs);

   string getText() const;
   const Position& getSource() const { return source;  }
   const Position& getDest()   const { return dest;    }
   PieceType getCapture()      const { return capture; }
   PieceType getPromote()      const { return promote; }

   void setCastle(bool isKingSide)
   { moveType = isKingSide ? CASTLE_KING : CASTLE_QUEEN; text = getText(); }

   void setEnpassant() {moveType = ENPASSANT;  text = getText(); capture = PAWN;}
   void setPromotion(PieceType promote) { this->promote = promote; text += 'Q'; }
   bool isEnPassant()     const { return moveType == ENPASSANT;    }
   bool isCastleK()       const { return moveType == CASTLE_KING;  }
   bool isCastleQ()       const { return moveType == CASTLE_QUEEN; }
   bool isWhiteTurn()     const { return isWhite;                  }

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


