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

   Delta defaultMoves[8] = {
      {1, -1}, {1, 0},  {1, 1},
      {0, -1},          {0, 1},
      {-1,-1}, {-1,0},  {-1,1},
   };
   this->getMovesSlide(moves, board, defaultMoves, 8);
}
