#include "rightshift.h"

// Constructor
RightShift::RightShift(Game* pGame) : Command(pGame)
{
}

// Method to execute a left-shift command in a game
void RightShift::Execute() {
  (_pGame->getCurrentBlock())->Shift_Right();
}
