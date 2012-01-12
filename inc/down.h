#ifndef __DOWN_H__
#define __DOWN_H__
#include "command.h"

class Down : public Command {
 public:
  Down(Game* pGame); // Constructor
  void Execute(); // Method to execute a down command in a game
};

#endif
