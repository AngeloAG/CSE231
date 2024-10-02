/***********************************************************************
 * Header File:
 *    TEST MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>

 /*************************************
  * Constructor : default
  * Input: 
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default() 
{
   // SETUP
   // EXERCISE
   Move mov;

   // VERIFY
   assertUnit(mov.source.isInvalid() == true);
   assertUnit(mov.dest.isInvalid() == true);

}

 /*************************************
  * CONSTRUCTOR : standard string move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::constructString_simple()
{
   // SETUP

   // EXERCISE
   Move mov("e5e6");

   // VERIFY
   assertUnit(mov.source == 0x44);
   assertUnit(mov.dest == 0x45);
   assertUnit(mov.moveType == Move::MOVE);

}

 /*************************************
  * READ simple move 
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::read_simple()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * READ capture move 
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::read_capture()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * READ enpassant move 
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::read_enpassant()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * READ king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::read_castleKing()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * READ queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::read_castleQueen()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * ASSIGN simple move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::assign_simple()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * ASSIGN capture move
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::assign_capture()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * ASSIGN enpassant move
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::assign_enpassant()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * ASSIGN king side castle
  * Input:  e1g1c
  * Output: source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  **************************************/
void TestMove::assign_castleKing()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * ASSIGN queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::assign_castleQueen()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT simple move
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  * Output:  e5e6
  **************************************/
void TestMove::getText_simple()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT capture
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  *         capture=ROOK
  * Output:  e5e6r
  **************************************/
void TestMove::getText_capture()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT en passant
  * Input : source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  *         capture=PAWN
  * Output:  e5f6E
  **************************************/
void TestMove::getText_enpassant()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT king side castle
  * Input : source=4,0
  *         dest  =6,0
  *         type  =CASTLE_KING
  * Output:  e1g1c
  **************************************/
void TestMove::getText_castleKing()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT queen side castle
  * Input : source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN  
  * Output:  e1c1C
  **************************************/
void TestMove::getText_castleQueen()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LETTER FROM PIECE TYPE space
  * Input :  SPACE
  * Output:  ' '
  **************************************/
void TestMove::letterFromPieceType_space()
{
   // SETUP
   Move mov;

   // EXERCISE
   char letter = mov.letterFromPieceType(SPACE);

   // VERIFY
   assertUnit(letter == ' ');
}

 /*************************************
  * LETTER FROM PIECE TYPE pawn
  * Input : PAWN
  * Output:  'p'
  **************************************/
void TestMove::letterFromPieceType_pawn()
{
   // SETUP
   Move mov;

   // EXERCISE
   char letter = mov.letterFromPieceType(PAWN);

   // VERIFY
   assertUnit(letter == 'p');
}

 /*************************************
  * LETTER FROM PIECE TYPE bishop
  * Input : BISHOP
  * Output:  'b'
  **************************************/
void TestMove::letterFromPieceType_bishop()
{
   // SETUP
   Move mov;

   // EXERCISE
   char letter = mov.letterFromPieceType(BISHOP);

   // VERIFY
   assertUnit(letter == 'b');
}

 /*************************************
  * LETTER FROM PIECE TYPE knight
  * Input : KNIGHT
  * Output:  'n'
  **************************************/
void TestMove::letterFromPieceType_knight()
{
   // SETUP
   Move mov;

   // EXERCISE
   char letter = mov.letterFromPieceType(KNIGHT);

   // VERIFY
   assertUnit(letter == 'n');
}

 /*************************************
  * LETTER FROM PIECE TYPE rook
  * Input : ROOK
  * Output:  'r'
  **************************************/
void TestMove::letterFromPieceType_rook()
{
   // SETUP
   Move mov;

   // EXERCISE
   char letter = mov.letterFromPieceType(ROOK);

   // VERIFY
   assertUnit(letter == 'r');
}

 /*************************************
  * LETTER FROM PIECE TYPE queen
  * Input : QUEEN
  * Output:  'q'
  **************************************/
void TestMove::letterFromPieceType_queen()
{
   // SETUP
   Move mov;

   // EXERCISE
   char letter = mov.letterFromPieceType(QUEEN);

   // VERIFY
   assertUnit(letter == 'q');
}

 /*************************************
  * LETTER FROM PIECE TYPE king
  * Input : KING
  * Output:  'k'
  **************************************/
void TestMove::letterFromPieceType_king()
{
   // SETUP
   Move mov;

   // EXERCISE
   char letter = mov.letterFromPieceType(KING);

   // VERIFY
   assertUnit(letter == 'k');
}

 /*************************************
  * PIECE TYPE FROM LETTER pawn
  * Input : 'p'
  * Output:  PAWN
  **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   // SETUP
   Move mov;

   // EXERCISE
   PieceType pieceType = mov.pieceTypeFromLetter('p');

   // VERIFY
   assertUnit(pieceType == PAWN);
}

 /*************************************
  * PIECE TYPE FROM LETTER bishop
  * Input : 'b'
  * Output:  BISHOP
  **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   // SETUP
   Move mov;

   // EXERCISE
   PieceType pieceType = mov.pieceTypeFromLetter('b');

   // VERIFY
   assertUnit(pieceType == BISHOP);
}

 /*************************************
  * PIECE TYPE FROM LETTER knight
  * Input : 'n'
  * Output:  KNIGHT
  **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   // SETUP
   Move mov;

   // EXERCISE
   PieceType pieceType = mov.pieceTypeFromLetter('n');

   // VERIFY
   assertUnit(pieceType == KNIGHT);
}

 /*************************************
  * PIECE TYPE FROM LETTER rook
  * Input : 'r'
  * Output:  ROOK
  **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   // SETUP
   Move mov;

   // EXERCISE
   PieceType pieceType = mov.pieceTypeFromLetter('r');

   // VERIFY
   assertUnit(pieceType == ROOK);
}

 /*************************************
  * PIECE TYPE FROM LETTER queen
  * Input : 'q'
  * Output:  QUEEN
  **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   // SETUP
   Move mov;

   // EXERCISE
   PieceType pieceType = mov.pieceTypeFromLetter('q');

   // VERIFY
   assertUnit(pieceType == QUEEN);
}

 /*************************************
  * PIECE TYPE FROM LETTER king
  * Input : 'k'
  * Output:  KING
  **************************************/
void TestMove::pieceTypeFromLetter_king() 
{
   // SETUP
   Move mov;

   // EXERCISE
   PieceType pieceType = mov.pieceTypeFromLetter('k');

   // VERIFY
   assertUnit(pieceType == KING);
}


 /*************************************
  * EQUAL - NOT
  * Input : b2b4 == b2b5
  * Output: false
  **************************************/
void TestMove::equal_not()
{
   // SETUP
   Move mov1("b2b4");
   Move mov2("b2b5");

   // EXERCISE
   bool equals = mov1 == mov2;

   // VERIFY
   assertUnit(equals);
}

 /*************************************
  * EQUAL - EQUALS
  * Input : b2b4 == b2b4
  * Output: false
  **************************************/
void TestMove::equal_equals()
{
   // SETUP
   Move mov1("b2b4");
   Move mov2("b2b4");

   // EXERCISE
   bool equals = mov1 == mov2;

   // VERIFY
   assertUnit(equals);
}

 /*************************************
  * LESS THAN - LESS THAN
  * Input : b2b2 < b2b4
  * Output: false
  **************************************/
void TestMove::lessthan_lessthan()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LESS THAN - EQUALS
  * Input : b2b4 < b2b4
  * Output: false
  **************************************/
void TestMove::lessthan_equals()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * LESS THAN - GREATAER THAN
  * Input : b2b4 < b2b2
  * Output: false
  **************************************/
void TestMove::lessthan_greaterthan()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}
