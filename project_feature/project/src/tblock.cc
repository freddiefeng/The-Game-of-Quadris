#include "tblock.h"
#include <vector>

// The number of rotating states
const int TBlock::_nRotateStates = 4;

// The encoded finite rotating states for T Blocks
const Coordinate TBlock::_rotateStates[4][4] =
{{(Coordinate){1,0}, (Coordinate){0,1}, (Coordinate){1,1}, (Coordinate){2,1}},
 {(Coordinate){0,1}, (Coordinate){1,0}, (Coordinate){1,1}, (Coordinate){1,2}},
 {(Coordinate){1,1}, (Coordinate){2,0}, (Coordinate){1,0}, (Coordinate){0,0}},
 {(Coordinate){1,1}, (Coordinate){0,0}, (Coordinate){0,1}, (Coordinate){0,2}}};

// Constructor
TBlock::TBlock(char symbol, Coordinate refCoord, int level, Board* pB) : Block(symbol, refCoord, level, pB)
{
  initialize();
}

//Method to initialize the blockCoords for TBlock
void TBlock::initialize() {
  _color = Xwindow::Cyan; // Use color Cyan for TBlock
  _symbol = 'T';

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
