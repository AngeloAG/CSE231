/***********************************************************************
 * Source File:
 *    King
 * Author:
 *    Jacob Mower, Angelo Arellano, Connor Hopkins
 * Summary:
 *    The king class
 ************************************************************************/

#include "pieceKing.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw the pieces.
 ***************************************************/
void King::display(ogstream* pgout) const
{
   pgout->drawKing(position, fWhite);
}


/**********************************************
 * KING : GET MOVES
 *********************************************/
void King::getMoves(set <Move>& moves, const Board& board) const
{
   int r = this->position.getRow();
   int c = this->position.getCol();

   Position defaultMoves[8] = {
      Position(c - 1, r + 1), Position(c, r + 1),  Position(c + 1, r + 1),
      Position(c - 1, r),                          Position(c + 1, r),
      Position(c - 1, r - 1), Position(c, r - 1),  Position(c + 1, r - 1),
   };
   this->getMovesNoSlide(moves, board, defaultMoves, 8);
   this->kingSideCastle (moves, board);
   this->queenSideCastle(moves, board);
}

/**********************************************
 * KING : KING SIDE CASTLE
 * Perform a castle move on the king's side.
 *********************************************/
void King::kingSideCastle(set <Move>& moves, const Board& board) const
{
   const Position rightCorner(position, {0,3});
   const Position destination(position, {0,2});

   if (canCastle(board, rightCorner))
   {
      Move move(position, destination, fWhite, INVALID);
      move.setCastle(true);
      moves.insert(move);
   }
}

/**********************************************
 * KING : QUEEN SIDE CASTLE
  * Perform a castle move on the queen's side.
 *********************************************/
void King::queenSideCastle(set <Move>& moves, const Board& board) const
{
   const Position leftCorner(position, { 0,-4});
   const Position destination(position,{ 0,-2});

   if (canCastle(board, leftCorner))
   {
      Move move(position, destination, fWhite, INVALID);
      move.setCastle(false);
      moves.insert(move);
   }
}

/**********************************************
 * KING : CAN CASTLE
 * Verify that the king and rook can castle.
 *********************************************/
bool King::canCastle(const Board& board, const Position & corner) const
{
   // Verify neither the king nor the rook has moved yet
   if (nMoves != 0)
      return false;

   // Check the rook's position
   if (corner.isInvalid())
      return false;

   // Make sure it's a rook
   if (board[corner].getType() != ROOK && board[corner].getNMoves() != 0)
      return false;

   // Check if queenside is empty
   if (position.getCol() > corner.getCol())
   {
      int difference = position.getCol() - corner.getCol();
      for (int i = difference - 1; i > 0; i--)
      {
         if (board[Position (position, {0,-i})] != SPACE)
            return false;
         else
            return true;
      }
   }

   // Check if kingside is empty
   if (position.getCol() < corner.getCol())
   {
      int difference = corner.getCol() - position.getCol();
      for (int i = 1; i < difference; i++)
      {
         if (board[Position(position, { 0,i})] != SPACE)
            return false;
         else
            return true;
      }
   }
   return false;
}
