#include <iostream>
#include <map>
#include "application.h"

using namespace std;

#include <iostream>
#include "application.h"

using namespace std;

//Default Constructor
Application::Application() : _isTextOnly(false), _seed(1), _game(NULL),
                             _commandInterpreter(NULL), _gDisplay(NULL) {
  Initialize(_isTextOnly, _seed);
}

//Constructor with paramaters to set _isTextOnly and _seed.
Application::Application(bool textOnly, uint32_t seed) : _isTextOnly(textOnly), _seed(seed),
                                                         _game(NULL), _commandInterpreter(NULL),
                                                         _gDisplay(NULL)  {
  Initialize(_isTextOnly, _seed);
}

//Destructor
Application::~Application() {
  if(_game != NULL) delete _game;
  if(_commandInterpreter != NULL) delete _commandInterpreter;
  if(_gDisplay != NULL) delete _gDisplay;
  if(_gSubDisplay != NULL) delete _gSubDisplay;
}

//Method to set up and return a Game object
Game* Application::MakeGame() {
  return new Game(_gDisplay, _gSubDisplay, 1, _seed);  //Game starts at level 1.
}

//Method to create and return a new GDisplay object for use as a mainWindow
GDisplay* Application::MakeGameView() {
  if (_isTextOnly) {  //Only return a display if not in text-only mode
    return NULL;
  } else {
    return new GDisplay(GDisplay::mainWindowWidth, GDisplay::mainWindowHeight);
  }
}

//Method to create and return a new GDisplay object for use as a subWindow.
GDisplay* Application::MakeGameSubView() {
  if (_isTextOnly) {  //Only return a display if not in text-only mode
    return NULL;
  } else {
    return new GDisplay(GDisplay::subWindowWidth, GDisplay::subWindowHeight);
  }
}

//Method to set up and return a pointer to a Command Interpreter
CommandInterpreter* Application::MakeCommandInterpreter() {
  map<string, Command*> commands;
  commands["leftshift"] = new LeftShift(_game);
  commands["rightshift"] = new RightShift(_game);
  commands["drop"] = new Drop(_game);
  commands["down"] = new Down(_game);
  commands["restart"] = new Restart(_game);
  commands["clockwise"] = new Clockwise(_game);
  commands["counterclockwise"] = new CounterClockwise(_game);
  commands["levelup"] = new LevelUp(_game);
  commands["leveldown"] = new LevelDown(_game);
  return new CommandInterpreter(commands, _game);
}

//getter method for _game object.
Game* Application::getGame() {
  return _game;
}

//getter method for _gDisplay object.
GDisplay* Application::getGameView() {
  return _gDisplay;
}

//getter method for the _gSubDisplay object
GDisplay* Application::getGameSubView() {
  return _gSubDisplay;
}

//Method to initialize the fields.
void Application::Initialize(bool textOnly, uint32_t seed) {

  //First, initialize the _gDisplay and gSubDisplay objects.
  _gDisplay = MakeGameView();
  _gSubDisplay = MakeGameSubView();

  //Second, initialize _game
  _game = MakeGame(); 

  //Finally, set up _commandInterpreter
  _commandInterpreter = MakeCommandInterpreter();
}

//Method to run the game.
void Application::Run() {
  //Run the game until no input can be read.
  while (_commandInterpreter->ReadInput()) {
    //Only execute a command if it is parsed as valid.
    if (_commandInterpreter->ParseInput()) { 
      _commandInterpreter->ExecuteActiveCommand(); 
    }
  }
}

