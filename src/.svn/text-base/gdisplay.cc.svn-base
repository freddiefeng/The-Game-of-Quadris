#include <string>
#include "gdisplay.h"

using namespace std;

// Constructor
GDisplay::GDisplay(int windowWidth, int windowHeight)
{
  _windowWidth = windowWidth;
  _windowHeight = windowHeight;
  _XWindow = new Xwindow(_windowWidth, _windowHeight);
  _scale = GDisplay::scale; // Set scale to a default value
}

// Destructor
GDisplay::~GDisplay()
{
  delete _XWindow;
}

// Gets the current scale
int GDisplay::getScale()
{
  return _scale;
}

// Gets the sub window object
void GDisplay::setScale(int scale)
{
  _scale = scale;
}

// Sets the width of the board to display
void GDisplay::setBoardWidth(int width)
{
  _boardWidth = width;
}

// Sets the height of the board to display
void GDisplay::setBoardHeight(int height)
{
  _boardHeight = height;
}

// Gets poiter to the main window object
Xwindow* GDisplay::getXWindow()
{
  return _XWindow;
}

//Draws a single cell on the Xwindow
void GDisplay::drawCell(int x, int y, int color, int width, int height)
{
  _XWindow->fillRectangle(x*_scale, y*_scale, width*_scale, height*_scale, color);
}

//Undraws a single cell on the Xwindow
void GDisplay::undrawCell(int x, int y, int width, int height)
{
  _XWindow->fillRectangle(x*_scale, y*_scale, width*_scale, height*_scale, Xwindow::White);
}

// Draws the level on the display
void GDisplay::drawLevel(string sLevel)
{
  // Cleans out the original display
  for(int i = _boardWidth; i < _windowHeight / _scale + 1; i++)
    {
      _XWindow->fillRectangle(GDisplay::borderOffset + i * _scale, 0 * _scale, _scale, _scale, Xwindow::White);
    }

  _XWindow->drawString(_boardWidth * _scale + textOffset, 1 * _scale, sLevel);
}

// Draws the scores on the display
void GDisplay::drawScore(string sScore, string sHiScore)
{
  // Cleans out the orginal display
  for(int i = _boardWidth; i < _windowHeight / _scale + 1; i++)
    {
      _XWindow->fillRectangle(GDisplay::borderOffset + i * _scale, 1 * _scale, _scale, _scale, Xwindow::White);
      _XWindow->fillRectangle(GDisplay::borderOffset + i * _scale, 2 * _scale, _scale, _scale, Xwindow::White);
    }

  _XWindow->drawString(_boardWidth * _scale + textOffset, 2 * _scale, sScore);
  _XWindow->drawString(_boardWidth * _scale + textOffset, 3 * _scale, sHiScore);
}

// Draws the border of the board
void GDisplay::drawBorder()
{
  if(_boardHeight != 0 && _boardWidth != 0)
    {
      _XWindow->fillRectangle(_boardWidth * _scale, 0, GDisplay::borderOffset, 
		      _boardHeight * _scale + GDisplay::borderOffset);
      _XWindow->fillRectangle(0, _boardHeight * _scale, _boardWidth * _scale, 
		      GDisplay::borderOffset);
    }
}

//Clears the view
void GDisplay::clearView()
{
  delete _XWindow;
  _XWindow = new Xwindow(_windowHeight, _windowWidth);
}

