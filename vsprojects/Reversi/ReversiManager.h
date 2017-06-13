#pragma once

namespace game
{
    class ReversiManager
    {
        // variables
        int m_mouseX;
        int m_mouseY;
        int m_playing;
        int m_score[2];
        bool m_gameover;
        unsigned char m_gameBoard[10][10];
        unsigned char m_gameCheck[10][10];
        static const int MOVE_T = 0x1000;
        static const int MOVE_L = 0x0010;
        static const int MOVE_R = 0x0001;
        static const int MOVE_B = 0x0100;
        static const int MOVE_TL = MOVE_T | MOVE_L;
        static const int MOVE_TR = MOVE_T | MOVE_R;
        static const int MOVE_BL = MOVE_B | MOVE_L;
        static const int MOVE_BR = MOVE_B | MOVE_R;
    public:
        static const int PLAYER1 = 1;
        static const int PLAYER2 = 2;
        // public defaults
        ReversiManager();
        // public functions
        int player();
        int score1();
        int score2();
        void restart();
        void onPaint();
        void onMouseMove(int x, int y);
        void onMouseClick();
    private:
        // private functions
        bool gameUpdate();
        bool gameValidate(int x, int y);
        void gamePopulate(int x, int y);
        void gamePopulate(int x, int y, int checkId);
        bool gameValidate(int x, int y, int checkId);
    };

}
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