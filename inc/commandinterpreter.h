#ifndef __CMDINT_H__
#define __CMDINT_H__
#include <map>
#include <string>
#include <iostream>
#include "game.h"
#include "command.h"

class CommandInterpreter {
  std::map<std::string, Command*> _commands; // Dynamic mapping from string name to commands which allows command renaming
  std::string _currentInput;
  Command* _activeCommand;
  int _numOfExecution;
  Game* _game;
 public:
  CommandInterpreter(std::map<std::string, Command*> &commands, Game*); // Constructor that accepts a reference to a map from command name to command pointer as parameter
  ~CommandInterpreter(); // Destructor

  void Initialize(); // Initializes the fields
  bool ReadInput(); // Reads input from the command line, returns true if successfule
  bool ParseInput(); // Parses the input command, returns true if it is syntactically valid
  void ExecuteActiveCommand(); // Executes the current active command
  Command* getActiveCommand(); // Returns pointer to the active Command
  int getNumOfExecution(); // Returns the number of execution of the active Command
};

#endif
