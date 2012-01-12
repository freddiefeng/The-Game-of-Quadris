#include "clockwise.h"

// Constructor
Clockwise::Clockwise(Game* pGame) : Command(pGame)
{
}

// Method to execute a clockwise rotate command in a game
void Clockwise::Execute(){
  (_pGame->getCurrentBlock())->Rotate_CW();
}
