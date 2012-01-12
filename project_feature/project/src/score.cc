#include <iomanip>
#include <sstream>
#include "score.h"

using namespace std;

//Constructor
Score::Score(GDisplay* pGDisplay) : Component(pGDisplay)
{
  _score = _hiScore = 0;
}

//Destructor
Score::~Score()
{}

//Method to add a certain numver of points to the current _score value, and return it.
//The high score is also updated.
int Score::Add(int points)
{
  _score += points;
  _hiScore = (_hiScore >= _score ? _hiScore : _score);
  return _score;
}

//Getter method to return the high score of the game.
int Score::getHiScore()
{
  return _hiScore;
}

//Setter method to set the value of the score.
void Score::setScore(int value)
{
  _score = value;
}

//Method to textually draw the score in this from:
//Score:        0
//Hi Score:     0
void Score::drawText()
{
  cout << "Score:" << setw(7) << _score << endl;
  cout << "Hi Score:" << setw(4) << _hiScore << endl;
}

//Method to draw the score on the game display.
void Score::drawGDisplay()
{
  if (_gameDisplay != NULL) {
    string sScore;
    stringstream ss;

    ss << "Score:" << setw(7) << _score;
    sScore = ss.str();

    ss.clear();
    ss.str("");
    ss << "Hi Score:" << setw(4) << _hiScore;

    _gameDisplay->drawScore(sScore, ss.str());
  }
}

//Method to reset the score of the game back to 0
void Score::reset()
{
  _score = 0;
}
