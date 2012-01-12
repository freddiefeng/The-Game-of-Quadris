#include <iostream>
#include <iostream>
#include <sstream>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "application.h"

using namespace std;

//This is where the program will handle the parameters passed in, and
//where it creates the application to run.
int main(int argc, char* argv[]) {
  bool textOnly = false;
  uint32_t seed = UINT_MAX;

  //Check the parameters and set textOnly and seed according to them.
  if (argc > 0) {
    for (int i = 0; i < argc; i++) {
      if (strcmp(argv[i], "-text") == 0) {
        //-text enables text-only mode 
        textOnly = true;
      } else if (strcmp(argv[i], "-seed") == 0) {
        //-seed suggests another argument is to be passed after it.
        if (i + 1 < argc) {
          istringstream numStream(argv[i + 1]);
          numStream >> seed;

          //Only accept valid seeds; other values will cause the program to exit.
          if (numStream.fail()) {
            cerr << "seed given is not a valid number." << endl;
            return 1;
          }

          i ++;
        } else {
          //If not, show an error message and leave program.
          cerr << "-seed called, but no seed is given." << endl;
          return 1;
        }
      }
    }
  }

  //Create the application object.
  Application app(textOnly, seed);
  app.Run(); //Let the game run until its "Run()" method returns.

  return 0;
}

