/***********************************************************************
 * Header File:
 *    Queen
 * Author:
*    Jacob Mower, Connor Hopkins, Angelo Arellano Gaona
 * Summary:
 *    The QUEEN class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * QUEEN
  * The queen, aka the "I move wherever I want"
  ***************************************************/
class Queen : public Piece
{
public:
   Queen(const Position& pos, bool isWhite) : Piece(pos, isWhite)  {}
   Queen(int c, int r, bool isWhite)        : Piece(c, r, isWhite) {}
   ~Queen() {}
   PieceType getType()              const { return QUEEN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)    const;
};
