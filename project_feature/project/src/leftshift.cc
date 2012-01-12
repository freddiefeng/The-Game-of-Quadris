#include "leftshift.h"

// Constructor
LeftShift::LeftShift(Game* pGame) : Command(pGame)
{
}

//Method to execute a left-shift command in a game
void LeftShift::Execute() {
  (_pGame->getCurrentBlock())->Shift_Left();
}

