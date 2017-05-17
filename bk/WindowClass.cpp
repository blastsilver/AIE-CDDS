#pragma once
//-- Dependencies ----------------------------------------------------------------------------------

    #include "main.h"
    // Win API :: Requirements
    HWND WndPopup(int width, int height, char * cName, char * wName, DWORD style, LPVOID lpvoid);
    bool WndRegister(char * name, HICON hIcon, HCURSOR hCursor);
    HICON WndIcon() { return LoadIcon(NULL, IDI_APPLICATION); }
    HCURSOR WndCursor() { return LoadCursor(NULL, IDC_ARROW); }
    HINSTANCE WndHInstance();
    // Win API :: Window Procedure
    LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//--------------------------------------------------------------------------------------------------
//-- Definitions -----------------------------------------------------------------------------------

    // -- class -------------
    WindowClass::WindowClass(char * name, WindowEvents * events)
    {
        // check parameters
        FUSE_ASSERT(name != NULL, "'name' is undefined!");
        FUSE_ASSERT(events != NULL, "'events' is undefined!");
        // assign values
        this->name = name;
        this->events = events;
    }
    void WindowClass::execute()
    {
        // register the class
        if (WndRegister(this->name, WndIcon(), WndCursor()))
        {

        }
    }
    void WindowClass::addWindow(int width, int height, char * name)
    {
        // check parameters
        FUSE_ASSERT(name != NULL, "'name' is undefined!");
        // attach new window
        this->windows.push_back(Window(width, height, name));
    }

    // -- win32 API ---------
    HWND WndPopup(int width, int height, char * cName, char * wName, DWORD style, LPVOID lpvoid)
    {
        // create window
        return CreateWindowEx(
            NULL,
            cName,
            wName,
            style,
            0,0,width,height,
            NULL,
            NULL,
            WndHInstance(),
            (LPVOID)lpvoid
        );
    }
    bool WndRegister(char * name, HICON hIcon, HCURSOR hCursor)
    {
        // construct class
        WNDCLASSEX wndcex;
        wndcex.hIcon = WndIcon();
        wndcex.style = CS_HREDRAW | CS_VREDRAW;
        wndcex.cbSize = sizeof(WNDCLASSEX);
        wndcex.hCursor = WndCursor();
        wndcex.hIconSm = WndIcon();
        wndcex.hInstance = WndHInstance();
        wndcex.cbClsExtra = 0;
        wndcex.cbWndExtra = 16;
        wndcex.lpfnWndProc = WndProc;
        wndcex.lpszMenuName = NULL;
        wndcex.lpszClassName = "FuseWindowClass";
        wndcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        // register the class
        if (!RegisterClassEx(&wndcex)) return false;
        // register successfull
        return true;
    }
    HINSTANCE WndHInstance()
    {
        // get current hInstance
        return GetModuleHandle(NULL);
    }
    LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

//--------------------------------------------------------------------------------------------------