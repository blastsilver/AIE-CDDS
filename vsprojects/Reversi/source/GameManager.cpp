//-- Dependencies ----------------------------------------------------------------------------------

    #include "Reversi.h"

//-- Declarations ----------------------------------------------------------------------------------

    GameManager::GameManager()
    {
        // current state
        this->reversi.state = GameState::None;
        // set new state
        this->stateManager.SetState(States::MENU);
    };
    void GameManager::OnPaint()
    {
        // draw the game
        this->_game_draw();
    }
    void GameManager::OnCreate(HWND hwnd)
    {
        // initialize manager
        this->_game_initiate();
        this->_paint_initiate(hwnd);
    }
    void GameManager::OnDestroy()
    {
        // terminate manager
        this->_paint_terminate();
        this->_game_terminate();
    }
    void GameManager::OnMouseMove(int x, int y)
    {
        // update game pos
        this->_game_update(x, y);
    }
    void GameManager::OnMouseClick(int x, int y)
    {
        // make next move
        this->_game_play(x, y);
    }
    GameState GameManager::GetState()
    {
        return this->reversi.state;
    }
    // private methods :: game
    void GameManager::_game_draw()
    {
        // begin paint
        this->_paint_begin();



        // end paint
        this->_paint_end();
    }
    void GameManager::_game_play(int x, int y)
    {
        // update mouse coord
        this->_game_update(x, y);
    }
    void GameManager::_game_update(int x, int y)
    {
        // update mouse coord
        this->reversi.x = x;
        this->reversi.y = y;
    }
    void GameManager::_game_initiate()
    {
        // initialize values
        this->reversi.x = 0;
        this->reversi.y = 0;
        this->reversi.size = 25;
        this->reversi.state = GameState::None;
        this->reversi.player = PLAYER1;
        // initialize arrays
        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 10; x++)
            {
                this->reversi.board1[x][y] = 0;
                this->reversi.board2[x][y] = 0;
            }
        }
    }
    // private methods :: paint
    void GameManager::_paint_end()
    {

    }
    void GameManager::_paint_begin()
    {

    }
    void GameManager::_paint_initiate(HWND hwnd)
    {

    }
    void GameManager::_paint_terminate()
    {

    }
    void GameManager::_paint_graphicsLine(int x, int y, int dx, int dy, Gdiplus::Color color)
    {

    }
    void GameManager::_paint_graphicsEllipse(int x, int y, Gdiplus::Color color)
    {

    }

//-----------------//hacked!!!!!---------------------------------------------------------------------------------