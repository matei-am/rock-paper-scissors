class Player{
    int winCount=0;
    int loseCount=0;
    int drawCount=0;

    public:
    void addWin();
    void addLose();
    void addDraw();
    void displayStats();
    void ResetStats();
    
    Move getPlayerMove();
    Move getComputerMove();
};
