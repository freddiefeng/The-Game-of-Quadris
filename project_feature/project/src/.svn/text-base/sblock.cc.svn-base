#include "sblock.h"
#include <vector>

// The number of rotating states
const int SBlock::_nRotateStates = 2;

// The encoded finite rotating states for S Blocks
const Coordinate SBlock::_rotateStates[2][4] = 
{{(Coordinate){0,0}, (Coordinate){1,0}, (Coordinate){1,1}, (Coordinate){2,1}},
 {(Coordinate){0,2}, (Coordinate){0,1}, (Coordinate){1,1}, (Coordinate){1,0}}};

// Constructor
SBlock::SBlock(char symbol, Coordinate refCoord, int level, Board* pB) : Block(symbol, refCoord, level, pB)
{
  initialize();
}

//Method to initialize the blockCoords for SBlock
void SBlock::initialize() {
  _color = Xwindow::Magenta; // Use color magenta for SBlock
  _symbol = 'S';

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
