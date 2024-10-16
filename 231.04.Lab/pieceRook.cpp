
/***********************************************************************
 * Source File:
 *    Rook
 * Author:
 *    Jacob Mower, Angelo Arellano
 * Summary:
 *    The bishop class
 ************************************************************************/

#include "pieceRook.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Rook::display(ogstream* pgout) const
{
   pgout->drawQueen(position, fWhite);
}


/**********************************************
 * Rook : GET POSITIONS
 *********************************************/
void Rook::getMoves(set <Move>& moves, const Board& board) const
{
   int r = this->position.getRow();
   int c = this->position.getCol();

   Position defaultMoves[4] = {
                              Position(c, r + 1),
      Position(c - 1, r),                          Position(c + 1, r),
                              Position(c, r - 1),
   };
   this->getMovesSlide(moves, board, defaultMoves, 4);
}
