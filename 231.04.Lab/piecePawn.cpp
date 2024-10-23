/***********************************************************************
 * Source File:
 *    PAWN
 * Author:
 *    Jacob Mower, Connor Hopkins, Angelo Arellano
 * Summary:
 *    The pawn class
 ************************************************************************/

#include "piecePawn.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

const int MOVES_SIZE = 2;

const Delta DIAGONAL_MOVES_BOTTOM[MOVES_SIZE] = { {-1, -1}, {-1, 1} };

const Delta DIAGONAL_MOVES_TOP[MOVES_SIZE]    = { {1, -1} , {1, 1}  };

const Delta VERTICAL_MOVE_BOTTOM = {-1, 0}; // 

const Delta VERTICAL_MOVE_TOP    = {1, 0 }; // 

 /***************************************************
 * PIECE DRAW
 * Draw the piece.
 ***************************************************/
void Pawn::display(ogstream* pgout) const
{
   pgout->drawPawn(position, !fWhite);
}

/**********************************************
 * PAWN : GET MOVES
 * Gets possible moves based on current location
 *********************************************/
void Pawn::getMoves(set <Move>& moves, const Board& board) const
{
  this->getMovesVertical(moves, board );
  this->getMovesDiagonal(moves, board );
  this->getMovesEnpassant(moves, board);
}

/**********************************************
 * PAWN : GET MOVES VERTICAL
 * Gets possible vertical moves based on current location
 *********************************************/
void Pawn::getMovesVertical(set <Move>& moves, const Board& board) const 
{
   const Delta defaultMove = fWhite ? VERTICAL_MOVE_TOP : VERTICAL_MOVE_BOTTOM;
   Position possibleDest(position, defaultMove);
   if (possibleDest.isValid())
   {
      // If it is a valid position we get the piece to see if it is a space
      const Piece& pieceInDest = board[possibleDest];
      if (pieceInDest == SPACE)
      { 
         // Advance one
         Move move(position, possibleDest, fWhite);
         if (canPromote(possibleDest.getRow()))
            move.setPromotion(QUEEN);
         moves.insert(move);

         // trying to jump, we must not have moved and the path must be clear
         if (nMoves == 0) 
         {
            // We want to jump to rows (either up or down)
            int jumpRow = defaultMove.dRow + defaultMove.dRow;

            // Create the landing postion
            Position jumpPosition(position, {jumpRow, 0});

            // Add the move
            moves.insert(Move(position, jumpPosition, fWhite));
            // nMoves --;
         }
      }
   }
}

/**********************************************
 * PAWN : GET MOVES DIAGONAL
 * Gets possible diagonal moves based on current location
 *********************************************/
void Pawn::getMovesDiagonal(set <Move>& moves, const Board& board) const 
{
   const Delta* defaultMoves = fWhite ? DIAGONAL_MOVES_TOP : DIAGONAL_MOVES_BOTTOM;
   for (int i = 0; i < MOVES_SIZE; i++)
   {
      Position possibleDest(position, defaultMoves[i]);
      if (possibleDest.isValid())
      {
         // If it is a valid position we get the piece to see if it is an opposite piece
         const Piece& pieceInDest = board[possibleDest];
         if (pieceInDest != SPACE && pieceInDest.isWhite() != fWhite)
         {
            Move move(position,
               possibleDest,
               fWhite,
               pieceInDest.getType());
            if(canPromote(possibleDest.getRow()))
               move.setPromotion(QUEEN);
            moves.insert(move);
         }
      }
   }
}

/**********************************************
 * PAWN : GET MOVES
 * Gets possible enpassant moves based on current location
 *********************************************/
void Pawn::getMovesEnpassant(set <Move>& moves, const Board& board) const 
{
   const Delta* defaultMoves = fWhite ? DIAGONAL_MOVES_TOP : DIAGONAL_MOVES_BOTTOM;
   for (int i = 0; i < MOVES_SIZE; i++)
   {
      Position possibleDest(position, defaultMoves[i]);
      if (possibleDest.isValid())
      {
         const Piece& pieceInDest = board[possibleDest];
         // Get the positions on the left and right to see if we can enpassant
         Position sidePosition(position, { 0, defaultMoves[i].dCol});
         // If we are not in the edge of the board
         if (sidePosition.isValid() && pieceInDest == SPACE)
         {
            // We check if the piece in the right is an opposite color pawn that just moved
            const Piece& sidePiece   = board[sidePosition];
            if (sidePiece           == PAWN &&
                sidePiece.isWhite() != fWhite &&
                sidePiece.justMoved(board.getCurrentMove()) &&
                sidePiece.getNMoves() == 1)
            {
               // Create an enpassant move
               Move move(position, possibleDest, fWhite);
               move.setEnpassant();
               moves.insert(move);
            }
         }
      }
   }
};

bool Pawn::canPromote(int destinationRow) const 
{
   if (fWhite == true && destinationRow == 7)
      return true;
   if(fWhite == false && destinationRow == 0) 
      return true;

   return false;
}