/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    Jacob Mower, Connor, Angelo Arellano
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw the piece.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{
   pgout->drawKnight(position, !fWhite);
}


/**********************************************
 * KNIGHT : GET MOVES
 * Gets possible moves based on current location
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   Delta defaultMoves[8] = { //Theoretical possible moves for knight
               { 2, -1}, { 2, 1},
      {1 , -2},                  { 1, 2},
      {-1, -2},                  {-1, 2},
               {-2, -1}, {-2, 1}
   };
   
   //Send those moves on
   this->getMovesNoSlide(moves, board, defaultMoves, 8);
}
