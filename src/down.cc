#include "down.h"

// Constructor
Down::Down(Game* pGame) : Command(pGame)
{
}

// Method to execute a down command in a game
void Down::Execute() {
  (_pGame->getCurrentBlock())->Shift_Down();
}
