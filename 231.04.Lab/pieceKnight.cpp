/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    Jacob Mower, Angelo Arellano
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   int r = position.getRow();
   int c = position.getCol();
   Position pos(c+1, r+2);
   if (
       board[pos].getType() == SPACE ||
       board[pos].isWhite() != this->fWhite
       ) {
          moves.insert(Move("{}"));
      }
}
