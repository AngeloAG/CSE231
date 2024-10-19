/***********************************************************************
 * Source File:
 *    BISHOP
 * Author:
 *    Jacob Mower, Connor Hopkins, Angelo Arellano
 * Summary:
 *    The bishop class
 ************************************************************************/

#include "pieceBishop.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw the piece.
 ***************************************************/
void Bishop::display(ogstream* pgout) const
{
   pgout->drawBishop(position, fWhite);
}


/**********************************************
 * Bishop : GET MOVES
 * Gets possible moves based on current location
 *********************************************/
void Bishop::getMoves(set <Move>& moves, const Board& board) const
{
   Delta defaultMoves[4] = {
      {1, -1},    {1, 1},

      {-1, -1},   {-1, 1},
   };
   this->getMovesSlide(moves, board, defaultMoves, 4);
}
