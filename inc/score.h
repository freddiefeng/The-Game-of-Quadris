#ifndef __SCORE_H__
#define __SCORE_H__
#include "component.h"

class Score : public Component{
  int _hiScore;
  int _score;
 public:
  Score(GDisplay*); // Constructor
  ~Score(); // Destructor

  int Add(int); // Adds to the current score and return the new score value
  int getHiScore(); // Gets the highest score
  void setScore(int); // Sets the score directly
  void drawText(); // Draw the scores to standard output
  void drawGDisplay(); // Draw the scores to the graphical display

  void reset();
};

#endif
