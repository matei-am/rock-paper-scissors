#pragma once
enum class Move {
    ROCK,
    PAPER,
    SCISSORS
};
enum class outcome {
    WIN,
    LOSS,
    DRAW
};

namespace Rules {
    outcome determineOutcome(Move playerMove, Move opponentMove);
}
