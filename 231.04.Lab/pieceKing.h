#pragma once

#include "piece.h"

/***************************************************
 * KING
 * The king, aka the "'go fight for me' guy"
 ***************************************************/
class King : public Piece
{
public:
   King(const Position& pos, bool isWhite) : Piece(pos, isWhite) {}
   King(int c, int r, bool isWhite)        : Piece(c, r, isWhite) {}
   ~King() {}
   PieceType getType()              const { return KING; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)    const;
   
private:
   void queenSideCastle(set <Move>& moves, const Board& board) const;
   void kingSideCastle(set <Move>& moves, const Board& board ) const;
   bool canCastle(const Board& board, const Position & corner) const;
};
