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
Move::Move()
{
   Position dest;
   Position source;
   text = "";
}

Move::Move(const char * s)
{
   source.set(s[0], s[1]);
   dest.set(s[2], s[3]);
   moveType = MOVE;
   text = s;
}

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
