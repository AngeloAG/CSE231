/***********************************************************************
 * Source File:
 *    TEST KING
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the King
 ************************************************************************/

#include "testKing.h"
#include "pieceRook.h"
#include "pieceKing.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       p p p         6
 * 5       p(k)p         5
 * 4       p p p         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   King king(5, 5, false /*white*/);
   king.fWhite = true;
   king.nMoves = 1; // King has already moved
   king.position.set(3, 4);
   board.board[3][4] = &king;
   
   // Surround the king with friendly pawns (block all moves)
   White whitePawn1(PAWN);
   board.board[2][3] = &whitePawn1; // Top-left
   White whitePawn2(PAWN);
   board.board[2][4] = &whitePawn2; // Top-center
   White whitePawn3(PAWN);
   board.board[2][5] = &whitePawn3; // Top-right
   White whitePawn4(PAWN);
   board.board[3][3] = &whitePawn4; // Left
   White whitePawn5(PAWN);
   board.board[3][5] = &whitePawn5; // Right
   White whitePawn6(PAWN);
   board.board[4][3] = &whitePawn6; // Bottom-left
   White whitePawn7(PAWN);
   board.board[4][4] = &whitePawn7; // Bottom-center
   White whitePawn8(PAWN);
   board.board[4][5] = &whitePawn8; // Bottom-right
   
   set<Move> moves;
   
   // EXERCISE
   king.getMoves(moves, board);
   
   // VERIFY // King should have no valid moves since it's blocked by friendly pieces
   assertUnit(moves.size() == 0);
   
   // TEARDOWN
   board.board[4][4] = nullptr; // king
   board.board[3][3] = nullptr; // whitePawn1
   board.board[3][4] = nullptr; // whitePawn2
   board.board[3][5] = nullptr; // whitePawn3
   board.board[4][3] = nullptr; // whitePawn4
   board.board[4][5] = nullptr; // whitePawn5
   board.board[5][3] = nullptr; // whitePawn6
   board.board[5][4] = nullptr; // whitePawn7
   board.board[5][5] = nullptr; // whitePawn8
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       P P P         6
 * 5       P(k)P         5
 * 4       P P P         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_capture()
{
   // SETUP
   BoardEmpty board;
   King king(5, 5, false /*white*/);
   king.fWhite = true;
   king.nMoves = 1; // King has already moved
   king.position.set(3, 4);
   board.board[3][4] = &king;

   // Surround the king with enemy pawns (possible capture moves)
   Black blackPawn1(PAWN);
   board.board[2][5] = &blackPawn1; // Top-left
   Black blackPawn2(PAWN);
   board.board[3][5] = &blackPawn2; // Top-center
   Black blackPawn3(PAWN);
   board.board[4][5] = &blackPawn3; // Top-right
   Black blackPawn4(PAWN);
   board.board[2][4] = &blackPawn4; // Left
   Black blackPawn5(PAWN);
   board.board[4][4] = &blackPawn5; // Right
   Black blackPawn6(PAWN);
   board.board[2][3] = &blackPawn6; // Bottom-left
   Black blackPawn7(PAWN);
   board.board[3][3] = &blackPawn7; // Bottom-center
   Black blackPawn8(PAWN);
   board.board[4][3] = &blackPawn8; // Bottom-right

   set<Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);//The king should be able to capture all pawns
   assertUnit(moves.find(Move("d5c6p")) != moves.end()); // capture blackPawn1
   assertUnit(moves.find(Move("d5d6p")) != moves.end()); // capture blackPawn2
   assertUnit(moves.find(Move("d5e6p")) != moves.end()); // capture blackPawn3
   assertUnit(moves.find(Move("d5e5p")) != moves.end()); // capture blackPawn4
   assertUnit(moves.find(Move("d5e4p")) != moves.end()); // capture blackPawn5
   assertUnit(moves.find(Move("d5d4p")) != moves.end()); // capture blackPawn6
   assertUnit(moves.find(Move("d5c4p")) != moves.end()); // capture blackPawn7
   assertUnit(moves.find(Move("d5c5p")) != moves.end()); // capture blackPawn8

   // TEARDOWN
   board.board[3][4] = nullptr; // king
   board.board[2][5] = nullptr; // blackPawn1
   board.board[3][5] = nullptr; // blackPawn2
   board.board[4][5] = nullptr; // blackPawn3
   board.board[2][4] = nullptr; // blackPawn4
   board.board[4][4] = nullptr; // blackPawn5
   board.board[2][3] = nullptr; // blackPawn6
   board.board[3][3] = nullptr; // blackPawn7
   board.board[4][3] = nullptr; // blackPawn8
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       . . .         6
 * 5       .(k).         5
 * 4       . . .         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_free()
{
   // SETUP
   BoardEmpty board;
   King king(5, 5, false /*white*/);
   king.fWhite = true;
   king.nMoves = 1; // King has already moved
   king.position.set(4, 4);
   board.board[4][4] = &king;

   set<Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   // The king can move to any of the 8 adjacent squares
   assertUnit(moves.size() == 8);
   assertUnit(moves.find(Move("e5d4")) != moves.end()); // Move to d4
   assertUnit(moves.find(Move("e5e4")) != moves.end()); // Move to e4
   assertUnit(moves.find(Move("e5f4")) != moves.end()); // Move to f4
   assertUnit(moves.find(Move("e5d5")) != moves.end()); // Move to d5
   assertUnit(moves.find(Move("e5f5")) != moves.end()); // Move to f5
   assertUnit(moves.find(Move("e5d6")) != moves.end()); // Move to d6
   assertUnit(moves.find(Move("e5e6")) != moves.end()); // Move to e6
   assertUnit(moves.find(Move("e5f6")) != moves.end()); // Move to f6

   // TEARDOWN
   board.board[4][4] = nullptr; // king
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2   . .               2
 * 1  (k).               1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_end()
{
   // SETUP
   BoardEmpty board;
   King king(1, 1, false /*white*/);
   king.fWhite = true;
   king.nMoves = 1; // King has already moved
   king.position.set(0, 0); // King at a1
   board.board[0][0] = &king;

   set<Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);  // The king should have only 3 valid moves
   assertUnit(moves.find(Move("a1a2")) != moves.end()); // Move to a2
   assertUnit(moves.find(Move("a1b1")) != moves.end()); // Move to b1
   assertUnit(moves.find(Move("a1b2")) != moves.end()); // Move to b2

   // TEARDOWN
   board.board[0][0] = nullptr; // king
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r   . .(k). . r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastle()
{
   // SETUP
   BoardEmpty board;
   King king(1, 4, false /*white*/); // white king starting at e1
   king.fWhite   = true;
   king.lastMove = 0;
   king.nMoves   = 0;
   king.position.set(4, 0); // e1
   board.board[4][0] = &king;

   // Place rooks on a1 and h1
   Rook rook1(1, 0, false /*white*/); // white rook on a1
   rook1.fWhite   = true;
   rook1.position.set(0, 0); // a1
   rook1.lastMove = 0;
   rook1.nMoves   = 0;
   board.board[0][0] = &rook1;

   Rook rook2(1, 7, false /*white*/); // white rook on h1
   rook2.fWhite   = true;
   rook2.position.set(0, 7); // h1
   rook2.lastMove = 0;
   rook2.nMoves   = 0;
   board.board[7][0] = &rook2;

   // Add pawns in front of the king to ensure they don't block
   White whitePawn1(PAWN);
   board.board[3][1] = &whitePawn1; // d2
   White whitePawn2(PAWN);
   board.board[4][1] = &whitePawn2; // e2
   White whitePawn3(PAWN);
   board.board[5][1] = &whitePawn3; // f2

   set<Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   // Check for castling moves
   assertUnit(moves.size() == 4);
   assertUnit(moves.find(Move("e1c1C")) != moves.end()); // Queen-side castling (a1 to e1)
   assertUnit(moves.find(Move("e1g1c")) != moves.end()); // King-side castling (h1 to e1)
   assertUnit(moves.find(Move("e1d1")) != moves.end());  // Normal king moves
   assertUnit(moves.find(Move("e1f1")) != moves.end());  // Normal king moves

   // TEARDOWN
   board.board[4][0] = nullptr; // king
   board.board[0][0] = nullptr; // rook1
   board.board[7][0] = nullptr; // rook2
   board.board[3][1] = nullptr; // whitePawn1
   board.board[4][1] = nullptr; // whitePawn2
   board.board[5][1] = nullptr; // whitePawn3
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R   . .(K). . R   8
 * 7         P P P       7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blackCastle()
{
   // SETUP
   BoardEmpty board;
   King king(8, 5, true /*black*/); // Black king starting at e8
   king.fWhite       = false;
   king.position.set(4, 7); // e8
   king.lastMove     = 0;
   king.nMoves       = 0;
   board.board[4][7] = &king;

   // Place black rooks on a8 and h8
   Rook rook1(8, 1, true /*black*/); // black rook on a8
   rook1.fWhite      = false;
   rook1.position.set(0, 7); // a8
   rook1.lastMove    = 0;
   rook1.nMoves      = 0;
   board.board[0][7] = &rook1;

   Rook rook2(8, 8, true /*black*/); // black rook on h8
   rook2.fWhite      = false;
   rook2.position.set(7, 7); // h8
   rook2.lastMove    = 0;
   rook2.nMoves      = 0;
   board.board[7][7] = &rook2;

   // Add pawns in front of the king to ensure they don't block
   Black blackPawn1(PAWN);
   board.board[3][6] = &blackPawn1; // d7
   Black blackPawn2(PAWN);
   board.board[4][6] = &blackPawn2; // e7
   Black blackPawn3(PAWN);
   board.board[5][6] = &blackPawn3; // f7

   set<Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 4);
   assertUnit(moves.find(Move("e8c8C")) != moves.end()); // Queen-side castling (a8 to e8)
   assertUnit(moves.find(Move("e8g8c")) != moves.end()); // King-side castling (h8 to e8)
   assertUnit(moves.find(Move("e8d8")) != moves.end());  // Normal king moves
   assertUnit(moves.find(Move("e8f8")) != moves.end());  // Normal king moves

   // TEARDOWN
   board.board[4][7] = nullptr; // king
   board.board[0][7] = nullptr; // rook1
   board.board[7][7] = nullptr; // rook2
   board.board[3][6] = nullptr; // blackPawn1
   board.board[4][6] = nullptr; // blackPawn2
   board.board[5][6] = nullptr; // blackPawn3
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleKingMoved()
{
   // SETUP
   BoardEmpty board;
   King king(1, 4, false /*white*/);
   king.fWhite       = true;
   king.position.set(0, 4); // e1
   king.lastMove     = 1;   // King has already moved
   board.board[0][4] = &king;

   Rook rook1(1, 0, false /*white*/);
   rook1.fWhite      = true;
   rook1.position.set(0, 0); // a1
   rook1.lastMove    = 0;
   board.board[0][0] = &rook1;

   Rook rook2(1, 7, false /*white*/);
   rook2.fWhite      = true;
   rook2.position.set(0, 7); // h1
   rook2.lastMove    = 0;
   board.board[0][7] = &rook2;

   White whitePawn1(PAWN);
   board.board[1][3] = &whitePawn1; // d2
   White whitePawn2(PAWN);
   board.board[1][4] = &whitePawn2; // e2
   White whitePawn3(PAWN);
   board.board[1][5] = &whitePawn3; // f2

   set<Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(Move("e1c1")) == moves.end()); // No queen-side castling
   assertUnit(moves.find(Move("e1g1")) == moves.end()); // No king-side castling

   // TEARDOWN
   board.board[0][4] = nullptr; // king
   board.board[0][0] = nullptr; // rook1
   board.board[0][7] = nullptr; // rook2
   board.board[1][3] = nullptr; // whitePawn1
   board.board[1][4] = nullptr; // whitePawn2
   board.board[1][5] = nullptr; // whitePawn3
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleRookMoved()
{
   // SETUP
   BoardEmpty board;
   King king(1, 4, false /*white*/);
   king.fWhite = true;
   king.position.set(4, 0); // e1
   king.lastMove = 0;       // King has not moved
   board.board[4][0] = &king;

   Rook rook1(1, 0, false /*white*/); // white rook on a1
   rook1.fWhite = true;
   rook1.position.set(0, 0); // a1
   rook1.nMoves = 1; // Rook on a1 has moved
   board.board[0][0] = &rook1;

   Rook rook2(1, 7, false /*white*/); // white rook on h1
   rook2.fWhite = true;
   rook2.position.set(7, 0); // h1
   rook2.nMoves = 1;         // Rook on h1 has moved
   board.board[7][0] = &rook2;

   White whitePawn1(PAWN);
   board.board[3][1] = &whitePawn1; // d2
   White whitePawn2(PAWN);
   board.board[4][1] = &whitePawn2; // e2
   White whitePawn3(PAWN);
   board.board[5][1] = &whitePawn3; // f2

   set<Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(Move("e1d1")) != moves.end()); // Normal King moves
   assertUnit(moves.find(Move("e1f1")) != moves.end()); // Normal King moves

   // TEARDOWN
   board.board[4][0] = nullptr; // king
   board.board[0][0] = nullptr; // rook1
   board.board[7][0] = nullptr; // rook2
   board.board[3][1] = nullptr; // whitePawn1
   board.board[4][1] = nullptr; // whitePawn2
   board.board[5][1] = nullptr; // whitePawn3
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
   // SETUP
   King king(7, 7, false /*white*/); 
   king.fWhite          = true  ;  
   king.position.colRow = 0x34  ; 
   PieceType type       = BISHOP;  

   // EXERCISE
   type = king.getType();  

   // VERIFY
   assertUnit(type                 == KING);
   assertUnit(king.fWhite          == true);
   assertUnit(king.position.colRow == 0x34);
}  // TEARDOWN


