/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    Jacob Mower, Angelo Arellano
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;


/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{
   this->position = rhs.position;
   this->nMoves   = rhs.nMoves  ;
   this->lastMove = rhs.lastMove;
   this->fWhite   = rhs.fWhite  ;
   return *this;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}

/************************************************
 * PIECE : GET MOVES NO SLIDE
 * Iterate through the moves decorator to allow a piece to move no sliding
 ***********************************************/
void Piece::getMovesNoSlide(set <Move>& movesSet, const Board& board) const
{
}

/************************************************
 * PIECE : GET MOVES Sliding
 * Iterate through the moves decorator to allow a piece to move slide
 ***********************************************/
void Piece::getMovesSlide(set <Move>& movesSet, const Board& board) const
{
}

bool Piece::justMoved(int currentMove) const
{
   return lastMove + 1 == currentMove;
}
