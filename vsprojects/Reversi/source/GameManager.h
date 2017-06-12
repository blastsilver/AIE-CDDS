#pragma once
//-- Declarations ----------------------------------------------------------------------------------

    enum class GameState
    {
        None,       // no message
        Player1,    // the player 1
        Player2,    // the player 2
        GameOver,   // the game has finished
        NextPlayer, // the player has finished playing
        KeepPlayer, // the player has not finished playing
    };


    class GameManager
    {
    public:
        // constructor
        GameManager();
        // WindowProcedure :: called on paint
        void OnPaint(HWND hwnd);
        // WindowProcedure :: called on create
        void OnCreate(HWND hwnd);
        // WindowProcedure :: called on destroy
        void OnDestroy(HWND hwnd);
        // WindowProcedure :: called on mouse move
        void OnMouseMove(HWND hwnd, int x, int y);
        // WindowProcedure :: called on mouse click
        void OnMouseClick(HWND hwnd, int x, int y);
        // get current game state;
        GameState GetState();
    private:
        // structs
        struct _WinGraphics
        {
            HDC hdc;
            HBITMAP bmp;
            Gdiplus::Pen pen;
            Gdiplus::Graphics * graphics;
            Gdiplus::SolidBrush SolidBrush1;
            Gdiplus::SolidBrush SolidBrush2;
            Gdiplus::SolidBrush SolidBrush3;
        };
        struct _Reversi
        {
            int player;
            int x, y, size;
            GameState state;
            int board1[10][10];
            int board2[10][10];
        };
        // methods :: game
        void _game_draw();
        void _game_play(int x, int y);
        void _game_update(int x, int y);
        void _game_initiate();
        // methods :: paint
        void _paint_end();
        void _paint_begin();
        void _paint_initiate(HWND hwnd);
        void _paint_terminate();
        void _paint_graphicsLine(int x, int y, int dx, int dy, Gdiplus::Color color);
        void _paint_graphicsEllipse(int x, int y, Gdiplus::Color color);
        // variables
        _Reversi reversi;
        _WinGraphics window;
        StateManager stateManager;
        const int PLAYER1 = 1;
        const int PLAYER2 = 2;
    };

//--------------------------------------------------------------------------------------------------