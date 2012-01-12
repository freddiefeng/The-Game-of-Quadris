#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"

class SBlock : public Block {
  static const int _nRotateStates; // The number of rotating states
  // The encoded finite rotating states for S Blocks
  static const Coordinate _rotateStates[2][4];

 public:
  SBlock(char, Coordinate, int, Board*); // Constructor

  void initialize(); // Method to initialize the blockCoords for SBlock
};

#endif
