WORKFLOW:
1. Ask how many rounds to play.
2. Get the player's move.
3. Generate the computer's move.
4. Compare the two moves.
5. Determine win/loss/draw.
6. Update the score.
7. Display the round result.
8. Repeat until n rounds have been played.
9. Display the final result.

CONCEPTS / ENTITIES
-Game
-Player
-Move
-Score
-Result

STRUCTURE
Game
 ├── controls the game
 │
 ├── Player
 │    ├── name
 │    ├── score
 │    └── chooses move
 │
 └── Move
      └── Rock/Paper/Scissors


DEPENDENCIES 
Game:
    play()
    playRound()
    displayFinalResult()

Player:
    chooseMove()
    addWin()
    addLoss()
    addDraw()

Game logic:
    determineWinner()