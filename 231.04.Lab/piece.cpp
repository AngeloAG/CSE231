/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    Jacob Mower, Angelo Arellano
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;


/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{
   this->position = rhs.position;
   this->nMoves   = rhs.nMoves  ;
   this->lastMove = rhs.lastMove;
   this->fWhite   = rhs.fWhite  ;
   return *this;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}

/************************************************
 * PIECE : GET MOVES NO SLIDE
 * Iterate through the moves decorator to allow a piece to move no sliding
 ***********************************************/
void Piece::getMovesNoSlide(set <Move>& movesSet, const Board& board) const
{
}

/************************************************
 * PIECE : GET MOVES Sliding
 * Iterate through the moves decorator to allow a piece to move slide
 ***********************************************/
void Piece::getMovesSlide(set <Move>& movesSet, const Board& board, const Position* directions, int amountOfDirections) const
{
   Position currentPositionCopy(position);
   for (int i = 0; i < amountOfDirections; i++)
   {
      Position possibleDestination = directions[i];
      bool canCapture = false;
      while (possibleDestination.isValid() && (board[possibleDestination].isWhite() != fWhite || board[possibleDestination].getType() == SPACE))
      {
         const Piece& pieceInDest = board[possibleDestination];
         if (pieceInDest.getType() == SPACE)
         {
            Move move(currentPositionCopy, possibleDestination, this->isWhite());
            movesSet.insert(move);
         }
         else if (pieceInDest.isWhite() != this->fWhite)
         {
            Move move(currentPositionCopy, possibleDestination, this->isWhite(), pieceInDest.getType());
            movesSet.insert(move);
            canCapture = true;
         }

         // If the destination col is greater that means we are moving to the right
         if (currentPositionCopy.getCol() < possibleDestination.getCol())
            possibleDestination.adjustCol(1);
         else if (currentPositionCopy.getCol() > possibleDestination.getCol())
            possibleDestination.adjustCol(-1);

         // If the destination row is greater that means we are moving to the up
         if (currentPositionCopy.getRow() < possibleDestination.getRow())
            possibleDestination.adjustRow(1);
         else if (currentPositionCopy.getRow() > possibleDestination.getRow())
            possibleDestination.adjustRow(-1);

         if(canCapture)
            break;
      }
   }
}

bool Piece::justMoved(int currentMove) const
{
   return lastMove + 1 == currentMove;
}
