#include <stdint.h>
#include "PRNG.h"
#include "level1.h"
#include "block.h"
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "tblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"

// Constructor that sets Level's lvalue to 1.
Level1::Level1(uint32_t seed, GDisplay* pGDisplay) : Level(1, seed, pGDisplay) {
}

// Generate the next block in pseudorandom order, giving s and z blocks a 1/12 chance
// of being generated, and every other block a 1/12 change.
Block* Level1::getNextBlock(Coordinate coord, Board *pBoard) {
  uint32_t prNum = _pseudoRand() % 12; //Ensures a number from 0-11 is obtained.

  switch (prNum) {
    case 0u:                   //J (1/6 chance)
    case 1u:
      return new JBlock('J', coord, 1, pBoard);
    case 2u:                   //L (1/6 chance)
    case 3u:
      return new LBlock('L', coord, 1, pBoard);
    case 4u:                   //I (1/6 chance)
    case 5u:
      return new IBlock('I', coord, 1, pBoard);
    case 6u:                   //O (1/6 chance)
    case 7u:
      return new OBlock('O', coord, 1, pBoard);
    case 8u:                   //T (1/6 chance)
    case 9u:
      return new TBlock('T', coord, 1, pBoard);
    case 10u:                   //S (1/12 chance)
      return new SBlock('S', coord, 1, pBoard);
    case 11u:                   //Z (1/12 chance)
      return new ZBlock('Z', coord, 1, pBoard);
    default:                   //Couldn't map, but will return something (and print message for DEBUG mode)
#if DEBUG
      cout << "PRNG produced a number beyond level 1's cap of 11!" << endl;
#endif
      return new JBlock('J', coord, 1, pBoard);
  }
}
