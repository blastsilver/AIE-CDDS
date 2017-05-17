#include <Windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

void Reversi_DrawGrid(Graphics * graphics, Pen * pen, int sizeX, int sizeY)
{
    for (int y = 0; y < (sizeY + 1); y++)
    {
        for (int x = 0; x < (sizeX + 1); x++)
        {
            int lowX = 0 + (x * 25);
            int lowY = 0 + (y * 25);
            int higX = 0 + ((10 - x) * 25);
            int higY = 0 + ((10 - y) * 25);

            graphics->DrawLine(
                pen,
                lowX,
                lowY,
                lowX,
                higY
            );
            graphics->DrawLine(
                pen,
                lowX,
                lowY,
                higX,
                lowY
            );
        }
    }
}

void Reversi_DrawPoint(Graphics * graphics, SolidBrush * brush, int x, int y)
{
    graphics->FillEllipse(brush, (x * 25) + 26, (y * 25) + 26, 23, 23);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            Graphics graphics(hdc);
            Pen      pen(Color(255, 100, 100, 100));
            Gdiplus::SolidBrush brush1(Color(255, 0, 0, 0));
            Gdiplus::SolidBrush brush2(Color(255, 255, 0, 0));

            Reversi_DrawGrid(&graphics, &pen, 10, 10);

            Reversi_DrawPoint(&graphics, &brush1, 4, 4);
            Reversi_DrawPoint(&graphics, &brush2, 5, 4);
            Reversi_DrawPoint(&graphics, &brush2, 4, 5);
            Reversi_DrawPoint(&graphics, &brush1, 5, 5);

            EndPaint(hwnd, &ps);
            break;
        }

        case WM_DESTROY:
        {
            PostQuitMessage(0);
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
        "Reversi",
        WS_POPUP | WS_CAPTION | WS_SYSMENU,
        0, 0, 300, 300,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );
    if (hwnd == NULL) return 1;
    // update the window
    RECT rect;
    GetClientRect(hwnd, &rect);
    GetWindowRect(hwnd, &rect);

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
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