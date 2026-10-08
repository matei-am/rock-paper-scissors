enum class Move {
    ROCK,
    PAPER,
    SCISSORS
};

enum class outcome {
    WIN,
    LOSE,
    DRAW
};

class Result{
    public:
    outcome determineResult(Move playerMove, Move computerMove);
    void displayResult(outcome gameResult);
};