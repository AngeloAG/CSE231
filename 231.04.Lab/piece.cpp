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
void Piece::getMovesNoSlide(set <Move>& movesSet, const Board& board, const Delta deltas[], int deltasSize) const
{
   for (int i = 0; i < deltasSize; i++)
   {
      Position possibleDest(position, deltas[i]);
      if (possibleDest.isValid())
      {
         const Piece& pieceInDest = board[possibleDest];
         if (pieceInDest.isWhite() != fWhite || pieceInDest == SPACE)
         {
            if(pieceInDest != SPACE)
               movesSet.insert(Move(position, possibleDest, fWhite, pieceInDest.getType()));
            else
               movesSet.insert(Move(position, possibleDest, fWhite));
         }
      }
   }
}

/************************************************
 * PIECE : GET MOVES Sliding
 * Iterate through the moves decorator to allow a piece to move slide
 ***********************************************/
void Piece::getMovesSlide(set <Move>& movesSet, const Board& board, const Delta deltas[], int deltasSize) const
{
   for (int i = 0; i < deltasSize; i++)
   {
      Delta currentDelta = deltas[i];
      bool keepSliding = true;
      while (keepSliding)
      {
         Position possibleDest(position, currentDelta);
         if (possibleDest.isValid())
         {
            const Piece& pieceInDest = board[possibleDest];
            if (pieceInDest.isWhite() != fWhite || pieceInDest == SPACE)
            {
               if (pieceInDest != SPACE)
               {
                  movesSet.insert(Move(position, possibleDest, fWhite, pieceInDest.getType()));
                  keepSliding = false;
               }
               else
                  movesSet.insert(Move(position, possibleDest, fWhite));
            } 
            else 
               keepSliding = false;
         }
         else
            keepSliding = false;
;
         currentDelta.dCol += deltas[i].dCol;
         currentDelta.dRow += deltas[i].dRow;
      }
   }
}

bool Piece::justMoved(int currentMove) const
{
   return lastMove + 1 == currentMove;
}
