/***********************************************************************
 * Source File:
 *    King
 * Author:
 *    Jacob Mower, Connor, Angelo Arellano
 * Summary:
 *    The king class
 ************************************************************************/

#include "pieceKing.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw piece.
 ***************************************************/
void King::display(ogstream* pgout) const
{
   pgout->drawKing(position, fWhite);
}


/**********************************************
 * Bishop : GET POSITIONS
 *********************************************/
void King::getMoves(set <Move>& moves, const Board& board) const
{
   Delta defaultMoves[8] = {
      {- 1, 1}, {0, 1},  {1, 1},
      {- 1, 0},          {1, 0},
      {- 1,-1}, {0,-1},  {1,-1},
   };
   this->getMovesNoSlide(moves, board, defaultMoves, 8);
   this->kingSideCastle(moves, board);
   this->queenSideCastle(moves, board);
}

/**********************************************
 * King: KING SIDE CASTLE
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
 * King: QUEEN SIDE CASTLE
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
 * King: CAN CASTLE
 *********************************************/
bool King::canCastle(const Board& board, const Position & corner) const
{
   // Verify neither the king nor the rook has moved yet
   if (nMoves != 0)
      return false;

   // Check the rook's position
   if (corner.isInvalid())
      return false;

   // Make sure it's a rook and that is hasn't moved
   if (board[corner].getType() != ROOK || board[corner].getNMoves() != 0)
      return false;

   // If the corner is the right side one 
   // Check if path on queenside is empty
   if (position.getCol() > corner.getCol())
   {
      int difference = position.getCol() - corner.getCol();
      // Check square by square between king and left corner
      for (int i = difference - 1; i > 0; i--) // Make sure they are all spaces
      {
         if (board[Position (position, {0,-i})] != SPACE)
            return false;
         else
            return true;
      }
   }

   // If the corner is the left side one 
   // Check if path on queenside is empty
   if (position.getCol() < corner.getCol())
   {
      int difference = corner.getCol() - position.getCol();
      // Check square by square between king and right corner
      for (int i = 1; i < difference; i++) // Make sure they are all spaces
      {
         if (board[Position(position, { 0,i})] != SPACE)
            return false;
         else
            return true;
      }
   }
   return false;
}
