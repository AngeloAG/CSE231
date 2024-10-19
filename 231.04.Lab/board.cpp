/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *    Jacob Mower, Connor Hopkins, Angelo Arellano Gaona
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "pieceQueen.h"
#include "pieceRook.h"
#include "pieceBishop.h"
#include "piecePawn.h"
#include "pieceKing.h"
#include <cassert>
using namespace std;

/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
   if (fFree)
   {
      free();
   }
   else
   {
      setUpKnights();
      setUpSpaces();
      setUpPawns();
      setUpKings();
      setUpRooks();
      setUpQueens();
      setUpBishops();
   }

}

/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
   if (noreset) {
      for (int r = 0; r < 8; r++)
         for (int c = 0; c < 8; c++)
            board[c][r] = nullptr;
   }
   else
   {
      reset(false);
   }
}

/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{
   for (int c = 0; c < 8; c++)
   {
      for (int r = 0; r < 8; r++)
      {
         delete board[c][r];
      }
   }
}

// we really REALLY need to delete this.
Space space(0,0);

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   return *(board[pos.getCol()][pos.getRow()]);
}
Piece& Board::operator [] (const Position& pos)
{
   return *(board[pos.getCol()][pos.getRow()]);
}

 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position & posSelect) const
{
   ogstream ogstream;
   ogstream.drawBoard();
   for (int c = 0; c < 8; c++)
   {
      for (int r = 0; r < 8; r++)
      {
         board[c][r] -> display(&ogstream);
      }
   }

}

/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}

/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move & move)
{  
   numMoves ++;
   Position source = move.getSource();
   Position dest   = move.getDest();

   // Handles Simple captures
   if (move.getCapture() != INVALID)
   {
      this->operator[](source) = dest;
      board[dest.getCol()][dest.getRow()]
      = board[source.getCol()][source.getRow()];
         
      board[source.getCol()][source.getRow()]
      = new Space(source.getCol(), source.getRow());
   
      // Check en passant condition
      if (move.isEnPassant())
      {
         // En passant is moving up
         if (dest.getRow() > source.getRow())
         {
            // From where the pawn was captured
            board[dest.getCol()][dest.getRow() - 1]
               = new Space(dest.getCol(), dest.getRow() - 1);
         }
         // En passant is moving down
         else
         {
            // From where the pawn was captured
            board[dest.getCol()][dest.getRow() + 1]
               = new Space(dest.getCol(), dest.getRow() + 1);
         }
      }
   }
   // Handles moves
   else 
   {
      // Simple moves
      this->operator[](source) = dest;
      this->operator[](dest) = source;
      Piece* sourcePiece = board[source.getCol()][source.getRow()];

      board[source.getCol()][source.getRow()] 
      = board[dest.getCol()][dest.getRow()  ];

      board[dest.getCol()][dest.getRow()] = sourcePiece;

      // Castling condition
      if (move.isCastleK())
      {
         board[7][dest.getRow()] = new Space(7, dest.getRow());
         board[5][dest.getRow()] = new Rook(5, dest.getRow() );
      }
      if (move.isCastleQ())
      {
         board[0][dest.getRow()] = new Space(0, dest.getRow());
         board[3][dest.getRow()] = new Rook(3, dest.getRow() );
      }
   }

   // Handles promotions (queen only)
   if (move.getPromote() != INVALID)
   {
      board[dest.getCol()][dest.getRow()]
         = new Queen(dest.getCol(), dest.getRow());
   }
}

/**********************************************
 * BOARD : setUpKnights()
 *         Puts knights in their correct position on the board
 *********************************************/
void Board::setUpKnights()
{
   board[1][0] = new Knight(1, 0, true );
   board[6][0] = new Knight(6, 0, true );
   board[1][7] = new Knight(1, 7, false);
   board[6][7] = new Knight(6, 7, false);

};

/**********************************************
 * BOARD : setUpQueens()
 *         Puts queens in their correct position on the board
 *********************************************/
void Board::setUpQueens()
{
   board[3][0] = new Queen(3, 0, true );
   board[3][7] = new Queen(3, 7, false);
};

/**********************************************
 * BOARD : setUpKings()
 *         Puts kings in their correct position on the board
 *********************************************/
void Board::setUpKings()
{
   board[4][0] = new King(4, 0, true );
   board[4][7] = new King(4, 7, false);
};

/**********************************************
 * BOARD : setUpBishiops()
 *         Puts bishops in their correct position on the board
 *********************************************/
void Board::setUpBishops()
{
   board[2][0] = new Bishop(2, 0, true );
   board[5][0] = new Bishop(5, 0, true );
   board[2][7] = new Bishop(2, 7, false);
   board[5][7] = new Bishop(5, 7, false);
};

/**********************************************
 * BOARD : setUpRooks()
 *         Puts rooks in their correct position on the board
 *********************************************/
void Board::setUpRooks()
{
   board[0][0] = new Rook(0, 0, true );
   board[7][0] = new Rook(7, 0, true );
   board[0][7] = new Rook(0, 7, false);
   board[7][7] = new Rook(7, 7, false);
};

/**********************************************
 * BOARD : setUpPawns()
 *         Puts pawns in their correct position on the board
 *********************************************/
void Board::setUpPawns()
{
   for (int c = 0; c < 8; c++)
   {
      board[c][1] = new Pawn(c, 1, true );
      board[c][6] = new Pawn(c, 6, false);
   }
};
/**********************************************
 * BOARD : setUpSpaces()
 *                Get the whole board populated with spaces
 *********************************************/
void Board::setUpSpaces()
{
   for (int r = 2; r < 6; r++)
      for (int c = 0; c < 8; c++)
         board[c][r] = new Space(c,r);

};


/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr), moveNumber(0)
{
   pSpace = new Space(0, 0);
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}
