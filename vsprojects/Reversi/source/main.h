#pragma once

#include <string>
#include <objidl.h>
#include <gdiplus.h>
#include <Windows.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

#define REVERSI_SIZEX 25
#define REVERSI_SIZEY 25

namespace Reversi
{
    void GameEnd();
    void GameInit(HWND hwnd, HDC hdc);
    void GameStart();
    void GamePaint(Graphics * graphics);
    void GamePopulate();
    void GamePopulate(int x, int y, int dx, int dy);
    bool GameCalculate();
    void GameCalculate(int x, int y, int dx, int dy, int id);
    void GameEventMouseMove(int x, int y);
    void GameEventMouseClick();
}