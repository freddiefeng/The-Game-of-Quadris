#include "zblock.h"
#include <vector>

// The number of rotating states
const int ZBlock::_nRotateStates = 2;

// The encoded finite rotating states for Z Blocks
const Coordinate ZBlock::_rotateStates [2][4] =
{{(Coordinate){2,0}, (Coordinate){1,0}, (Coordinate){1,1}, (Coordinate){0,1}},
 {(Coordinate){0,0}, (Coordinate){0,1}, (Coordinate){1,1}, (Coordinate){1,2}}};

// Constructor
ZBlock::ZBlock(char symbol, Coordinate refCoord, int level, Board* pB) : Block(symbol, refCoord, level, pB)
{
  initialize();
}

//Method to initialize the blockCoords for ZBlock
void ZBlock::initialize() {
  _color = Xwindow::Yellow; // Use color yellow for ZBlock
  _symbol = 'Z';

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
