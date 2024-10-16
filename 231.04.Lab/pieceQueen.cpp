/***********************************************************************
 * Source File:
 *    Queen
 * Author:
 *    Jacob Mower, Angelo Arellano
 * Summary:
 *    The bishop class
 ************************************************************************/

#include "pieceQueen.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Queen::display(ogstream* pgout) const
{
   pgout->drawQueen(position, fWhite);
}


/**********************************************
 * Bishop : GET POSITIONS
 *********************************************/
void Queen::getMoves(set <Move>& moves, const Board& board) const
{
   int r = this->position.getRow();
   int c = this->position.getCol();

   Position defaultMoves[8] = {
      Position(c - 1, r + 1), Position(c, r + 1),  Position(c + 1, r + 1),
      Position(c - 1, r),                          Position(c + 1, r),
      Position(c - 1, r - 1), Position(c, r - 1),  Position(c + 1, r - 1),
   };
   this->getMovesSlide(moves, board, defaultMoves, 8);
}
