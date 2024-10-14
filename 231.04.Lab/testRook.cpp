/***********************************************************************
 * Source File:
 *    TEST ROOK
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the rook
 ************************************************************************/

#include "testRook.h"
#include "pieceRook.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3       p             3
 * 2     p(r)p           2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Rook rook(2, 2, false /*white*/); // Create a white rook at position (2, 2)
   rook.fWhite = true; // The rook is white
   board.board[2][2] = &rook; // Place the rook on the board

   // Place blocking pieces
   Piece pawn1(PAWN);
   board.board[3][2] = &pawn1; // Pawn at (3, 2)
   Piece pawn2(PAWN);
   board.board[1][2] = &pawn2; // Pawn at (1, 2)

   set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board); // Get valid moves for the rook

   // VERIFY
   assertUnit(moves.size() == 0); // No moves, it's blocked

   // TEARDOWN
   board.board[2][2] = nullptr; // Remove rook
   board.board[3][2] = nullptr; // Remove pawn1
   board.board[1][2] = nullptr; // Remove pawn2
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   . .(r). . . . .   2
 * 1       .             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;
   Rook rook(2, 2, false /*white*/); // Create a white rook at position (2, 2)
   rook.fWhite = true; // The rook is white
   board.board[2][2] = &rook; // Place the rook on the board
   set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board); // Get valid moves for the rook

   // VERIFY
   assertUnit(moves.size() == 14); // Rook can move to 14 positions
   assertUnit(moves.find(Move("b2")) != moves.end()); // Left
   assertUnit(moves.find(Move("c2")) != moves.end()); // Right
   assertUnit(moves.find(Move("d2")) != moves.end()); // Right
   assertUnit(moves.find(Move("e2")) != moves.end()); // Right
   assertUnit(moves.find(Move("f2")) != moves.end()); // Right
   assertUnit(moves.find(Move("g2")) != moves.end()); // Right
   assertUnit(moves.find(Move("h2")) != moves.end()); // Right
   assertUnit(moves.find(Move("a2")) != moves.end()); // Left
   assertUnit(moves.find(Move("2b")) != moves.end()); // Down
   assertUnit(moves.find(Move("2c")) != moves.end()); // Down
   assertUnit(moves.find(Move("2d")) != moves.end()); // Down
   assertUnit(moves.find(Move("2e")) != moves.end()); // Down
   assertUnit(moves.find(Move("2f")) != moves.end()); // Down
   assertUnit(moves.find(Move("2g")) != moves.end()); // Down
   assertUnit(moves.find(Move("2h")) != moves.end()); // Down

   // TEARDOWN
   board.board[2][2] = nullptr; // Remove rook
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   p .(r). . . . p   2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToBlock()
{
   // SETUP
   BoardEmpty board;
   Rook rook(2, 2, false /*white*/); // Create a white rook at position (2, 2)
   rook.fWhite = true; // The rook is white
   board.board[2][2] = &rook; // Place the rook on the board

   // Place blocking pieces
   Piece pawn1(PAWN);
   board.board[1][2] = &pawn1; // Pawn at (1, 2)
   Piece pawn2(PAWN);
   board.board[2][0] = &pawn2; // Pawn at (2, 0)
   Piece pawn3(PAWN);
   board.board[3][2] = &pawn3; // Pawn at (3, 2)

   set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board); // Get valid moves for the rook

   // VERIFY
   assertUnit(moves.size() == 4); // Rook can only move to 4 positions
   assertUnit(moves.find(Move("2b")) != moves.end()); // Block left
   assertUnit(moves.find(Move("3b")) != moves.end()); // Block down
   assertUnit(moves.find(Move("2a")) != moves.end()); // Block left
   assertUnit(moves.find(Move("4b")) != moves.end()); // Block down

   // TEARDOWN
   board.board[2][2] = nullptr; // Remove rook
   board.board[1][2] = nullptr; // Remove pawn1
   board.board[2][0] = nullptr; // Remove pawn2
   board.board[3][2] = nullptr; // Remove pawn3
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   P .(r). . . . P   2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToCapture()
{
   // SETUP
   BoardEmpty board;
   Rook rook(2, 2, false /*white*/); // Create a white rook at position (2, 2)
   rook.fWhite = true; // The rook is white
   board.board[2][2] = &rook; // Place the rook on the board

   // Place opponent's piece to capture
   Piece pawn1(PAWN);
   pawn1.fWhite = false; // The pawn is black
   board.board[3][2] = &pawn1; // Pawn at (3, 2)
   Piece pawn2(PAWN);
   board.board[1][2] = &pawn2; // Pawn at (1, 2)

   set<Move> moves;

   // EXERCISE
   rook.getMoves(moves, board); // Get valid moves for the rook

   // VERIFY
   assertUnit(moves.size() == 6); // Rook can capture 6 positions
   assertUnit(moves.find(Move("3b")) != moves.end()); // Capture down
   assertUnit(moves.find(Move("3c")) != moves.end()); // Capture right
   assertUnit(moves.find(Move("3a")) != moves.end()); // Capture left
   assertUnit(moves.find(Move("3d")) != moves.end()); // Capture right
   assertUnit(moves.find(Move("3e")) != moves.end()); // Capture right
   assertUnit(moves.find(Move("3f")) != moves.end()); // Capture right

   // TEARDOWN
   board.board[2][2] = nullptr; // Remove rook
   board.board[1][2] = nullptr; // Remove pawn1
   board.board[3][2] = nullptr; // Remove pawn2
}


/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
   // SETUP
   Rook rook(7, 7, false /*white*/); // Create a white rook at (7, 7)
   rook.fWhite = true; // The rook is white
   rook.position.colRow = 0x34; // Position

   PieceType type = KING; // Initialize type as KING

   // EXERCISE
   type = rook.getType(); // Get the type of the rook

   // VERIFY
   assertUnit(type == ROOK); // Type should be ROOK
   assertUnit(rook.fWhite == true); // Rook should be white
   assertUnit(rook.position.colRow == 0x34); // Position should remain
}
