#include "component.h"

// Default constructor
Component::Component() : _gameDisplay(NULL)
{}

// Constructor
Component::Component(GDisplay* pGDisplay) : _gameDisplay(pGDisplay)
{}

// Copy Constructor
Component::Component(const Component &component)
{
  this->_gameDisplay = component._gameDisplay;
}

// Destructor
Component::~Component()
{}

// Gets pointer to the game display
GDisplay* Component::getDisplay()
{
  return _gameDisplay;
}
