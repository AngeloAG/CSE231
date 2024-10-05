/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    Jacob Mower, Angelo Arellano Gaona
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#include "board.h"
#include "position.h"
#include "piece.h"
#include <cassert>
using namespace std;


// we really REALLY need to delete this.
Space space;

/***********************************************
* BOARD CONSTRUCTOR
* Initializes all spots to a nullpointer
***********************************************/
Board::Board(): numMoves(0)
{
   for (int i = 0; i < 8; i++)
   {
      for (int j = 0; j < 8; j++)
      {
         board[i][j] = nullptr;
      }
   }  
}

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


/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr)
{
   pSpace = new Space;
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}