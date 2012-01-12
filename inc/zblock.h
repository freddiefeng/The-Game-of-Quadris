#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"

class ZBlock : public Block {
  static const int _nRotateStates; // The number of rotating states
  // The encoded finite rotating states for Z Blocks
  static const Coordinate _rotateStates[2][4];

 public:
  ZBlock(char, Coordinate, int, Board*); // Constructor

  void initialize(); // Method to initialize the blockCoords for ZBlock
};

#endif
