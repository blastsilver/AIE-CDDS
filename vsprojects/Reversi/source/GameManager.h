#pragma once
//-- Declarations ----------------------------------------------------------------------------------

    enum class GameMessage
    {
        None,       // no message
        Player1,    // the player 1
        Player2,    // the player 2
        Restart,    // the game needs to restart
        GameOver,   // when the game has finished
        NextPlayer, // when player finished his move
        KeepPlayer, // when next player has no moves
    };

    class GameManager
    {
    public:
        GameManager();
        ~GameManager();
        int Score(GameMessage message);
        GameMessage Play(int x, int y);


        //void GameEnd();
        //void GameInit(HWND hwnd, HDC hdc);
        //void GameStart();
        //void GamePaint(Graphics * graphics);
        //void GamePopulate();
        //void GamePopulate(int x, int y, int dx, int dy);
        //bool GameCalculate();
        //void GameCalculate(int x, int y, int dx, int dy, int id);
        //void GameEventMouseMove(int x, int y);
        //void GameEventMouseClick();
    };

//--------------------------------------------------------------------------------------------------