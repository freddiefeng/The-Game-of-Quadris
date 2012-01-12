#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"

class TBlock : public Block {
  static const int _nRotateStates; // The number of rotating states
  // The encoded finite rotating states for T Blocks
  static const Coordinate _rotateStates[4][4];

 public:
  TBlock(char, Coordinate, int, Board*); // Constructor

  void initialize(); // Method to initialize the blockCoords for TBlock
};

#endif
