#include "levelup.h"

// Constructor
LevelUp::LevelUp(Game* pGame) : Command(pGame)
{
}

// Method to execute level incrementation in the game.
void LevelUp::Execute() {
  _pGame->changeLevel(_pGame->getLevel()->getValue() + 1);
  _pGame->drawText();
}

