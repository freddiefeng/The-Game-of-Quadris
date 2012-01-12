#include "lblock.h"
#include <vector>

// The number of rotating states
const int LBlock::_nRotateStates = 4;

// The encoded finite rotating states for L Blocks
const Coordinate LBlock::_rotateStates[4][4] = 
{{(Coordinate){0,0}, (Coordinate){1,0}, (Coordinate){2,0}, (Coordinate){2,1}},	
 {(Coordinate){1,0}, (Coordinate){0,0}, (Coordinate){0,1}, (Coordinate){0,2}},
 {(Coordinate){0,0}, (Coordinate){0,1}, (Coordinate){1,1}, (Coordinate){2,1}},
 {(Coordinate){0,2}, (Coordinate){1,2}, (Coordinate){1,1}, (Coordinate){1,0}}};

// Constructor
LBlock::LBlock(char symbol, Coordinate refCoord, int level, Board* pB) : Block(symbol, refCoord, level, pB)
{
  initialize();
}

//Method to initialize the blockCoords for LBlock
void LBlock::initialize() {
  _color = Xwindow::Blue; // Use blue color for LBlock
  _symbol = 'L';

  //Iterate through all rotate states
  for(int i = 0; i < _nRotateStates; i++) {
    std::vector<Coordinate> stateCoords;
    //Get all the Coordinates associated with that state.
    for (int j = 0; j < 4; j++) {
      stateCoords.push_back(_rotateStates[i][j]);
    }
    _blockCoords.push_back(stateCoords);
  }
}
