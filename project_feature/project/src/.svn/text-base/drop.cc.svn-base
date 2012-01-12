#include "drop.h"

// Constructor
Drop::Drop(Game* pGame) : Command(pGame)
{
}

//Method to execute the drop command in the game.
void Drop::Execute() {
  (_pGame->getCurrentBlock())->Fall();
  _pGame->generateNextBlock();
  _pGame->computeScore();

  //See if the game has ended as a result of trying to put the new block in.
  if (!(_pGame->getCurrentBlock())->canFit()) {
    _pGame->restart();  //If the game is over, restart it.
  }
}
