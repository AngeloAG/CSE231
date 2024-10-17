/***********************************************************************
 * Source File:
 *    BISHOP
 * Author:
 *    Jacob Mower, Angelo Arellano
 * Summary:
 *    The bishop class
 ************************************************************************/

#include "pieceBishop.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Bishop::display(ogstream* pgout) const
{
   pgout->drawKnight(position, fWhite);
}


/**********************************************
 * Bishop : GET POSITIONS
 *********************************************/
void Bishop::getMoves(set <Move>& moves, const Board& board) const
{
   int r = this->position.getRow();
   int c = this->position.getCol();

   Delta defaultMoves[4] = {
      {1, -1},    {1, 1},

      {-1, -1},   {-1, 1},
   };
   this->getMovesSlide(moves, board, defaultMoves, 4);
}
