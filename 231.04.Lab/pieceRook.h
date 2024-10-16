/***********************************************************************
 * Header File:
 *    Rook
 * Author:
*    Jacob Mower, Angelo Arellano
 * Summary:
 *    The BISHOP class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * BISHOP
  * The BISHOP, aka the "diagonal guy"
  ***************************************************/
class Rook : public Piece
{
public:
   Rook(const Position& pos, bool isWhite) : Piece(pos, isWhite) {}
   Rook(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~Rook() {}
   PieceType getType()            const { return ROOK; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};
