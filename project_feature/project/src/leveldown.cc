#include "leveldown.h"

// Constructor
LevelDown::LevelDown(Game* pGame) : Command(pGame)
{
}

//Method to execute level decrementation in the game.
void LevelDown::Execute() {
  _pGame->changeLevel(_pGame->getLevel()->getValue() - 1);
  _pGame->drawText();
}

