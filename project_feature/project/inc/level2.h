#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include "level.h"
#include "PRNG.h"
#include <string>
#include <vector>
#include <stdint.h>

class Level2 : public Level{
 public:
  Level2(uint32_t, GDisplay*); // Constructor that sets Level's lvalue to 0.

  Block* getNextBlock(Coordinate, Board*); // Generate the next block in fixed order.
};

#endif
