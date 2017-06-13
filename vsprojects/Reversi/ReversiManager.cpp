#include "ReversiManager.h"

// public defaults
game::ReversiManager::ReversiManager()
{
    // restart game
    this->restart();
};
// public functions
int game::ReversiManager::player()
{
    // return current player
    return this->m_playing;
}
int game::ReversiManager::score1()
{
    // return player 1 score
    return this->m_score[0];
}
int game::ReversiManager::score2()
{
    // return player 2 score
    return this->m_score[1];
}
void game::ReversiManager::restart()
{
    // set defaults
    this->m_mouseX = 0;
    this->m_mouseX = 0;
    this->m_playing = ReversiManager::PLAYER1;
    this->m_score[0] = 0;
    this->m_score[1] = 0;
    this->m_gameover = false;
    for (char y = 0; y < 10; y++)
    {
        for (char x = 0; x < 10; x++)
        {
            this->m_gameBoard[x][y] = 0;
            this->m_gameCheck[x][y] = 0;
        }
    }
    // set default board
    this->m_gameBoard[4][4] = ReversiManager::PLAYER1;
    this->m_gameBoard[4][5] = ReversiManager::PLAYER2;
    this->m_gameBoard[5][4] = ReversiManager::PLAYER2;
    this->m_gameBoard[5][5] = ReversiManager::PLAYER1;
    // calculate check board
    this->gameUpdate();
};
void game::ReversiManager::onPaint()
{

};
void game::ReversiManager::onMouseMove(int x, int y)
{
    // set mouse coords
    this->m_mouseX = x;
    this->m_mouseY = y;
};
void game::ReversiManager::onMouseClick()
{
    // check if valid
    if (this->gameValidate(this->m_mouseX, this->m_mouseY)) return;
    // populate player
    this->gamePopulate(this->m_mouseX, this->m_mouseY);
    // check for valid moves
    if (!this->gameUpdate())
    {
        // swap players
        this->m_playing = this->m_playing % 2 + 1;
        // check for valid moves
        if (!this->gameUpdate())
        {
            // failed, gameover
            this->m_gameover = true;
        }
        else
        {
            //MessageBox(NULL, "Keep Playing!", MB_OK, MB_ICONINFORMATION)
        }
    }
};
// private functions
bool game::ReversiManager::gameUpdate()
{
    bool check = false;
    this->m_score[0] = 0;
    this->m_score[1] = 0;
    // reset board check
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            // reset check
            this->m_gameCheck[x][y] = 0;
            // check if empty
            if (this->m_gameBoard[x][y] == 0)
            {
                // calculate axis
                check |= this->gameValidate(x, y, ReversiManager::MOVE_T);
                check |= this->gameValidate(x, y, ReversiManager::MOVE_L);
                check |= this->gameValidate(x, y, ReversiManager::MOVE_R);
                check |= this->gameValidate(x, y, ReversiManager::MOVE_B);
                // calculate diagonals
                check |= this->gameValidate(x, y, ReversiManager::MOVE_T | ReversiManager::MOVE_L);
                check |= this->gameValidate(x, y, ReversiManager::MOVE_T | ReversiManager::MOVE_R);
                check |= this->gameValidate(x, y, ReversiManager::MOVE_B | ReversiManager::MOVE_L);
                check |= this->gameValidate(x, y, ReversiManager::MOVE_B | ReversiManager::MOVE_R);
            }
            else
            {
                // save score
                this->m_score[this->m_playing - 1]++;
            }
        }
    }
    // return check;
    return check;
};
bool game::ReversiManager::gameValidate(int x, int y)
{
    // check if valid
    return this->m_gameCheck[this->m_mouseX][this->m_mouseY] != 0;
}
void game::ReversiManager::gamePopulate(int x, int y)
{
    char check = this->m_gameCheck[x][y];
    // populate player on axis
    if ((check | ReversiManager::MOVE_T) == check) this->gamePopulate(x, y, ReversiManager::MOVE_T);
    if ((check | ReversiManager::MOVE_L) == check) this->gamePopulate(x, y, ReversiManager::MOVE_L);
    if ((check | ReversiManager::MOVE_R) == check) this->gamePopulate(x, y, ReversiManager::MOVE_R);
    if ((check | ReversiManager::MOVE_B) == check) this->gamePopulate(x, y, ReversiManager::MOVE_B);
    // pupulate player on diagonals
    if ((check | ReversiManager::MOVE_TL) == check) this->gameValidate(x, y, ReversiManager::MOVE_TL);
    if ((check | ReversiManager::MOVE_TR) == check) this->gameValidate(x, y, ReversiManager::MOVE_TR);
    if ((check | ReversiManager::MOVE_BL) == check) this->gameValidate(x, y, ReversiManager::MOVE_BL);
    if ((check | ReversiManager::MOVE_BR) == check) this->gameValidate(x, y, ReversiManager::MOVE_BR);
}
void game::ReversiManager::gamePopulate(int x, int y, int checkId)
{
    // check if empty
    if (checkId == 0) throw "ReversiManager :: checkId cannot be empty!";
    // calculate direction
    int tx = x, ty = y;
    int dy = (checkId | ReversiManager::MOVE_T) ? -1 : (checkId | ReversiManager::MOVE_B) ? 1 : 0;
    int dx = (checkId | ReversiManager::MOVE_L) ? -1 : (checkId | ReversiManager::MOVE_R) ? 1 : 0;
    // go throught deltas
    while (true)
    {
        // check if in-bounds
        if (tx < 0 || tx > 9) break;
        if (ty < 0 || ty > 9) break;
        // check if complete
        if (this->m_gameBoard[tx][ty] == 0) break;
        if (this->m_gameBoard[tx][ty] == this->m_playing) break;
        // populate boards
        this->m_gameBoard[tx][ty] = this->m_playing;
        // add deltas
        tx += dx;
        ty += dy;
    }
};
bool game::ReversiManager::gameValidate(int x, int y, int checkId)
{
    // check if empty
    if (checkId == 0) throw "ReversiManager :: checkId cannot be empty!";
    // calculate direction
    int dy = (checkId | ReversiManager::MOVE_T) ? -1 : (checkId | ReversiManager::MOVE_B) ? 1 : 0;
    int dx = (checkId | ReversiManager::MOVE_L) ? -1 : (checkId | ReversiManager::MOVE_R) ? 1 : 0;
    int tx = x + dx;
    int ty = x + dy;
    // check if valid (PLAYER1 + PLAYER2 == 3)
    if (this->m_gameBoard[tx][ty] + this->m_playing == 3)
    {
        // go throught deltas
        while (true)
        {
            // add deltas
            tx += dx, ty += dy;
            // check if in-bounds
            if (tx < 0 || tx > 9) return false;
            if (ty < 0 || ty > 9) return false;
            // check if wrong values
            if (this->m_gameBoard[tx][ty] == this->m_playing)
            {
                this->m_gameCheck[x][y] |= checkId;
                return true;
            }
            // check if empty found
            if (this->m_gameBoard[tx][ty] == 0) return true;
        }
    }
};