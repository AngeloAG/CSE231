
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

   Delta defaultMoves[4] = {
              {1, 0},
      {0, -1},       {0, 1},
              {-1,0},
   };
   this->getMovesSlide(moves, board, defaultMoves, 4);
}
