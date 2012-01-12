#ifndef __CMD_H__
#define __CMD_H__
#include "game.h"

class Command {
 protected:
  Game* _pGame; // Pointer to the game object
 public:
  Command(Game* pGame); // Constructor that takes pointer to game object as paramenter
  ~Command(); // Destructor

  virtual void Execute() = 0; // Pure virtual function to be overloaded by Concrete classes
};

#endif
