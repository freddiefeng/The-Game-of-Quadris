#ifndef __CELL_H__
#define __CELL_H__
#include "component.h"
#include "block.h"
#include "coordinate.h"

class Block;

class Cell : public Component {
 private:
  Coordinate _coord; // The coordinate of the cell
  char _symbol; // The symbol of the cell
  int _color; // The color of the cell
  bool _occupied; // Set to true if the block of which is on the pile
  Block* _block; // Pointer to the block the cell belongs to
 public:
  Cell(GDisplay*, Coordinate = (Coordinate){-1, -1}, char = ' ', int = Xwindow::White, Block* = NULL); // Constructor
  ~Cell(); // Destructor

  char getSymbol(); // Gets the symbol of the cell for text display
  Coordinate getCoord(); // Gets the coordinate of the cell
  Block* getBlock(); // Gets pointer to the block that the cell belongs to
  Cell* updateCell(Block*, char, int, bool = false); // Update the properties of the cell
  bool isOccupied(); // Returns true if the cell is occupied
  void UnOccupy(); // Clears the cell and removes itself from block
  void drawText(); // Draws text representation to standard output
  void UnDraw();  //Undraws this cell.
  Cell& operator=(const Cell &); // Overloaded assignment operator
};

#endif
