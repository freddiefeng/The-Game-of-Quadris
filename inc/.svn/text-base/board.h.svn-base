#ifndef __BOARD_H__
#define __BOARD_H__
#include "component.h"
#include "coordinate.h"
#include "cell.h"
#include "score.h"
#include "level.h"

class Cell;
class Level;

class Board : public Component{
  Cell*** grid; // The grid of pointers to cells
  int _boardHeight; // The height of the board
  int _boardWidth; // The width of the board
  
  void deleteRow(int); // Deletes the row of given number

 public:
  Board(GDisplay*, int, int); // Constructor
  ~Board(); // Destructor

  Cell* getCell(Coordinate); // Gets pointer to the cell specified by the coordinate
  bool isAvailable(Coordinate); // Returns true if the inquired cell is not occupied and within bound
  bool isRowFull(int); // Returns true if the inquired row is full
  void reduceRows(Score*, Level*); // Reduces the rows to compute the score
  void clearBoard(); // Clears the whole board
  void drawText(); // Draws text to the standard output
  int getHeight();  //Method to retrieve this board's height
  int getWidth();   //Method to retrieve this board's width
};

#endif
