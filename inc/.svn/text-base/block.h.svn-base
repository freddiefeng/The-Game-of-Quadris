#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <vector>
#include <list>
#include "board.h"
#include "coordinate.h"
#include "cell.h"

class Board;
class Cell;

class Block {
 protected:
  char _symbol; // The symbol of the block
  // The reference coordinate of the block, by default it is the left bottom corner
  Coordinate _refCoord;

  std::vector<std::vector<Coordinate > > _blockCoords; //matrix of coordinates of each cell of the block.
  std::list<Cell*> _cells; // The list of references to cells that make up the block
  int _cellCount;
  int _rState; // The rotate state of the block
  int _level; // The level at which the block is generated
  int _color; // The color of the block
  Board *_pBoard;  //Board in which this current block is in.

  void initialize();

 public:
  // Constructor that accepts the symbol, reference coordinate, level, and board as input
  Block(char, Coordinate, int, Board*);
  virtual ~Block(); // Destructor

  int getLevel(); // Gets the level of the block
  void setBoard(Board*, int, int); // Change the board in which this block appears in.
  void removeCell(); // Removes the reference to the cell from the cell list
  bool canFit();  // Returns true if block can fit in its current position (doesn't overlap others)
  bool isEmpty(); // Returns true if all the cells are removed
  void Rotate_CW(); // Rotates the block in clockwise direction
  void Rotate_CCW(); // Rotates the block in clockwise direction
  void Fall(); // Drops the block to the pile
  void Shift_Left(); // Shifts the block to the left
  void Shift_Right(); // Shifts the block to the right
  void Shift_Down(); // Shifts the block down
  void Show(); // Shows the block on the board
  void undraw(); //Method to undraw this block
  Block &operator=(const Block &); // Overloaded assignment operator
};

#endif
