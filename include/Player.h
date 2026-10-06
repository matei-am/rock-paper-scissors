
class Player{
    int winCount=0;
    int loseCount=0;
    int drawCount=0;
    void addWin() {
        winCount++;
    }

    void addLose() {
        loseCount++;
    }

    void addDraw() {
        drawCount++;
    }
    public:
    Move getPlayerMove();
    Move getComputerMove();
};
