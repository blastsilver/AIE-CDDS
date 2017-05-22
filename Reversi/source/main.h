#pragma once

#include <string>
#include <Windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

#define REVERSI_SIZEX 25
#define REVERSI_SIZEY 25

namespace Reversi
{
    void GameStart();
    void GamePaint(Graphics * graphics);
    void GamePutPiece(int x, int y);
    void GameCalculate();
    void GameCalculate(int x, int y, int dx, int dy);
}