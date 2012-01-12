#ifndef __GAME_H__
#define __GAME_H__
#include <stdint.h>
#include "component.h"
#include "level.h"
#include "board.h"
#include "score.h"
#include "gdisplay.h"

class Game : public Component{
  uint32_t _seed;    //The seed to use for the levels (if they need them).
  Board* _mainBoard; // The main board
  Board* _subBoard; // The sub board which shows the next block
  Block* _currentBlock; // The current block
  Block* _nextBlock; // The next block
  Score* _score; // The score
  std::list<Block*> _aliveBlocks; // An list of active blocks on the main board
  Level* _level; // The level object

  static const int mainBoardHeight = 18; // The height of main board
  static const int mainBoardWidth = 10; // The width of main board
  static const int subBoardHeight = 4; // The height of sub board
  static const int subBoardWidth = 4; // The height of main board
 public:
  Game(GDisplay*, GDisplay*, int, uint32_t); // Constructor
  ~Game(); // Destructor

  Level* getLevel(); // Gets a pointer to the level object
  Block* getCurrentBlock(); // Gets a poiner to the current block
  void generateNextBlock(); // Generates the next block
  void changeLevel(int); // Method to change the level of the game to the one specified as a parameter
  void computeScore(); // Computes the new score according to the state fo board and blocks alive
  void restart(); // Restarts the game
  void drawText(); // Draws text to the standard output
};

#endif
