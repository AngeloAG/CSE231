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
 * King : GET MOVES
 * Gets possible moves based on current location
 *********************************************/
void King::getMoves(set <Move>& moves, const Board& board) const
{
   Delta defaultMoves[8] = {
      {- 1, 1}, {0, 1},  {1, 1},
      {- 1, 0},          {1, 0},
      {- 1,-1}, {0,-1},  {1,-1},
   };
   this->getMovesNoSlide(moves, board, defaultMoves, 8); //get normal moves
   this->kingSideCastle(moves, board); // get possible castling in king side
   this->queenSideCastle(moves, board); // get possible castling in queen side
}

/**********************************************
 * King: KING SIDE CASTLE
 * If castling is possible in the king's side, get the move
 *********************************************/
void King::kingSideCastle(set <Move>& moves, const Board& board) const
{
   const Position rightCorner(position, {0,3}); //King side corner
   const Position destination(position, {0,2}); //Where the king lands
   if (canCastle(board, rightCorner))
   {
      Move move(position, destination, fWhite, INVALID);
      move.setCastle(true);
      moves.insert(move);
   }
}

/**********************************************
 * King: QUEEN SIDE CASTLE
 * If castling is possible in the queen's side, get the move
 *********************************************/
void King::queenSideCastle(set <Move>& moves, const Board& board) const
{
   const Position leftCorner(position, { 0,-4}); //Queen side corner
   const Position destination(position,{ 0,-2}); //Where the king lands
   if (canCastle(board, leftCorner))
   {
      Move move(position, destination, fWhite, INVALID);
      move.setCastle(false);
      moves.insert(move);
   }
}

/**********************************************
 * King: CAN CASTLE
 * Returns true if the king can castle to the specified corner
 *********************************************/
bool King::canCastle(const Board& board, const Position & corner) const
{
   // Verify neither the king nor the rook has moved yet
   if (nMoves != 0)
      return false;

   // Check Rooks position
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
