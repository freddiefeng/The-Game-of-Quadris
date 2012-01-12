#include <iostream>
#include <fstream>
#include <cstdlib>
#include "level0.h"
#include "block.h"
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "tblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"

using namespace std;

int Level0::curChar = 0;

// Constructor that sets Level's lvalue to 0.
Level0::Level0(GDisplay* pGDisplay) : Level(0, pGDisplay) {
  //Now, fill up sequence table.
  ifstream filestream;
  filestream.open("sequence.txt");
  

  if(!filestream) return;
 
  string curWord;

  filestream >> curWord;

  //Extract the pattern from the file (get each character).
  while (!filestream.eof()) {
    _sequence.push_back(curWord);
    filestream >> curWord;
  }
  filestream.close();
}

// Generate the next block in fixed order.
Block* Level0::getNextBlock(Coordinate coord, Board *pBoard) {
  int oldChar = curChar; //Used to check which block to generate in this method.
  curChar = (curChar + 1) % _sequence.size();  //Current char is  curChar+1 MOD sequence length

  if (_sequence[oldChar] == "J") {
    return new JBlock('J', coord, 0, pBoard);
  } else if (_sequence[oldChar] == "L") {
    return new LBlock('L', coord, 0, pBoard);
  } else if (_sequence[oldChar] == "I") {
    return new IBlock('I', coord, 0, pBoard);
  } else if (_sequence[oldChar] == "O") {
    return new OBlock('O', coord, 0, pBoard);
  } else if (_sequence[oldChar] == "T") {
    return new TBlock('T', coord, 0, pBoard);
  } else if (_sequence[oldChar] == "S") {
    return new SBlock('S', coord, 0, pBoard);
  } else if (_sequence[oldChar] == "Z") {
    return new ZBlock('Z', coord, 0, pBoard);
  }

  //If the sequence.txt file has something beyond the above, a J block is produced, but
  //so is a message indicating the problem in debug mode.

#if DEBUG
  cout << "ERROR: sequence.txt file has an unexpected value!" << endl;
#endif
  return new JBlock('J', coord, 0, pBoard);
}
