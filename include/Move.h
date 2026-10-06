#include <iostream>

enum class Move {
    ROCK,
    PAPER,
    SCISSORS
};

enum class result {
    WIN,
    LOSE,
    DRAW
};

class Result{
    public:
    result determineResult(Move playerMove, Move computerMove);
    void displayResult(result gameResult);
};