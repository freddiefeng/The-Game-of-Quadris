#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"

class OBlock : public Block {
  static const int _nRotateStates; // The number of rotating states
  // The encoded finite rotating states for O Blocks
  static const Coordinate _rotateStates[1][4];

 public:
  OBlock(char, Coordinate, int, Board*); // Constructor

  void initialize(); // Method to initialize the blockCoords for OBlock
};

#endif
