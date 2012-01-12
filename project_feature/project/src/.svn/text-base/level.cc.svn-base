#include <iostream>
#include <iomanip>
#include <sstream>
#include "level.h"

using namespace std;

PRNG Level::_pseudoRand;
bool Level::_seedDefined = false;

// Constructor that accepts the value of the level
Level::Level(int level, GDisplay* pGDisplay) : Component(pGDisplay)
{
    _lvalue = level;
}

// Constructor that accepts the value of the level and the PRNG seed
Level::Level(int level, uint32_t seed, GDisplay* pGDisplay) : Component(pGDisplay)
{
  _lvalue = level;

  //Only set the seed if it hasn't been defined.
  if (!_seedDefined) {
  _pseudoRand.seed(seed);
    _seedDefined = true;
  }
}

// Destructor
Level::~Level()
{}

// Gets the value of level
int Level::getValue()
{
  return _lvalue;
}

// Sets the value of level
void Level::setLevel(int level)
{
  _lvalue = level;
}

// Draws text to the standart output
void Level::drawText()
{
  cout << "Level:" << setw(7) << _lvalue << endl;
}

//Method to draw the level onto the display
void Level::drawGDisplay()
{
  if (_gameDisplay != NULL) {
    stringstream ss;
    ss << "Level:" << setw(7) << _lvalue;
    _gameDisplay->drawLevel(ss.str());
  }
}
