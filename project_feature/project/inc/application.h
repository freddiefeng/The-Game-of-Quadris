#ifndef __APP_H__
#define __APP_H__
#include <stdint.h>
#include "game.h"
#include "levelup.h"
#include "leveldown.h"
#include "leftshift.h"
#include "rightshift.h"
#include "down.h"
#include "restart.h"
#include "drop.h"
#include "clockwise.h"
#include "counterclockwise.h"
#include "commandinterpreter.h"
#include "gdisplay.h"

class Application {
  bool _isTextOnly; // Set to true if only text display is needed
  uint32_t _seed; // Holds the seed of the generator
  Game* _game; // Pointer to the Game object
  CommandInterpreter* _commandInterpreter; // Pointer to the CommandInterpreter object
  GDisplay* _gDisplay;    // Pointer to the GDisplay object
  GDisplay* _gSubDisplay; // Pointer to a GDisplay object acting as a subWindow
 public:
  Application(); // Default constructor
  Application(bool, uint32_t); // Constructor that accepts two parameters from the main program
  ~Application();

  //The following are factory methods used to create Game, GameView, and CommandInterpreter.
  virtual Game* MakeGame();
  virtual GDisplay* MakeGameView();
  virtual GDisplay* MakeGameSubView();
  virtual CommandInterpreter* MakeCommandInterpreter();

  Game* getGame(); // Returns the Game object
  GDisplay* getGameView(); // Returns the GDisplay object
  GDisplay* getGameSubView();  //Returns the subWindow object
  void Initialize(bool, uint32_t); // Initializes the fields
  void Run();
};

#endif
