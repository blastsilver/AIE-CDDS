#include <Windows.h>
#include "fuse-win-windows.h"

class ReversiApp : public FUSEapp
{
    float x, y;
    float dx, dy;
    FUSEwindow * window;
public:
    virtual void OnEnd()
    {
        int zz = 0;
    };
    virtual void OnBegin() {
        x = 0;
        y = 0;
        this->window = fuseCreateWindow(400, 400, "Reversi - by Francisco Romano");
    };
    virtual void OnError(const char * name)
    {
        int zz = 0;
    }
    virtual void OnUpdate(const float delta)
    {
        // check if moving
        if (dx != 0 || dy != 0)
        {
            x += dx;
            y += dy;
            // set the window position
            fuseSetWindowPos(window, int(x), int(y));
        }
    };
    virtual void OnWindowPaint(FUSEwindow * window)
    {
        int zz = 0;
    };
    virtual void OnWindowCreate(FUSEwindow * window)
    {
        int zz = 0;
    };
    virtual void OnWindowDestroy(FUSEwindow * window)
    {
        int zz = 0;
    };
    virtual void OnWindowKeyState(FUSEwindow * window, int key, int state)
    {
        // set window direction
        if (state == FALSE)
        {
            if (key == VK_UP)         dy -= 0.005f;
            else if (key == VK_DOWN)  dy += 0.005f;
            else if (key == VK_LEFT)  dx -= 0.005f;
            else if (key == VK_RIGHT) dx += 0.005f;
        }
    };
    virtual void OnWindowMouseMove(FUSEwindow * window, int posX, int posY)
    {
        int zz = 0;
    };
    virtual void OnWindowMouseState(FUSEwindow * window, int key, int state)
    {
        int zz = 0;
    };
};

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // create an app
    ReversiApp app;
    // execute the app
    fuseExecute(&app);
    // return 0
    return 0;
}

//#include <Windows.h>
//#include <objidl.h>
//#include <gdiplus.h>
//using namespace Gdiplus;
//#pragma comment (lib,"Gdiplus.lib")
//
//void Reversi_DrawGrid(Graphics * graphics, Pen * pen, int sizeX, int sizeY)
//{
//    for (int y = 0; y < (sizeY + 1); y++)
//    {
//        for (int x = 0; x < (sizeX + 1); x++)
//        {
//            int lowX = 0 + (x * 25);
//            int lowY = 0 + (y * 25);
//            int higX = 0 + ((10 - x) * 25);
//            int higY = 0 + ((10 - y) * 25);
//
//            graphics->DrawLine(
//                pen,
//                lowX,
//                lowY,
//                lowX,
//                higY
//            );
//            graphics->DrawLine(
//                pen,
//                lowX,
//                lowY,
//                higX,
//                lowY
//            );
//        }
//    }
//}
//
//void Reversi_DrawPoint(Graphics * graphics, SolidBrush * brush, int x, int y)
//{
//    graphics->FillEllipse(brush, (x * 25) + 26, (y * 25) + 26, 23, 23);
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//    switch (uMsg)
//    {
//        case WM_CREATE:
//        {
//            RECT rect1, rect2;
//            GetClientRect(hwnd, &rect1);
//            GetWindowRect(hwnd, &rect2);
//            int sizeX = 
//            // show the window
//            ShowWindow(hwnd, SW_SHOW);
//            break;
//        }
//        case WM_PAINT:
//        {
//            PAINTSTRUCT ps;
//            HDC hdc = BeginPaint(hwnd, &ps);
//
//            Graphics graphics(hdc);
//            Pen      pen(Color(255, 100, 100, 100));
//            Gdiplus::SolidBrush brush1(Color(255, 0, 0, 0));
//            Gdiplus::SolidBrush brush2(Color(255, 255, 0, 0));
//
//
//
//            Reversi_DrawGrid(&graphics, &pen, 10, 10);
//
//            Reversi_DrawPoint(&graphics, &brush1, 4, 4);
//            Reversi_DrawPoint(&graphics, &brush2, 5, 4);
//            Reversi_DrawPoint(&graphics, &brush2, 4, 5);
//            Reversi_DrawPoint(&graphics, &brush1, 5, 5);
//
//            EndPaint(hwnd, &ps);
//            break;
//        }
//
//        case WM_DESTROY:
//        {
//            PostQuitMessage(0);
//            break;
//        }
//    }
//    return DefWindowProc(hwnd, uMsg, wParam, lParam);
//}
//
//int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//    //------------------------------------------------
//    // initial values
//    MSG msg;
//    HWND hwnd;
//    BOOL running = 1;
//    WNDCLASSEX wndcex;
//    ULONG_PTR gdiplusToken;
//    GdiplusStartupInput gdiplusStartupInput;
//    //------------------------------------------------
//    // initialize gdi++.
//    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
//    //------------------------------------------------
//    // construct class
//    wndcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//    wndcex.style = CS_HREDRAW | CS_VREDRAW;
//    wndcex.cbSize = sizeof(WNDCLASSEX);
//    wndcex.hCursor = LoadCursor(NULL, IDC_ARROW);
//    wndcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//    wndcex.hInstance = GetModuleHandle(NULL);
//    wndcex.cbClsExtra = 0;
//    wndcex.cbWndExtra = 16;
//    wndcex.lpfnWndProc = WndProc;
//    wndcex.lpszMenuName = NULL;
//    wndcex.lpszClassName = "WindowClass";
//    wndcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//    // register the class
//    if (!RegisterClassEx(&wndcex)) return 1;
//    // register successfull
//    //------------------------------------------------
//    // create window
//    hwnd = CreateWindow(
//        "WindowClass",
//        "Reversi",
//        WS_POPUP | WS_CAPTION | WS_SYSMENU,
//        0, 0, 300, 300,
//        NULL,
//        NULL,
//        GetModuleHandle(NULL),
//        NULL
//    );
//    if (hwnd == NULL) return 1;
//    // update the window
//    RECT rect;
//    GetClientRect(hwnd, &rect);
//    GetWindowRect(hwnd, &rect);
//
//    UpdateWindow(hwnd);
//    // creation successfull
//    //------------------------------------------------
//    // message pump
//    while (running == TRUE)
//    {
//        // check for message
//        while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
//        {
//            // check if running
//            if (msg.message == WM_QUIT)
//            {
//                running = FALSE;
//                break;
//            }
//            // message dispatch
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//        // update...
//    }
//    //------------------------------------------------
//    // shutdown gdi++.
//    GdiplusShutdown(gdiplusToken);
//    //------------------------------------------------
//    return 0;
//}