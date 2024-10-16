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

   Position defaultMoves[8] = {
      Position(c - 1, r + 1), Position(c, r + 1),  Position(c + 1, r + 1),
      Position(c - 1, r),                          Position(c + 1, r),
      Position(c - 1, r - 1), Position(c, r - 1),  Position(c + 1, r - 1),
   };
   this->getMovesSlide(moves, board, defaultMoves, 8);
}
