/***********************************************************************
 * Header File:
 *    KNIGHT
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
class Bishop : public Piece
{
public:
   Bishop(const Position& pos, bool isWhite) : Piece(pos, isWhite) {}
   Bishop(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~Bishop() {}
   PieceType getType()            const { return BISHOP; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};
