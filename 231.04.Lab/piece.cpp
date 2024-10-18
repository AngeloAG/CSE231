/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    Jacob Mower, Connor, Angelo Arellano
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
void Piece::getMovesNoSlide(set <Move>& movesSet, const Board& board, 
                            const Delta deltas[], int deltasSize) const
{
   // We iterate though each of the deltas
   // to check if we can move there
   for (int i = 0; i < deltasSize; i++)
   {
      Position possibleDest(position, deltas[i]);
      if (possibleDest.isValid())
      {
         // If it is a valid position we get the piece 
         // and check if it is a space or if we can capture it
         const Piece& pieceInDest = board[possibleDest];
         if (pieceInDest.isWhite() != fWhite || pieceInDest == SPACE)
         {
            // We create the simple move or capture move
            if(pieceInDest != SPACE)
               movesSet.insert(Move(position, 
                                    possibleDest, 
                                    fWhite, 
                                    pieceInDest.getType()));
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
void Piece::getMovesSlide(set <Move>& movesSet, const Board& board, 
                          const Delta deltas[], int deltasSize) const
{
   // We iterate though each of the deltas
   // to check if we can move there
   for (int i = 0; i < deltasSize; i++)
   {
      Delta currentDelta = deltas[i];
      // We will keep sliding with the delta until we reach
      // the end of the board or a piece we cannot capture
      bool keepSliding = true;
      while (keepSliding)
      {
         Position possibleDest(position, currentDelta);
         if (possibleDest.isValid())
         {
            // If it is a valid position we get the piece 
            // and check if it is a space or if we can capture it
            const Piece& pieceInDest = board[possibleDest];
            if (pieceInDest.isWhite() != fWhite || pieceInDest == SPACE)
            {
               // We create the simple move or capture move
               if (pieceInDest != SPACE)
               {
                  movesSet.insert(Move(position, 
                                       possibleDest, 
                                       fWhite, 
                                       pieceInDest.getType()));
                  keepSliding = false; //We cannot move past a capture
               }
               else
                  movesSet.insert(Move(position, possibleDest, fWhite));
            } 
            else 
               keepSliding = false;
         }
         else
            keepSliding = false;

         // This moves the delta to keep sliding
         currentDelta.dCol += deltas[i].dCol;
         currentDelta.dRow += deltas[i].dRow;
      }
   }
}

/************************************************
 * PIECE : JUST MOVED
 * Check if the piece moved in the last turn
 ***********************************************/
bool Piece::justMoved(int currentMove) const
{
   return lastMove + 1 == currentMove;
}
