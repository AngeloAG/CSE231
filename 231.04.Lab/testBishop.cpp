/***********************************************************************
 * Source File:
 *    TEST BISHOP
 * Author:
 *    Jacob Mower, Connor, Angelo Arellano
 * Summary:
 *    The unit tests for a bishop
 ************************************************************************/


#include "testBishop.h"
#include "pieceBishop.h"     
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
 * 3     p   p           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   board.board[2][1] = &bishop;
   White white1(PAWN);
   board.board[1][2] = &white1;
   White white2(PAWN);
   board.board[3][2] = &white2;
   White white3(PAWN);
   board.board[1][0] = &white3;
   White white4(PAWN);
   board.board[3][0] = &white4;
   set <Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);  // No moves, it's blocked

   // TEARDOWN
   board.board[2][1] = nullptr; // white bishop
   board.board[1][2] = nullptr; // white1 pawn
   board.board[3][2] = nullptr; // white2 pawn
   board.board[1][0] = nullptr; // white3 pawn
   board.board[3][0] = nullptr; // white4 pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 .   7
 * 6               .     6
 * 5             .       5
 * 4   .       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     .   .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToEnd()
{
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   board.board[2][1] = &bishop;
   set <Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 9);  // Many moves
   assertUnit(moves.find(Move("c2b1")) != moves.end());
   assertUnit(moves.find(Move("c2d1")) != moves.end());
   assertUnit(moves.find(Move("c2b3")) != moves.end());
   assertUnit(moves.find(Move("c2a4")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   assertUnit(moves.find(Move("c2h7")) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr; // white bishop
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 p   7
 * 6               .     6
 * 5             .       5
 * 4   p       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToBlock()
{
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   board.board[2][1] = &bishop;
   White white1(PAWN);
   board.board[0][3] = &white1;
   White white2(PAWN);
   board.board[7][6] = &white2;
   White white3(PAWN);
   board.board[1][0] = &white3;
   White white4(PAWN);
   board.board[3][0] = &white4;
   set <Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 5);  // Many moves
   assertUnit(moves.find(Move("c2b3")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr; // white bishop
   board.board[0][3] = nullptr; // white1 pawn
   board.board[7][6] = nullptr; // white2 pawn
   board.board[1][0] = nullptr; // white3 pawn
   board.board[3][0] = nullptr; // white4 pawn
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 P   7
 * 6               .     6
 * 5             .       5
 * 4   P       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     P   P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToCapture()
{
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   board.board[2][1] = &bishop;
   Black black1(PAWN);
   board.board[0][3] = &black1;
   Black black2(PAWN);
   board.board[7][6] = &black2;
   Black black3(PAWN);
   board.board[1][0] = &black3;
   Black black4(PAWN);
   board.board[3][0] = &black4;
   set <Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 9);  // Many moves
   assertUnit(moves.find(Move("c2b1p")) != moves.end());
   assertUnit(moves.find(Move("c2d1p")) != moves.end());
   assertUnit(moves.find(Move("c2b3"))  != moves.end());
   assertUnit(moves.find(Move("c2a4p")) != moves.end());
   assertUnit(moves.find(Move("c2d3"))  != moves.end());
   assertUnit(moves.find(Move("c2e4"))  != moves.end());
   assertUnit(moves.find(Move("c2f5"))  != moves.end());
   assertUnit(moves.find(Move("c2g6"))  != moves.end());
   assertUnit(moves.find(Move("c2h7p")) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr; // white bishop
   board.board[0][3] = nullptr; // black1 pawn
   board.board[7][6] = nullptr; // black2 pawn
   board.board[1][0] = nullptr; // black3 pawn
   board.board[3][0] = nullptr; // black4 pawn
}


/*************************************
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
   // SETUP
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite          = true;
   bishop.position.colRow = 0x34;
   PieceType type         = KING;

   // EXERCISE
   type = bishop.getType();

   // VERIFY
   assertUnit(type                   == BISHOP);
   assertUnit(bishop.fWhite          == true  );
   assertUnit(bishop.position.colRow == 0x34  );
}  // TEARDOWN
