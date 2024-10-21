/***********************************************************************
 * Source File:
 *    Queen
 * Author:
 *    Jacob Mower, Connor Hopkins, Angelo Arellano
 * Summary:
 *    The Queen class
 ************************************************************************/

#include "pieceQueen.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw the piece.
 ***************************************************/
void Queen::display(ogstream* pgout) const
{
   pgout->drawQueen(position, fWhite);
}

/**********************************************
 * Bishop : GET MOVES
 * Gets possible moves based on current location
 *********************************************/
void Queen::getMoves(set <Move>& moves, const Board& board) const
{
   Delta defaultMoves[8] = {
      {1, -1}, {1, 0},  {1, 1},
      {0, -1},          {0, 1},
      {-1,-1}, {-1,0},  {-1,1},
   };
   this->getMovesSlide(moves, board, defaultMoves, 8);
}
