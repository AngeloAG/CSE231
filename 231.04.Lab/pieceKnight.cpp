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
   pgout->drawKnight(position, fWhite);
}

/**********************************************
 * KNIGHT : GET MOVES
 * Gets possible moves based on current location
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   int r = this->position.getRow();
   int c = this->position.getCol();
   
   Position defaultMoves[8] = {
                         Position(c - 1, r + 2), Position(c + 1, r + 2),
   Position(c - 2, r + 1),                                             Position(c + 2, r + 1),
   Position(c - 2, r - 1),                                             Position(c + 2, r - 1),
                         Position(c - 1, r - 2), Position(c + 1, r - 2)
   };

   Position currentPositionCopy(position);
   for (int i = 0; i < 8; i++)
   {
      Position possibleDestination = defaultMoves[i];
      if (possibleDestination.isValid()){
         const Piece& pieceInDestination = board[possibleDestination];
         if (pieceInDestination.getType() == SPACE)
         {
            Move move(currentPositionCopy, possibleDestination, this->isWhite());
            moves.insert(move);
         }
         else if (pieceInDestination.isWhite() != this->fWhite)
         {
            Move move(currentPositionCopy, possibleDestination, this->isWhite(), pieceInDestination.getType());
            moves.insert(move);
         }
      }
   }
}
