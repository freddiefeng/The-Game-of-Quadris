#ifndef __LEVEL0_H__
#define __LEVEL0_H__
#include "level.h"
#include <string>
#include <vector>

class Level0 : public Level{
  std::vector<std::string> _sequence;  //Fixed sequence that the blocks are made with
  static int curChar;             //Current item in sequence to create. It is never reset unless it reaches the size
                                        //of the above sequence.

 public:
  Level0(GDisplay*); // Constructor that sets Level's lvalue to 0.

  Block* getNextBlock(Coordinate, Board*); // Generate the next block in fixed order.
};

#endif
