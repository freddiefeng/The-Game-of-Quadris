#include <vector>
#include "iblock.h"

// The number of rotating states
const int IBlock::_nRotateStates = 4;

// The encoded finite rotating states for I Blocks
const Coordinate IBlock::_rotateStates[4][4] = 
{{(Coordinate){0,0}, (Coordinate){1,0}, (Coordinate){2,0}, (Coordinate){3,0}},
 {(Coordinate){0,3}, (Coordinate){0,2}, (Coordinate){0,1}, (Coordinate){0,0}},
 {(Coordinate){0,0}, (Coordinate){1,0}, (Coordinate){2,0}, (Coordinate){3,0}},
 {(Coordinate){0,3}, (Coordinate){0,2}, (Coordinate){0,1}, (Coordinate){0,0}}};

IBlock::IBlock(char symbol, Coordinate refCoord, int level, Board* pB) : Block(symbol, refCoord, level, pB)
{
  initialize();
}

//Method to initialize the blockCoords for IBlock
void IBlock::initialize() {
  _color = Xwindow::Red; // Use red color for IBlock
  _symbol = 'I';
  
  //Iterate through all rotate states
  for(int i = 0; i < _nRotateStates; i++) {
    std::vector<Coordinate> stateCoords;
    //Get all the Coordinates associated with that state.
    for (int j = 0; j < 4; j++) {
      stateCoords.push_back((Coordinate)_rotateStates[i][j]);
    }
    _blockCoords.push_back(stateCoords);
  }
}
