#ifndef __RESTART_H__
#define __RESTART_H__
#include "command.h"

class Restart : public Command {
 public:
  Restart(Game *pGame); // Constructor
  void Execute(); // Method to execute a restart command in a game
};

#endif
