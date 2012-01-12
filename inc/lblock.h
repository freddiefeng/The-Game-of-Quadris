#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"

class LBlock : public Block {
  static const int _nRotateStates; // The number of rotating states
  // The encoded finite rotating states for L Blocks
  static const Coordinate _rotateStates[4][4];

 public:
  LBlock(char, Coordinate, int, Board*); // Constructor

  void initialize(); // Method to initialize the blockCoords for LBlock
};

#endif
