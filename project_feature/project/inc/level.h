#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <stdint.h>
#include "PRNG.h"
#include "component.h"
#include "board.h"
#include "coordinate.h"

class Board;
class Block;

class Level : public Component{
 protected:
  static PRNG _pseudoRand;  //Pseudo random number generator to generate the sequence of blocks.
  static bool _seedDefined; //Checks to see if seed has been defined. If so, don't let seed be reset.
  int _lvalue; // The value of level
 public:
  Level(int, GDisplay*);   //Constructor that accepts the value of the level
  Level(int, uint32_t, GDisplay*); // Constructor that accepts the value of the level and the seed for the PRNG.
  virtual ~Level(); // Destructor

  int getValue(); // Gets the value of level
  void setLevel(int); // Sets the value of level
  void drawText(); // Draws text to the standart output
  void drawGDisplay(); // Draws to the graphical display
  virtual Block* getNextBlock(Coordinate, Board*) = 0; // Pure virtual method to generate the next block depending on the level
};

#endif
