#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "block.h"

class JBlock : public Block {
  static const int _nRotateStates; // The number of rotating states
  // The encoded finite rotating states for J Blocks
  static const Coordinate _rotateStates[4][4];

 public:
  JBlock(char, Coordinate, int, Board*); // Constructor

  void initialize(); // Method to initialize the blockCoords for JBlock
};

#endif
