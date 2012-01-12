#ifndef __CCWISE_H__
#define __CCWISE_H__
#include "command.h"

class CounterClockwise : public Command {
 public:
  CounterClockwise(Game* pGame); // Constructor
  void Execute(); // Method to execute a counter clockwise rotate command in a game
};

#endif
