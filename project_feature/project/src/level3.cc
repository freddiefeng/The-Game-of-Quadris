#include <stdint.h>
#include "PRNG.h"
#include "level3.h"
#include "block.h"
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "tblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"

using namespace std;

// Constructor that sets Level's lvalue to 3.
Level3::Level3(uint32_t seed, GDisplay* pGDisplay) : Level(3, seed, pGDisplay) {
}

// Generate the next block in pseudorandom order, giving each s and z blocks a 2/9 chance
// of being generated, and every other block a 1/9 chance.
Block* Level3::getNextBlock(Coordinate coord, Board *pBoard) {
  uint32_t prNum = _pseudoRand() % 9; //Ensures a number from 0-11 is obtained.

  switch (prNum) {
    case 0u:                   //J (1/9 chance)
      return new JBlock('J', coord, 3, pBoard);
    case 1u:                   //L (1/9 chance)
      return new LBlock('L', coord, 3, pBoard);
    case 2u:                   //I (1/9 chance)
      return new IBlock('I', coord, 3, pBoard);
    case 3u:                   //O (1/9 chance)
      return new OBlock('O', coord, 3, pBoard);
    case 4u:                   //T (1/9 chance)
      return new TBlock('T', coord, 3, pBoard);
    case 5u:                   //S (2/9 chance)
    case 6u:
      return new SBlock('S', coord, 3, pBoard);
    case 7u:                   //Z (2/9 chance)
    case 8u:
      return new ZBlock('Z', coord, 3, pBoard);
    default:                   //Couldn't map, but will return something (and print message for DEBUG mode)
#if DEBUG
      cout << "PRNG produced a number beyond level 3's cap of 11!" << endl;
#endif
      return new JBlock('J', coord, 3, pBoard);
  }
}
