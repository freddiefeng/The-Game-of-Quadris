#include <stdint.h>
#include "PRNG.h"
#include "level2.h"
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
Level2::Level2(uint32_t seed, GDisplay* pGDisplay) : Level(2, seed, pGDisplay) {
}

// Generate the next block in pseudorandom order, giving each block an equal 1/7 chance
// of being generated. 
Block* Level2::getNextBlock(Coordinate coord, Board *pBoard) {
  uint32_t prNum = _pseudoRand() % 7; //Ensures a number from 0-11 is obtained.

  //The following assigns each block with numbers that map to them. If one of a blocks'
  //numbers is generated, that block is returned for this function.
  switch (prNum) {
    case 0u:                   //J (1/7 chance)
      return new JBlock('J', coord, 2, pBoard);
    case 1u:                   //L (1/7 chance)
      return new LBlock('L', coord, 2, pBoard);
    case 2u:                   //I (1/7 chance)
      return new IBlock('I', coord, 2, pBoard);
    case 3u:                   //O (1/7 chance)
      return new OBlock('O', coord, 2, pBoard);
    case 4u:                   //T (1/7 chance)
      return new TBlock('T', coord, 2, pBoard);
    case 5u:                   //S (1/7 chance)
      return new SBlock('S', coord, 2, pBoard);
    case 6u:                   //Z (1/7 chance)
      return new ZBlock('Z', coord, 2, pBoard);
    default:                   //Couldn't map, but will return something (and print message for DEBUG mode)
#if DEBUG
      cout << "PRNG produced a number beyond level 2's cap of 6!" << endl;
#endif
      return new JBlock('J', coord, 2, pBoard);
  }
}
