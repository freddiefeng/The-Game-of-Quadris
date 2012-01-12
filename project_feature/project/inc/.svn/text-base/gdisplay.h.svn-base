#ifndef __GDISPLAY_H__
#define __GDISPLAY_H__
#include "window.h"

class GDisplay {
  Xwindow* _XWindow; // Pointer to the Xwindow Object
  int _scale; // Customizable Scale for proper visual display
  int _windowHeight; // The height of the Xwindow
  int _windowWidth; // The width of the Xwindow
  int _boardHeight; // The height of the board embedded inside the Xwindow
  int _boardWidth; // The width of the board embedded inside the Xwindow

 public:

  static const int mainWindowHeight = 500; // The height of main window
  static const int mainWindowWidth = 500; // The width of main window
  static const int subWindowHeight = 100; // The height of sub window
  static const int subWindowWidth = 100; // The height of main window
  static const int scale = 25; // The default scale
  static const int textOffset = 10; //The offset from the right side of board
					//to the beginning of score/level text.
  static const int borderOffset = 5; // The width of the boarder

  GDisplay(); // Default Constructor
  GDisplay(int, int);
  // Constructor that accepts pointer to the game
  ~GDisplay(); // Destructor

  int getScale(); // Gets the current scale
  void setScale(int); // Dynamically sets the scale of the window
  void setBoardWidth(int); // Sets the width of the board to display
  void setBoardHeight(int); // Sets the height of the board to display
  Xwindow* getXWindow(); // Gets poiter to the window object
  //Draws a single cell on the Xwindow
  void drawCell(int, int, int, int = 1, int = 1);
  //Undraws a single cell on the Xwindow
  void undrawCell(int, int, int = 1, int = 1);
  void drawLevel(std::string); // Draws the level on the display
  void drawScore(std::string, std::string); // Draws the scores on the display
  void drawBorder(); // Draws the boarder of the board
  void clearView(); // Clears the game view when restarted
};

#endif
