#include <math.h>
#include "board.h"

using namespace std;

// Constructor
Board::Board(GDisplay* pGDisplay, int boardHeight, int boardWidth) : Component(pGDisplay)
{
  this->_boardHeight = boardHeight;
  this->_boardWidth = boardWidth;

  // Only set _gameDisplay properties if truly exists
  if (_gameDisplay != NULL) {
    _gameDisplay->setBoardWidth(boardWidth);
    _gameDisplay->setBoardHeight(boardHeight);
  }

  // Allocates memory space for the grid and cells
  grid = new Cell**[boardWidth];
  for(int i = 0; i < boardWidth; i++)
    {
      grid[i] = new Cell*[boardHeight];
      for(int j = 0; j < boardHeight; j++)
	{
	  grid[i][j] = new Cell(pGDisplay, (Coordinate){i, j});
	}
    }
}

// Destructor
Board::~Board()
{
  for(int i = 0; i < _boardWidth; i++)
    {
      for(int j = 0; j < _boardHeight; j++)
	{
	  delete grid[i][j];
	}
    }

  for(int i = 0; i < _boardWidth; i++)
    {
      delete [] grid[i];
    }

  delete [] grid;
}

// Gets pointer to the cell specified by the coordinate
Cell* Board::getCell(Coordinate coord)
{
  int x = coord.xCoord;
  int y = coord.yCoord;

  if((0 <= x && x < _boardWidth) || (0 <= y && y < _boardHeight))
    {
      return grid[x][y];
    }
  else
    {
      // Returns NULL if the coordinate is out of bound
      return NULL;
    }
}

// Returns true if the inquired cell is not occupied and within bound
bool Board::isAvailable(Coordinate coord)
{
  int x = coord.xCoord;
  int y = coord.yCoord;

  if(0 > x || x >= _boardWidth || 0 > y || y >= _boardHeight)
    return false;

  return !grid[coord.xCoord][coord.yCoord]->isOccupied();
}

// Returns true if the inquired row is full
bool Board::isRowFull(int row)
{
  for(int i = 0; i < _boardWidth; i++)
    {
      if(!grid[i][row]->isOccupied())
	return false;
    }

  return true;
}

// Delete the row of given number
void Board::deleteRow(int row)
{
  for(int i = 0; i < _boardWidth; i++)
    {
      grid[i][row]->UnOccupy();
    }

  int columnTop = _boardHeight; // Temporary variable to hold the index of column top

  for(int i = 0; i < _boardWidth; i++)
    {
      // Finds the top of the underlying pile in each column
      for(int j = 0; j < _boardHeight; j++)
	{
	  if(grid[i][j]->isOccupied())
	    {
	      columnTop = j;
	      break;
	    }
	}

      // Shifts cells down by one in the column above the deleted row
      for(int k = row - 1; k >= columnTop; k--)
	{
	  *(grid[i][k+1]) = *(grid[i][k]);
	  grid[i][k]->UnDraw();
	}
    }
}

// Reduces the rows to compute the score
void Board::reduceRows(Score* pScore, Level* pLevel)
{
  int nReducedRows = 0;

  // Removes rows and counts the numberof rows reduced
  for(int i = _boardHeight - 1; i >= 0; i--)
    {
      while(isRowFull(i))
	{
	  nReducedRows++;
	  deleteRow(i);
	} 
    }

  //Only add to the score if the dropped block cleared a line
  if (nReducedRows > 0) {
    pScore->Add(pow(nReducedRows + pLevel->getValue(), 2));
  }
}

// Clears the whole board
void Board::clearBoard()
{
  for(int i = 0; i < _boardWidth; i++)
    {
      for(int j = 0; j < _boardHeight; j++)
	{ 
	  grid[i][j]->UnDraw();
	}
    }
}

// Draws text to the standard output
void Board::drawText()
{
  for(int j = 0; j < _boardHeight; j++)
    {
      for(int i = 0; i < _boardWidth; i++)
	{
	  grid[i][j]->drawText();
	}
      cout << endl;
    }
}

//Method to return the height of this board.
int Board::getHeight() {
  return _boardHeight;
}

//Method to return the width of this board
int Board::getWidth() {
  return _boardWidth;
}
