/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Jacob Mower, Angelo Arellano Gaona
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <string>
#include <cstdint>
#include <cassert>
using std::string;
using std::ostream;
using std::istream;

const int SIZE_SQUARE  = 32;   // number of pixels in a square by default
const int OFFSET_BOARD = 50;   // boarder between the board and the edge of screen

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0};
const Delta ADD_C = { 0,  1};
const Delta SUB_R = {-1,  0};
const Delta SUB_C = { 0, -1};


class PositionTest;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
   friend class TestKnight;
   friend class TestBishop;
   friend class TestQueen;
   friend class TestKing;
   friend class TestRook;
   friend class TestPawn;
public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
   Position(const Position & rhs): colRow(rhs.colRow) {                               }
   Position() : colRow(0xff)      {                                                   }
   bool isInvalid() const         { return !isValid();                                }
   bool isValid()   const         { return getLocation() >= 0 && getLocation() < 64;  }
   void setValid()                { set(0,   0);                                      }
   void setInvalid()              { set(-1, -1);                                      }
   bool operator <  (const Position & rhs) const { return this->colRow < rhs.colRow;  }
   bool operator == (const Position & rhs) const { return rhs.colRow == this->colRow; }
   bool operator != (const Position & rhs) const { return rhs.colRow != this->colRow; }
   const Position & operator = (const Position & rhs) { this->colRow = rhs.colRow; return *this;}
   
   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
   Position(int location)         { setLocation(location);                            }
   int getLocation() const        { return getRow() * 8 + getCol();                   }
   void setLocation(int location) { setRow(floor(location / 8)); setCol(location % 8);}

   
   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
   Position(int c, int r)         { this->set(c, r);                                }
   virtual int getCol() const;
   virtual int getRow() const;
   void setRow(int r)             { this->colRow &= 0xf0; this->colRow |= r;        }
   void setCol(int c)             { this->colRow &= 0x0f; this->colRow |= (c << 4); }
   void set(int c, int r)         { this->setCol(c); this->setRow(r);               }

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"
   Position(const char * s)                       { *this = s;                  }
   const Position & operator = (const char * rhs) { return *this = string(rhs); }
   Position       & operator = (const string & rhs);

   
   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()               const { return getCol()*squareHeight + OFFSET_BOARD; }
   int getY()               const { return getRow()*squareWidth + OFFSET_BOARD; }
   void setXY(double x, double y);
   double getSquareWidth()  const { return squareWidth; }
   double getSquareHeight() const { return squareHeight; }
   void setSquareWidth (double width ) { squareWidth  = width;  }
   void setSquareHeight(double height) { squareHeight = height; }

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position & rhs, const Delta & delta) : colRow(rhs.colRow) { *this += delta; }
   void adjustRow(int dRow);
   void adjustCol(int dCol);
   Position& operator += (const Delta& rhs);
   Position  operator + (const Delta& rhs) const;

private:
   void set(uint8_t colRowNew) { }
   
   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;
};


ostream & operator << (ostream & out, const Position & pos);
istream & operator >> (istream & in,  Position & pos);
      
class PositionDummy : public Position
{
public:
   PositionDummy() : Position() { }
   virtual int getCol() const { assert(false); return -1; }
   virtual int getRow() const { assert(false); return -1; }
};

class PositionStub45 : public PositionDummy
{
public:
   PositionStub45() : PositionDummy() { }
   virtual int getCol() const { return 4; }
   virtual int getRow() const { return 5; }
};

class PositionStub44 : public PositionDummy
{
public:
   PositionStub44() : PositionDummy() {}
   virtual int getCol() const { return 4; }
   virtual int getRow() const { return 4; }
};
