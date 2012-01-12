#include <math.h>
#include "game.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

using namespace std;

// Constructor
Game::Game(GDisplay* pMainBoardDisplay, GDisplay* pSubBoardDisplay, int level, uint32_t seed)
{
  _mainBoard = new Board(pMainBoardDisplay, mainBoardHeight, mainBoardWidth);

  //Set up the board graphically, if possible
  if (pMainBoardDisplay != NULL) pMainBoardDisplay->drawBorder();

  _subBoard = new Board(pSubBoardDisplay, subBoardHeight, subBoardWidth);
  _score = new Score(pMainBoardDisplay);
  _seed = seed;

  // Uses level to see what Level object to assign _level to
  if (level == 1) {
    _level = new Level1(_seed, pMainBoardDisplay);
  } else if (level == 2) {
    _level = new Level2(_seed, pMainBoardDisplay);
  } else if (level == 3) {
    _level = new Level3(_seed, pMainBoardDisplay);
  } else {
    _level = new Level0(pMainBoardDisplay); 
  }

  // Generates the current and next blocks
  _currentBlock = _level->getNextBlock((Coordinate){0, 3}, _mainBoard);
  _aliveBlocks.push_back(_currentBlock);
  _nextBlock = _level->getNextBlock((Coordinate){0, 3}, _subBoard);

  // Shows both blocks to the boards
  _currentBlock->Show();
  _nextBlock->Show();
  _level->drawGDisplay();
  _score->drawGDisplay();

  // Draws text to the standard output
  drawText();
}

// Destructor
Game::~Game()
{
  if(_mainBoard != NULL) delete _mainBoard;
  if(_subBoard != NULL) delete _subBoard;
  
  for(list<Block*>::iterator it = _aliveBlocks.begin(); it != _aliveBlocks.end(); it++)
    {
      delete *it;
    }

  if(_nextBlock != NULL) delete _nextBlock;

  if(_score != NULL) delete _score;
  if(_level != NULL) delete _level;
}

// Gets a pointer to the level object
Level* Game::getLevel()
{
  return _level;
}

// Gets a poiner to the current block
Block* Game::getCurrentBlock()
{
  return _currentBlock;
}

// Generates the next block
void Game::generateNextBlock()
{
  _nextBlock->undraw();  //Clears the old _nextBlock from the subwindow before doing anything else.
  _currentBlock = _nextBlock;
  _currentBlock->setBoard(_mainBoard, 0, 3);  //Changes the board currentBlock is in

  _aliveBlocks.push_back(_currentBlock); // Adds the new block to the block list
  _currentBlock->Show(); // Shows the current block on the display

  _nextBlock = _level->getNextBlock((Coordinate){0, 3}, _subBoard); // Generates the next block
  _nextBlock->Show(); // Shows the next block on the display
}

//Method to change the level of the game to the one specified as a parameter.
void Game::changeLevel(int nLevel) {
  //Set _level to be of a specific level subclass depending on the value of 
  //"nLevel"
  GDisplay* pGDisplay = _level->getDisplay();
  if (nLevel == 0) {
    delete _level;
    _level = new Level0(pGDisplay);  //Any value of "nLevel" that isn't the above is Level0
  } else if (nLevel == 1) {
    delete _level;
    _level = new Level1(_seed, pGDisplay);
  } else if (nLevel == 2) {
    delete _level;
    _level = new Level2(_seed, pGDisplay);
  } else if (nLevel == 3) {
    delete _level;
    _level = new Level3(_seed, pGDisplay);
  }

  _level->drawGDisplay();
}

// Computes the new score according to the state fo board and blocks alive
void Game::computeScore()
{
  // Reduces rows and compute the score accumulated through row reduction
  _mainBoard->reduceRows(_score, _level);

  /* Iterates through the list of blocks, removes empty blocks and computes the
     new score as a resulf of block reduction. */
  for(list<Block*>::iterator it = _aliveBlocks.begin(); it != _aliveBlocks.end();)
    {
      Block* pBlock = *it;

      if(pBlock->isEmpty())
	{
	  int blockLevel = pBlock->getLevel();
	  _score->Add(pow(blockLevel + 1, 2));

	  delete pBlock;
	  it = _aliveBlocks.erase(it);
	}
      else
	{
	  it++;
	}
    }

  _score->drawGDisplay();
}

// Restarts the game
void Game::restart()
{
  // Clears the main and sub boards
  _mainBoard->clearBoard();
  _subBoard->clearBoard();

  // Clears out the current block list and frees memories
  for(list<Block*>::iterator it = _aliveBlocks.begin(); it != _aliveBlocks.end(); it++)
    {
      (*it)->undraw();
      delete (*it);
    }

  _aliveBlocks.clear();

  // Undraws and clears the next block
  _nextBlock->undraw();
  delete _nextBlock;

  // Creates the new current and next blocks
  _currentBlock = _level->getNextBlock((Coordinate){0, 3}, _mainBoard);
  _aliveBlocks.push_back(_currentBlock);
  _nextBlock = _level->getNextBlock((Coordinate){0, 3}, _subBoard);

  _currentBlock->Show();
  _nextBlock->Show();

  // Reset the score
  _score->reset();
}

// Draws text to the standard output
void Game::drawText()
{
  _level->drawText();
  _score->drawText();
  cout << "----------" << endl;
  _mainBoard->drawText();
  cout << "----------" << endl;
  cout << "Next:" << endl;
  _subBoard->drawText();
  cout << endl;
}
