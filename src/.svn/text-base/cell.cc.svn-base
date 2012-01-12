#include "cell.h"

using namespace std;

// Constructor
Cell::Cell(GDisplay* pGDisplay, Coordinate coord, char symbol, int color, Block* pBlock) : Component(pGDisplay), _coord(coord), _symbol(symbol), _color(color), _block(pBlock)
{
}

// Overloaded assignment operator
// Note: that the coordinate of the cell is not copied
Cell& Cell::operator=(const Cell &cell)
{
  _symbol = cell._symbol;
  _color = cell._color;
  _occupied = cell._occupied;
  _block = cell._block;

  //Draw only if a display exists
  if (_gameDisplay != NULL) { 
    _gameDisplay->drawCell(_coord.xCoord, _coord.yCoord, _color);
  }

  return *this;
}

Cell::~Cell(){}

// Gets the symbol of the cell for text display
char Cell::getSymbol()
{
  return _symbol;
}

// Gets the coordinate of the cell
Coordinate Cell::getCoord()
{
  return _coord;
}

// Gets pointer to the block that the cell belongs to
Block* Cell::getBlock()
{
  return _block;
}

// Update the properties of the cell
Cell* Cell::updateCell(Block* block, char symbol, int color, bool occupied)
{
  _block = block;
  _symbol = symbol;
  _color = color;
  _occupied = occupied;

  //Draw only if a display exists
  if (_gameDisplay != NULL) { 
    _gameDisplay->drawCell(_coord.xCoord, _coord.yCoord, _color);
  }

  return this;
}

// Returns true if the cell is occupied
bool Cell::isOccupied()
{
  return _occupied;
}

// Clear the cell
void Cell::UnOccupy()
{
  // Remove one cell from the block it belongs to
  _block->removeCell();

  UnDraw(); 
}

// Draws text representation to standard output
void Cell::drawText()
{
  cout << _symbol;
}

//Method to undraw this cell.
void Cell::UnDraw() {
  _symbol = ' ';
  _color = Xwindow::White;
  _occupied = false;
  _block = NULL;

  //Undraw only if a display exists
  if (_gameDisplay != NULL) {
    _gameDisplay->undrawCell(_coord.xCoord, _coord.yCoord);
  }
}
