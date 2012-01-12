#include "block.h"

using namespace std;

// Constructor that accepts the symbol, reference coordinate, level, and board as input
Block::Block(char symbol, Coordinate refCoord, int level, Board* pB) : _symbol(symbol),
							               _refCoord(refCoord),
							               _level(level),
                                                                       _pBoard(pB)
{
  initialize();
}

// Destructor
Block::~Block()
{
}

//Method to initialize the blockCoords matrix. For block, it just creates a new
//empty one.
void Block::initialize() {
  _rState = 0;
  _cellCount = 4; // Initialize the number of cells to four
}

// Gets the level of the block
int Block::getLevel()
{
  return _level;
}


//Method to change the board in which this block appears in, along with the location it is in on the board.
void Block::setBoard(Board *pBoard, int xCoord, int yCoord) {
  _pBoard = pBoard;
  _refCoord.xCoord = xCoord;
  _refCoord.yCoord = yCoord;

  //The old cells refer to the old board; get new cells
  _cells.clear();

  Coordinate newCoord;
  for(int i = 0; i < 4; i++)
    {
      newCoord = (Coordinate){_refCoord.xCoord + _blockCoords[_rState][i].xCoord,
                  _refCoord.yCoord - _blockCoords[_rState][i].yCoord};
      Cell* curCell = _pBoard->getCell(newCoord);  //Cell to update

     //Keep the old occupied statuses for this cell, as it could be that the game is trying
     //to put this block on a block stack that is too high.
     _cells.push_back(curCell->updateCell(this, _symbol, _color, curCell->isOccupied()));
 
    }
}

// Removes the reference to the cell from the cell list
void Block::removeCell()
{
  _cellCount--;
}

//Method to determine if the block can fit in its current position. Mostly used to determine
//if the game's block pile has stacked far too much to allow any more new blocks in. Thus,
//this also acts as an indicator for the end of the game.
bool Block::canFit() {
  //Check if this block's unaltered cells are occupied.
  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    {
      Coordinate coord = (*it)->getCoord();

      if(!_pBoard->isAvailable((Coordinate){coord.xCoord, coord.yCoord}))
	{
	  return false;
	}
    }
  return true;
}

// Returns true if all the cells are removed
bool Block::isEmpty()
{
  return (_cellCount == 0);
}

// Drops the block to the pile
void Block::Fall()
{
  int minGap = _pBoard->getHeight();
  int index;

  // Computes the minimun gap between the cells to the pile of cells below
  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    {
      Coordinate coord = (*it)->getCoord();

      for(index = coord.yCoord; index < _pBoard->getHeight(); index++)
	{
	  // Finds the first occupied cell below the current cell/bottom cell  in the same column
	  if(!_pBoard->isAvailable((Coordinate){coord.xCoord, index}))
	    {
	      break;
	    }
	}
      // Updates the minimal gap between the cells in the block and the pile of cells below
      if(minGap > index - coord.yCoord - 1)
	{
	  minGap = index - coord.yCoord - 1;
	}
    }

  Coordinate oldCoord;
  vector<Coordinate> newCoords;

  if(minGap != _pBoard->getHeight())
    {
      for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
	{
	  // Compute the coordinate of the dropped cell
	  oldCoord = (*it)->getCoord();
	  newCoords.push_back((Coordinate){oldCoord.xCoord, oldCoord.yCoord + minGap});

	  // Clears the cell on the actual board
	  (*it)->UnDraw();
	}

      _cells.clear();

      for(vector<Coordinate>::iterator it = newCoords.begin(); it != newCoords.end(); it++)
	{
	  // Sets the new cell through the board
	  // and insert its address to the cell list
	  Cell* pCell = _pBoard->getCell(*it);
	  _cells.push_back(pCell->updateCell(this, _symbol, _color, true));
	}

      // Update the reference coordinate
      _refCoord.yCoord += minGap;
    }
}
// Rotates the block in clockwise direction
void Block::Rotate_CW(){
  int newRState = (_rState + 1) % (_blockCoords.size());  //Get next rotate state (0 to states size -1).

  //See if the cells in the new state are available to move into.
  for(int i = 0; i < 4; i++)
    {
      if(!_pBoard->isAvailable((Coordinate){_refCoord.xCoord + _blockCoords[newRState][i].xCoord,
                                           _refCoord.yCoord - _blockCoords[newRState][i].yCoord}))
	{
	  return;  //If not, no move can be made.
	}
    }

  Coordinate newCoord;

  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    {
      // Clears the cell on the actual board
      (*it)->UnDraw();
    }

  _cells.clear();

  //If the block can rotate, set the cells to their new positions.
  for(int i = 0; i < 4; i++)
    {
      newCoord = (Coordinate){_refCoord.xCoord + _blockCoords[newRState][i].xCoord,
                  _refCoord.yCoord - _blockCoords[newRState][i].yCoord};

      // Sets the new cell through the board
      // and insert its address to the cell list
      _cells.push_back((_pBoard->getCell(newCoord))->updateCell(this, _symbol, _color));
 
    }

  _rState = newRState;
}

// Rotates the block in clockwise direction
void Block::Rotate_CCW() {
  //Get the next rotate state (subtract by 1 to rotate counterclockwise).
  int newRState = _rState - 1;
  if (newRState < 0) {  //In case newRState became -1. change to be the last state, instead.
    newRState = _blockCoords.size()  - 1;
  }

  //See if the cells in the new state are available to move into.
  for(int i = 0; i < 4; i++)
    {
      if(!_pBoard->isAvailable((Coordinate){_refCoord.xCoord + _blockCoords[newRState][i].xCoord,
                                           _refCoord.yCoord - _blockCoords[newRState][i].yCoord}))
	{
	  return;  //If not, no move can be made.
	}
    }

  Coordinate newCoord;

  //Unoccupy and clear all the cells in _cells
  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    { 
      // Clears the cell on the actual board
      (*it)->UnDraw();
    }

  _cells.clear();

  //If the block can rotate, set the cells to their new positions.
  for(int i = 0; i < 4; i++)
    {
      newCoord = (Coordinate){_refCoord.xCoord + _blockCoords[newRState][i].xCoord,
                  _refCoord.yCoord - _blockCoords[newRState][i].yCoord};

      // Sets the new cell through the board
      // and insert its address to the cell list
      _cells.push_back((_pBoard->getCell(newCoord))->updateCell(this, _symbol, _color));
    }

  _rState = newRState;
}  

// Shifts the block to the right
void Block::Shift_Right()
{
  // Checks if right shift is possible
  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    {
      Coordinate coord = (*it)->getCoord();

      if(!_pBoard->isAvailable((Coordinate){coord.xCoord + 1, coord.yCoord}))
	{
	  return;
	}
    }

  Coordinate oldCoord;
  vector<Coordinate> newCoords;

  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    {
      // Compute the coordinate of the dropped cell
      oldCoord = (*it)->getCoord();
      newCoords.push_back((Coordinate){oldCoord.xCoord + 1, oldCoord.yCoord});

      // Clears the cell on the actual board
      (*it)->UnDraw();
    }

  _cells.clear();

  for(vector<Coordinate>::iterator it = newCoords.begin(); it != newCoords.end(); it++)
    {
      // Sets the new cell through the board
      // and insert its address to the cell list
      Cell* pCell = _pBoard->getCell(*it);
      _cells.push_back(pCell->updateCell(this, _symbol, _color));
    }

  // Update the reference coordinate
  _refCoord.xCoord++;
}

// Shifts the block to the left
void Block::Shift_Left()
{
  // Checks if left shift is possible
  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    {
      Coordinate coord = (*it)->getCoord();

      if(!_pBoard->isAvailable((Coordinate){coord.xCoord - 1, coord.yCoord}))
	{
	  return;
	}
    }

  Coordinate oldCoord;
  vector<Coordinate> newCoords;

  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    {
      // Compute the coordinate of the dropped cell
      oldCoord = (*it)->getCoord();
      newCoords.push_back((Coordinate){oldCoord.xCoord - 1, oldCoord.yCoord});

      // Clears the cell on the actual board
      (*it)->UnDraw();
    }

  _cells.clear();

  for(vector<Coordinate>::iterator it = newCoords.begin(); it != newCoords.end(); it++)
    {
      // Sets the new cell through the board
      // and insert its address to the cell list
      Cell* pCell = _pBoard->getCell(*it);
      _cells.push_back(pCell->updateCell(this, _symbol, _color));
    }


  // Update the reference coordinate
  _refCoord.xCoord--;
}

// Shifts the block down
void Block::Shift_Down()
{
  // Checks if shifting downward is possible
  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    {
      Coordinate coord = (*it)->getCoord();

      if(!_pBoard->isAvailable((Coordinate){coord.xCoord, coord.yCoord + 1}))
	{
	  return;
	}
    }

  Coordinate oldCoord;
  vector<Coordinate> newCoords;

  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    {
      // Compute the coordinate of the dropped cell
      oldCoord = (*it)->getCoord();
      newCoords.push_back((Coordinate){oldCoord.xCoord, oldCoord.yCoord + 1});

      // Clears the cell on the actual board
      (*it)->UnDraw();
    }

  _cells.clear();

  for(vector<Coordinate>::iterator it = newCoords.begin(); it != newCoords.end(); it++)
    {
      // Sets the new cell through the board
      // and insert its address to the cell list
      Cell* pCell = _pBoard->getCell(*it);
      _cells.push_back(pCell->updateCell(this, _symbol, _color));
    }

  // Update the reference coordinate
  _refCoord.yCoord++;
}

void Block::Show()
{
  vector<Coordinate> stateSet = _blockCoords[_rState]; // Current Rotation states
  Coordinate absCoord;

  for(vector<Coordinate>::iterator it = stateSet.begin(); it != stateSet.end(); it++)
    {
      // Computates the absolute coordinate
      absCoord = (Coordinate){_refCoord.xCoord + (*it).xCoord, 
			      _refCoord.yCoord - (*it).yCoord};
      Cell* curCell = _pBoard->getCell(absCoord);  //Current cell to add to cell list.

      _cells.push_back(curCell->updateCell(this, _symbol, _color, curCell->isOccupied()));
    }
}

//Method to undraw this block
void Block::undraw() {
  for(list<Cell*>::iterator it = _cells.begin(); it != _cells.end(); it++)
    {
      (*it)->UnDraw();
    }
}
