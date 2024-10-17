/***********************************************************************
 * Source File:
 *    King
 * Author:
 *    Jacob Mower, Angelo Arellano
 * Summary:
 *    The king class
 ************************************************************************/

#include "pieceKing.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw the pieces.
 ***************************************************/
void King::display(ogstream* pgout) const
{
   pgout->drawQueen(position, fWhite);
}


/**********************************************
 * Bishop : GET POSITIONS
 *********************************************/
void King::getMoves(set <Move>& moves, const Board& board) const
{
   int r = this->position.getRow();
   int c = this->position.getCol();

   Delta defaultMoves[8] = {
      {- 1, 1}, {0, 1},  {1, 1},
      {- 1, 0},          {1, 0},
      {- 1,-1}, {0,-1},  {1,-1},
   };
   this->getMovesNoSlide(moves, board, defaultMoves, 8);
}
