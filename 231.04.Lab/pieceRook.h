/***********************************************************************
 * Header File:
 *    Rook
 * Author:
*    Jacob Mower, Angelo Arellano
 * Summary:
 *    The ROOK class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * OK
  * The Rook, aka the "best piece"
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
