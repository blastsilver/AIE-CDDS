#include "main.h"

//https://msdn.microsoft.com/en-us/library/windows/desktop/ms644927(v=vs.85).aspx#system_defined

namespace Reversi
{
    HDC BUFF;
    HBITMAP hBMP;
    static int game_x;
    static int game_y;
    static int game_player;
    static int game_board[10][10];
    static int game_check[10][10];
    
    void GameEnd()
    {
        DeleteObject(BUFF);
        DeleteObject(hBMP);
    }
    void GameInit(HWND hwnd, HDC hdc)
    {
        int cx = GetSystemMetrics(SM_CXSCREEN);
        int cy = GetSystemMetrics(SM_CYSCREEN);
        BUFF = CreateCompatibleDC(hdc);
        hBMP = CreateCompatibleBitmap(hdc, cx, cy);
        SelectObject(BUFF, hBMP);
        ReleaseDC(hwnd, hdc);
    }
    void GameStart()
    {
        // clear board
        for (int y = 0; y < 10; y++)
            for (int x = 0; x < 10; x++)
                game_board[x][y] = 0,
                game_check[x][y] = 0;
        // set default game
        game_x = 0;
        game_y = 0;
        game_player = 1;
        game_board[4][4] = 1;
        game_board[5][4] = 2;
        game_board[4][5] = 2;
        game_board[5][5] = 1;
        // calculate the board
        GameCalculate();
    }
    void GamePaint(Graphics * graphics)
    {
        Pen pen(Color(255, 100, 100, 100));
        SolidBrush brush1(Color(255, 255, 0, 0));
        SolidBrush brush2(Color(255, 0, 0, 255));
        SolidBrush brush3(Color(255, 100, 100, 100));
        // draw the game
        for (int y = 0; y < 11; y++)
        {
            for (int x = 0; x < 11; x++)
            {
                //------------------------------------------------
                // calculate lows and highs
                int lowX = (x * REVERSI_SIZEX);
                int lowY = (y * REVERSI_SIZEY);
                int higX = ((10 - x) * REVERSI_SIZEX);
                int higY = ((10 - y) * REVERSI_SIZEY);
                // draw vertical line
                graphics->DrawLine(&pen, lowX, lowY, lowX, higY);
                // draw horizontal line
                graphics->DrawLine(&pen, lowX, lowY, higX, lowY);
                //------------------------------------------------
                // check if in-bounds
                if (y < 10 && x < 10)
                {
                    // check if empty
                    if (game_board[x][y] == 0) continue;
                    // select the brush
                    SolidBrush * brush = game_board[x][y] == 2 ? &brush2 : &brush1;
                    // draw filled ellipse
                    graphics->FillEllipse(brush, lowX+2, lowY+2, REVERSI_SIZEX-4, REVERSI_SIZEY-4);
                }
                //------------------------------------------------
            }
        }

        // draw the player
        if (game_x < 0 || game_x > 9) return;
        if (game_y < 0 || game_y > 9) return;
        if (game_check[game_x][game_y] != game_player) return;
        graphics->FillEllipse(&brush3, game_x*REVERSI_SIZEX+2, game_y*REVERSI_SIZEX+2, 21, 21);

        RECT rect = { 1, 1, 49, 24 };
        std::string str = std::to_string(game_x) + "," + std::to_string(game_y);
        DrawText(graphics->GetHDC(), str.c_str(), str.size(), &rect, DT_LEFT);



    }
    void GamePutPiece(int x, int y)
    {
        
    }
    void GameCalculate()
    {
        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 10; x++)
            {
                game_check[x][y] = 0;
                // calculate positives
                GameCalculate(x, y, 1, 0);
                GameCalculate(x, y, 0, 1);
                GameCalculate(x, y, 1, 1);
                // calculate negatives
                GameCalculate(x, y,-1, 0);
                GameCalculate(x, y, 0,-1);
                GameCalculate(x, y,-1,-1);
            }
        }
    }
    void GameCalculate(int x, int y, int dx, int dy)
    {
        int tx = x, ty = y;
        int value = game_board[tx][ty];
        // check if possible
        if (value == 0 && game_board[tx + dx][ty + dy] != 0 && game_board[tx + dx][ty + dy] != game_player)
        {
            tx += dx, ty += dy;
            // go through line deltas
            while (true)
            {
                // add deltas
                tx += dx, ty += dy;
                // check bounds
                if (tx < 0 || tx > 9) break;
                if (ty < 0 || ty > 9) break;
                // get the value
                value = game_board[tx][ty];
                // check for 0's
                if (value == 0) break;
                // check for opposite player
                if (value == game_player)
                {
                    // add to the check table
                    game_check[x][y] = game_player;
                    break;
                }
            }
        }
    }
    void GameEventMouseMove(int x, int y)
    {
        // set game position
        game_x = int(float(x) / float(REVERSI_SIZEX));
        game_y = int(float(y) / float(REVERSI_SIZEY));
    }
    void GameEventMouseState(int key, int state)
    {

    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    switch (uMsg)
    {
        case WM_CREATE:
        {
            // get size
            RECT r1, r2;
            GetClientRect(hwnd, &r1);
            GetWindowRect(hwnd, &r2);
            // set new size
            int cx = REVERSI_SIZEX * 10 + (r2.right - r2.left) - (r1.right - r1.left) + 1;
            int cy = REVERSI_SIZEY * 10 + (r2.bottom - r2.top) - (r1.bottom - r1.top) + 1;
            SetWindowPos(hwnd, NULL, 0, 0, cx, cy, SWP_NOMOVE | SWP_NOZORDER);
            // create new board
            Reversi::GameInit(hwnd, GetDC(hwnd));
            // create new buffer
            Reversi::GameStart();
            break;
        }
        case WM_PAINT:
        {
            RECT rc;
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            Graphics graphics(Reversi::BUFF);

            GetClientRect(hwnd, &rc);
            PatBlt(Reversi::BUFF, 0, 0, rc.right - rc.left, rc.bottom - rc.top, PATCOPY);

            Reversi::GamePaint(&graphics);

            int cx = GetSystemMetrics(SM_CXSCREEN);
            int cy = GetSystemMetrics(SM_CYSCREEN);
            BitBlt(hdc, 0, 0, cx, cy, Reversi::BUFF, 0, 0, SRCCOPY);

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_DESTROY:
        {
            Reversi::GameEnd();
            PostQuitMessage(0);
            break;
        }
        // events
        case WM_MOUSEMOVE:
        {
            Reversi::GameEventMouseMove(LOWORD(lParam), HIWORD(lParam));
            InvalidateRect(hwnd, NULL, FALSE);
            UpdateWindow(hwnd);
            break;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //------------------------------------------------
    // initial values
    MSG msg;
    HWND hwnd;
    BOOL running = 1;
    WNDCLASSEX wndcex;
    ULONG_PTR gdiplusToken;
    GdiplusStartupInput gdiplusStartupInput;
    //------------------------------------------------
    // initialize gdi++.
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    //------------------------------------------------
    // construct class
    wndcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndcex.style = CS_HREDRAW | CS_VREDRAW;
    wndcex.cbSize = sizeof(WNDCLASSEX);
    wndcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wndcex.hInstance = GetModuleHandle(NULL);
    wndcex.cbClsExtra = 0;
    wndcex.cbWndExtra = 16;
    wndcex.lpfnWndProc = WndProc;
    wndcex.lpszMenuName = NULL;
    wndcex.lpszClassName = "WindowClass";
    wndcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    // register the class
    if (!RegisterClassEx(&wndcex)) return 1;
    // register successfull
    //------------------------------------------------
    // create window
    hwnd = CreateWindow(
        "WindowClass",
        "Reversi \\ Othello",
        WS_POPUP | WS_CAPTION | WS_SYSMENU,
        0, 0, 300, 300,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );
    if (hwnd == NULL) return 1;
    // update the window
    RECT rect1;
    RECT rect2;
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
    GetClientRect(hwnd, &rect1);
    GetWindowRect(hwnd, &rect2);
    // creation successfull
    //------------------------------------------------
    // message pump
    while (running == TRUE)
    {
        // check for message
        while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
        {
            // check if running
            if (msg.message == WM_QUIT)
            {
                running = FALSE;
                break;
            }
            // message dispatch
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        // update...
    }
    //------------------------------------------------
    // shutdown gdi++.
    GdiplusShutdown(gdiplusToken);
    //------------------------------------------------
    return 0;
}