/***********************************************************************
 * Source File:
 *    BISHOP
 * Author:
 *    Jacob Mower, Angelo Arellano, Connor Hopkins
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

   Position defaultMoves[4] = {
      Position(c - 1, r + 1),    Position(c + 1, r + 1),

      Position(c - 1, r - 1),    Position(c + 1, r - 1),
   };
   this->getMovesSlide(moves, board, defaultMoves, 4);
}
