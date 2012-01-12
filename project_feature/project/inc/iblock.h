#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"

class IBlock : public Block {
  static const int _nRotateStates; // The number of rotating states
  // The encoded finite rotating states for I Blocks
  static const Coordinate _rotateStates[4][4];

 public:
  IBlock(char, Coordinate, int, Board*); // Constructor

  void initialize(); // Method to initialize the blockCoords for IBlock;
};

#endif
