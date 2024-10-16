#pragma once

#include "piece.h"

/***************************************************
 * BISHOP
 * The BISHOP, aka the "diagonal guy"
 ***************************************************/
class King : public Piece
{
public:
   King(const Position& pos, bool isWhite) : Piece(pos, isWhite) {}
   King(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~King() {}
   PieceType getType()            const { return KING; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};