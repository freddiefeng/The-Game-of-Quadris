#ifndef __DROP_H__
#define __DROP_H__

#include "command.h"

class Drop : public Command {
 public:
  Drop(Game* pGame); // Constructor
  void Execute();
};
#endif
