#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include "level.h"
#include "PRNG.h"
#include <string>
#include <vector>
#include <stdint.h>

class Level1 : public Level{
 public:
  Level1(uint32_t, GDisplay*); // Constructor that sets Level's lvalue to 0.

  Block* getNextBlock(Coordinate, Board*); // Generate the next block in fixed order.
};

#endif
