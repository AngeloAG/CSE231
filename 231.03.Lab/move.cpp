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
   source.set(s[0] - 'a', s[1] - '0');
   dest.set(s[2] - 'a', s[3] - '0');
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
         return ;
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

void Move::read(const string smithMove)
{
   source.set(smithMove[0], smithMove[1]);
   dest.set(smithMove[2], smithMove[3]);
   if (smithMove.size() > 4) 
   {
      smithMove[4];
   }
}


string Move::getText() const
{
   string smithNotation;
   int source1 = source.getCol();
   
   char firstChar = 'a';
   firstChar += source1;
   smithNotation += source.getCol() + 'a';
   smithNotation += source.getRow() + '0';
   smithNotation += dest.getCol() + 'a';
   smithNotation += dest.getRow() + '0';

   switch (moveType) {
      case ENPASSANT:
         return smithNotation += 'E';
      case CASTLE_QUEEN:
         return smithNotation += 'c';
      case CASTLE_KING:
         return smithNotation += 'C';
      default:
         break;
   }
   if (capture != INVALID || capture != SPACE)
   {
      return smithNotation += letterFromPieceType(capture);
   };
//   
//   smithNotation += source.getCol() + 'a';
//   return smithNotation += source.getCol() + 'a';
}
