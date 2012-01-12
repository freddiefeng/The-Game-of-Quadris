#include "jblock.h"
#include <vector>

// The number of rotating states
const int JBlock::_nRotateStates = 4;

// The encoded finite rotating states for J Blocks
const Coordinate JBlock::_rotateStates[4][4] =
{{(Coordinate){0,1}, (Coordinate){0,0}, (Coordinate){1,0}, (Coordinate){2,0}},
 {(Coordinate){1,2}, (Coordinate){0,2}, (Coordinate){0,1}, (Coordinate){0,0}},
 {(Coordinate){2,0}, (Coordinate){2,1}, (Coordinate){1,1}, (Coordinate){0,1}},
 {(Coordinate){0,0}, (Coordinate){1,0}, (Coordinate){1,1}, (Coordinate){1,2}}};

// Constructor
JBlock::JBlock(char symbol, Coordinate refCoord, int level, Board* pB) : Block(symbol, refCoord, level, pB)
{
  initialize();
}

//Method to initialize the blockCoords for JBlock
void JBlock::initialize() {
  _color = Xwindow::Green; // Use green colour for JBlock
  _symbol = 'J';
  
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
