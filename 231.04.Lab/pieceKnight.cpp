/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    Jacob Mower, Angelo Arellano, Connor Hopkins
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
   pgout -> drawKnight(position, fWhite);
}

/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   int r = this->position.getRow();
   int c = this->position.getCol();
   
   // To help keep defaultMoves visually tight,
   // variables names (primarySecondary) are as follows:
   //    - Primary direction   = 3 squares
   //    - Secondary direction = 1 square
   Position upLeft    = Position(c - 1, r + 2);
   Position upRight   = Position(c + 1, r + 2);
   Position leftUp    = Position(c - 2, r + 1);
   Position leftDown  = Position(c - 2, r - 1);
   Position rightUp   = Position(c + 2, r + 1);
   Position rightDown = Position(c + 2, r - 1);
   Position downLeft  = Position(c - 1, r - 2);
   Position downRight = Position(c + 1, r - 2);

   Position defaultMoves[8] = {
                           upLeft, upRight,
                  leftUp,                   rightUp,
                leftDown,                   rightDown,
                         downLeft, downRight
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
            Move move(currentPositionCopy, possibleDestination,
                      this->isWhite(), pieceInDestination.getType());
            moves.insert(move);
         }
      }
   }
}
