/***********************************************************************
 * Header File:
 *    PAWN
 * Author:
*    Jacob Mower, Angelo Arellano
 * Summary:
 *    The Pawn class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * PAWN
  * The pawn, aka the "complicated guy"
  ***************************************************/
class Pawn : public Piece
{
public:
   Pawn(const Position& pos, bool isWhite) : Piece(pos, isWhite) {}
   Pawn(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~Pawn() {}
   PieceType getType()            const { return PAWN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
private:
   void getMovesDiagonal(set <Move>& moves, const Board& board) const;
   void getMovesVertical(set <Move>& moves, const Board& board) const;
   void getMovesEnpassant(set <Move>& moves, const Board& board) const;
   bool canPromote(int destinationRow) const;
};
