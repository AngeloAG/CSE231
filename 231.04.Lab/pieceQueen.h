/***********************************************************************
 * Header File:
 *    Queen
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
class Queen : public Piece
{
public:
   Queen(const Position& pos, bool isWhite) : Piece(pos, isWhite) {}
   Queen(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~Queen() {}
   PieceType getType()            const { return QUEEN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};
