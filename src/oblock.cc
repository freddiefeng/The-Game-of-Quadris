#include "oblock.h"
#include <vector>

// The number of rotating states
const int OBlock::_nRotateStates = 1;

// The encoded finite rotating states for O Blocks
const Coordinate OBlock::_rotateStates [1][4] = 
  {{(Coordinate){0,0}, (Coordinate){1,0}, (Coordinate){1,1}, (Coordinate){0,1}}};

// Constructor
OBlock::OBlock(char symbol, Coordinate refCoord, int level, Board* pB) : Block(symbol, refCoord, level, pB)
{
  initialize();
}

//Method to initialize the blockCoords for OBlock
void OBlock::initialize() {
  _color = Xwindow::Orange; // Use color orange for OBlock
  _symbol = 'O';

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
