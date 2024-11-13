/***********************************************************************
 * Source File:
 *    TEST PAWN
 * Author:
 *    Jacob Mower, Connor Hopkins, Angelo Arellano
 * Summary:
 *    The unit tests for the pawn
 ************************************************************************/

#include "testPawn.h"
#include "piecePawn.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      

 /*************************************
  * GET MOVES TEST Simple
  * White pawn in the middle of the board: b4
  *
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5     .               5
  * 4    (p)              4
  * 3                     3
  * 2                     2
  * 1                     1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestPawn::getMoves_simpleWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 2, false /*white*/);
   pawn.fWhite = true; 
   pawn.position.set(1, 3);
   pawn.nMoves = 1; // it has already moved
   board.board[1][3] = &pawn;
   set<Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board); 

   // VERIFY
   assertUnit(moves.size() == 1);
   assertUnit(moves.find(Move("b4b5")) != moves.end());

   // TEARDOWN
   board.board[1][3] = nullptr;
}

/*************************************
 * GET MOVES TEST Simple
 * Black pawn in the middle of the board: b4
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4    (P)              4
 * 3     .               3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_simpleBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 2, true);
   pawn.fWhite = false; // black pawn
   pawn.position.set(1, 3);
   pawn.nMoves = 1; // it has already moved
   board.board[1][3] = &pawn;
   set<Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1);
   assertUnit(moves.find(Move("b4b3")) != moves.end());

   // TEARDOWN
   board.board[1][3] = nullptr;
}


/*************************************
 * GET MOVES TEST InitialAdvance
 * White pawn initial advance
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4     .               4
 * 3     .               3
 * 2    (p)              2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 2, false /*white*/);
   pawn.fWhite = true;
   pawn.position.set(1, 1);
   pawn.nMoves = 0; // it has not moved
   board.board[1][1] = &pawn;
   set<Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2); // Two possible moves
   assertUnit(moves.find(Move("b2b3")) != moves.end());
   assertUnit(moves.find(Move("b2b4")) != moves.end());

   // TEARDOWN
   board.board[1][1] = nullptr;
}

/*************************************
 * GET MOVES TEST InitialAdvance
 * Black pawn initial advance
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7      (P)            7
 * 6       .             6
 * 5       .             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 2, true);
   pawn.fWhite = false;
   pawn.position.set(2, 6);
   pawn.nMoves = 0; // it has not moved
   board.board[2][6] = &pawn;
   set<Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(Move("c7c6")) != moves.end());
   assertUnit(moves.find(Move("c7c5")) != moves.end());

   // TEARDOWN
   board.board[2][6] = nullptr;
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move pawn to b6 and capture
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7   P P P             7
 * 6    (p)              6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 2, false /*white*/);
   pawn.fWhite = true;
   pawn.position.set(1, 5);
   pawn.nMoves = 1; // it has moved
   board.board[1][5] = &pawn;
   set<Move> moves;
   Black black1(PAWN);
   board.board[0][6] = &black1;
   Black black2(PAWN);
   board.board[1][6] = &black2;
   Black black3(PAWN);
   board.board[2][6] = &black3;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(Move("b6a7p")) != moves.end());
   assertUnit(moves.find(Move("b6c7p")) != moves.end());

   // TEARDOWN
   board.board[1][5] = nullptr;
   board.board[0][6] = nullptr;
   board.board[1][6] = nullptr;
   board.board[2][6] = nullptr;
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move pawn to b6 and capture
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6    (P)              6
 * 5   p p p             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 2, true);
   pawn.fWhite = false;
   pawn.position.set(1, 5);
   pawn.nMoves = 1; // it has moved
   board.board[1][5] = &pawn;
   set<Move> moves;
   White white1(PAWN);
   board.board[0][4] = &white1;
   White white2(PAWN);
   board.board[1][4] = &white2;
   White white3(PAWN);
   board.board[2][4] = &white3;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(Move("b6a5p")) != moves.end());
   assertUnit(moves.find(Move("b6c5p")) != moves.end());

   // TEARDOWN
   board.board[1][5] = nullptr;
   board.board[0][4] = nullptr;
   board.board[1][4] = nullptr;
   board.board[2][4] = nullptr;
}

/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant b5a6E
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6   . P .             6
 * 5   P(p)P             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 2, false /*white*/);
   pawn.fWhite = true;
   pawn.position.set(1, 4);
   pawn.nMoves = 2; // it has moved
   board.board[1][4] = &pawn;
   set<Move> moves;
   BlackPawnJustMovedFake black1(PAWN); // Capture target
   board.board[0][4] = &black1;
   Black black2(PAWN);
   board.board[1][5] = &black2;
   BlackPawnNotJustMovedFake black3(PAWN);
   board.board[2][4] = &black3;
   board.numMoves = 3; //This is the third turn

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1);
   assertUnit(moves.find(Move("b5a6E")) != moves.end());

   // TEARDOWN
   board.board[1][4] = nullptr;
   board.board[0][4] = nullptr;
   board.board[1][5] = nullptr;
   board.board[2][4] = nullptr;
}


/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant f4g3E
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4           p(P)p     4
 * 3           . p .     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 2, true);
   pawn.fWhite = false;
   pawn.position.set(5, 3);
   pawn.nMoves = 2; // it has moved
   board.board[5][3] = &pawn;
   set<Move> moves;
   WhitePawnNotJustMovedFake white1(PAWN);  
   board.board[4][3] = &white1;
   White white2(PAWN);
   board.board[5][2] = &white2;
   WhitePawnJustMovedFake white3(PAWN); // Capture target
   board.board[6][3] = &white3;
   board.numMoves = 3; //This is the third turn

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1);
   assertUnit(moves.find(Move("f4g3E")) != moves.end());

   // TEARDOWN
   board.board[5][3] = nullptr;
   board.board[4][3] = nullptr;
   board.board[5][2] = nullptr;
   board.board[6][3] = nullptr;
}

/*************************************
 * GET MOVES TEST Promotion
 * Promotion: b7a8pQ
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   P . P             8
 * 7    (p)              7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 2, false /*white*/);
   pawn.fWhite = true;
   pawn.position.set(1, 6);
   pawn.nMoves = 2; // it has moved
   board.board[1][6] = &pawn;
   set<Move> moves;
   Black black1(PAWN); 
   board.board[0][7] = &black1;
   Black black2(PAWN);
   board.board[2][7] = &black2;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);
   assertUnit(moves.find(Move("b7a8pQ")) != moves.end());
   assertUnit(moves.find(Move("b7b8Q"))  != moves.end());
   assertUnit(moves.find(Move("b7c8pQ")) != moves.end());

   // TEARDOWN
   board.board[1][6] = nullptr;
   board.board[0][7] = nullptr;
   board.board[2][7] = nullptr;
}


/*************************************
 * GET MOVES TEST Promotion
 * Promotion: e2d1rQ
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2          (P)        2
 * 1         r   r       1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 2, true);
   pawn.fWhite = false;
   pawn.position.set(4, 1);
   pawn.nMoves = 2; // it has moved
   board.board[4][1] = &pawn;
   set<Move> moves;
   White white1(ROOK);
   board.board[3][0] = &white1;
   White white2(ROOK);
   board.board[5][0] = &white2;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);
   assertUnit(moves.find(Move("e2d1rQ")) != moves.end());
   assertUnit(moves.find(Move("e2e1Q"))  != moves.end());
   assertUnit(moves.find(Move("e2f1rQ")) != moves.end());

   // TEARDOWN
   board.board[4][1] = nullptr;
   board.board[3][0] = nullptr;
   board.board[5][0] = nullptr;
}


/*************************************
 * GET TYPE : pawn
 * Input:
 * Output: PAWN
 **************************************/
void TestPawn::getType()
{
   // SETUP
   Pawn pawn(7, 7, false /*white*/);
   pawn.fWhite          = true;
   pawn.position.colRow = 0x34;

   PieceType type = KING;

   // EXERCISE
   type = pawn.getType();

   // VERIFY
   assertUnit(type == PAWN);
   assertUnit(pawn.fWhite == true);
   assertUnit(pawn.position.colRow == 0x34);
}

