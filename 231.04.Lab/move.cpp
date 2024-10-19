/***********************************************************************
 * Source File:
 *    MOVE
 * Author:
 *    Jacob Mower, Angelo Arellano Gaona
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
Move::Move(): source(), dest(), promote(INVALID),
              capture(INVALID), moveType(MOVE), text(""), isWhite(true) {}

/***************************************************
 * MOVE : CONSTRUCTOR FROM STRING
 ***************************************************/
Move::Move(const char * s): promote(INVALID), capture(INVALID),
                            moveType(MOVE), text(s), isWhite(true)
{
   read(string(s));
}

/***************************************************
 * MOVE : CONSTRUCTOR FROM OBJECTS
 ***************************************************/
Move::Move(const Position source, Position dest, bool isWhite, PieceType capture)
   : source(source), dest(dest), promote(INVALID), capture(capture), moveType(MOVE), isWhite(isWhite)
{
   this->text = this->getText();
}

/*************************************
 * ASSIGN OPERATOR FROM ANOTHER MOVE
 **************************************/
Move& Move::operator = (const Move & rhs)
{
   source   = rhs.source;
   dest     = rhs.dest;
   promote  = rhs.promote;
   capture  = rhs.capture;
   moveType = rhs.moveType;
   text     = rhs.text;
   isWhite  = rhs.isWhite;
   return *this;
}

/*************************************
 * LETTER FROM PIECE TYPE
 * Returns the character representation of a piece
 **************************************/
char Move::letterFromPieceType(PieceType pt) const
{
   switch (pt) {
      case PieceType::PAWN:
         return 'p';
      
      case PieceType::ROOK:
         return 'r';
      
      case PieceType::KING:
         return 'k';
         
      case PieceType::QUEEN:
         return 'q';
         
      case PieceType::SPACE:
         return ' ';
         
      case PieceType::BISHOP:
         return 'b';
         
      case PieceType::KNIGHT:
         return 'n';
         
      default:
         return 'i';
   }
}

/*************************************
 * PIECE TYPE FROM LETTER
 * Returns the PieceType that corresponds
 * to a given character
 **************************************/
PieceType Move::pieceTypeFromLetter(char letter) const
{
   switch (letter) {
      case 'p':
         return PieceType::PAWN;
      
      case 'r':
         return PieceType::ROOK;
      
      case 'k':
         return PieceType::KING;
         
      case 'q':
         return PieceType::QUEEN;
         
      case ' ':
         return PieceType::SPACE;
         
      case 'b':
         return PieceType::BISHOP;
         
      case 'n':
         return PieceType::KNIGHT;
         
      default:
         return PieceType::INVALID;
   }
}

/*************************************
 * READ
 * Translates a smith notation move
 * into aan actual move
 **************************************/
void Move::read(const string smithMove)
{
   char sourceChars[2];
   char destChars[2];

   sourceChars[0] = smithMove[0];
   sourceChars[1] = smithMove[1];
   destChars[0]   = smithMove[2];
   destChars[1]   = smithMove[3];

   source = Position(sourceChars);
   dest   = Position(destChars);

   // If there's a fifth character
   // that means we have to consider
   // a special move
   if (smithMove.size() > 4)
   {
      switch (smithMove[4])
      {
         case 'E':
            moveType = ENPASSANT;
            capture = PAWN;
            break;
         case 'C':
            moveType = CASTLE_QUEEN;
            break;
         case 'c':
            moveType = CASTLE_KING;
            break;
         default:
            moveType = MOVE;
            capture = pieceTypeFromLetter(smithMove[4]);
            break;
         }
   }

   text = smithMove;
}

/*************************************
 * GET TEXT
 * Translates move into it's smith notation
 * representation
 **************************************/
string Move::getText() const
{
   string smithNotation;
   smithNotation += source.getCol() + 'a';
   smithNotation += source.getRow() + '1';
   smithNotation += dest.getCol()   + 'a';
   smithNotation += dest.getRow()   + '1';

   switch (moveType) {
      case ENPASSANT:
         return smithNotation += 'E';
      case CASTLE_QUEEN:
         return smithNotation += 'C';
      case CASTLE_KING:
         return smithNotation += 'c';
      default:
         break;
   }

   if (capture != INVALID && capture != SPACE)
   {
      return smithNotation += letterFromPieceType(capture);
   };

   return smithNotation;
}
