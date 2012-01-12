#ifndef __COMPONENT_H__
#define __COMPONENT_H__
#include "gdisplay.h"

class Component {
 protected:
  GDisplay* _gameDisplay; // Pointer to the gdisplay object
 public:
  Component(); // Default constructor
  Component(GDisplay*); // Constructor
  Component(const Component &); // Copy constructor
  virtual ~Component(); // Destructor

  GDisplay* getDisplay(); // Gets pointer to the game display
  virtual void drawText() = 0; // Draws object to the text display
};

#endif
