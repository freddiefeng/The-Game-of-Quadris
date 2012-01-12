#ifndef __CWISE_H__
#define __CWISE_H__
#include "command.h"

class Clockwise : public Command {
 public:
  Clockwise(Game* pGame); // Constructor
  void Execute(); // Method to execute a clockwise rotate command in a game
};

#endif
