#include <stdlib.h>
#include "commandinterpreter.h"

using namespace std;

static const string alpha = "abcdefghijklmnopqrstuvwxyz""ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Constructor that accepts a reference to a map from command name to command pointer as parameter
CommandInterpreter::CommandInterpreter(map<string, Command*> &commands, Game* pGame)
{
  _commands = commands;
  _game = pGame;
  Initialize();
}

// Destructor
CommandInterpreter::~CommandInterpreter()
{
  for(map<string, Command*>::iterator it = _commands.begin(); it != _commands.end(); it++)
    {
      delete it->second;
    }
}

// Initializes the fields to default values
void CommandInterpreter::Initialize()
{
  _currentInput = "";
  _activeCommand = NULL;
  _numOfExecution = 0;
}

// Reads input from the command line, returns true if successfule
bool CommandInterpreter::ReadInput()
{
  string sLine;
  cin >> sLine;
  
  if(cin.fail())
    return false;

  _currentInput = sLine;

  return true;
}

// Parses the input command, returns true if it is syntactically valid
bool CommandInterpreter::ParseInput()
{
  string sNum, sName;

  string::size_type posn = _currentInput.find_first_of(alpha);// finds the first occurrence of alphabet
  if(posn != 0)
    {
      sNum = _currentInput.substr(0, posn);
      _numOfExecution = atoi(sNum.c_str());
    }
  else
    {
      // if the number of execution is not specified, set it to default value 1
      _numOfExecution = 1;
    }

  bool bFound = false;
  sName = _currentInput.substr(posn);// gets the shortcut of the command

  for(map<string, Command*>::iterator it = _commands.begin(); it != _commands.end(); it++)
    {
      string::size_type p = ((*it).first).find(sName); // finds the first occurrence of the command name or shortcut
      if(p == 0)
	{
	  if(!bFound)
	    {
	      // sets the active command if the shortcut matches the begining of the command name
	      _activeCommand = (*it).second;
	      bFound = true;
	    }
	  else
	    {
	      // Rejects ambiguous command
	      cout << "Ambiguous Command: " << sName << endl;
	      return false;
	    }
	}
    }

  // Rejects if command not found
  if(!bFound)
    {
      cout << "Command Not Found: " << sName << endl;
      return false;
    }

  return true;
}

// Executes the current active command if it is valid, returns true if successfule
void CommandInterpreter::ExecuteActiveCommand()
{
  for(int i = 0; i < _numOfExecution; i++)
    {
      _activeCommand->Execute();
    }

  _game->drawText();
}

// Returns pointer to the active Command
Command* CommandInterpreter::getActiveCommand()
{
  return _activeCommand;
}

// Returns the number of execution of the active Command
int CommandInterpreter::getNumOfExecution()
{
  return _numOfExecution;
}

