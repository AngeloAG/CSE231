
/***********************************************************************
 * Source File:
 *    Rook
 * Author:
 *    Jacob Mower, Connor Hopkins, Angelo Arellano
 * Summary:
 *    The rook class
 ************************************************************************/

#include "pieceRook.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw the piece.
 ***************************************************/
void Rook::display(ogstream* pgout) const
{
   pgout->drawRook(position, fWhite);
}

/**********************************************
 * Rook : GET MOVES
 * Gets possible moves based on current location
 *********************************************/
void Rook::getMoves(set <Move>& moves, const Board& board) const
{
   Delta defaultMoves[4] = {
              {1, 0},
      {0, -1},       {0, 1},
              {-1,0},
   };
   this->getMovesSlide(moves, board, defaultMoves, 4);
}
