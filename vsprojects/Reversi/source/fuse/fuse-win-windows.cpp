#if defined(_WIN32)
//--------------------------------------------------------------------------------------------------
//-- Dependencies ----------------------------------------------------------------------------------

    #include <vector>
    #include "fuse-win-windows.h"
    // variables
    namespace _fusewin32
    {
        MSG msg;
        BOOL initialized = FALSE;
        char * className = "fusewin32";
        FUSEapp * app = NULL;
        std::vector<FUSEwindow> windows;
    }

//--------------------------------------------------------------------------------------------------
//-- Definitions -----------------------------------------------------------------------------------

    // test...
    void _fuseAPIWindowInit(FUSEapp * app)
    {
        // check if running
        if (_fusewin32::initialized == TRUE) return;
        // set current application
        _fusewin32::app = app;
        //------------------------------------------------
        // register window class
        WNDCLASSEX wndcex;
        wndcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wndcex.style = CS_HREDRAW | CS_VREDRAW;
        wndcex.cbSize = sizeof(WNDCLASSEX);
        wndcex.hCursor = LoadCursor(NULL, IDC_ARROW);
        wndcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
        wndcex.hInstance = GetModuleHandle(NULL);
        wndcex.cbClsExtra = 0;
        wndcex.cbWndExtra = 16;
        wndcex.lpfnWndProc = _fusewin32_WindowProcedure;
        wndcex.lpszMenuName = NULL;
        wndcex.lpszClassName = _fusewin32::className;
        wndcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        // check if registration worked
        if (!RegisterClassEx(&wndcex)) throw "_fusewin32 :: failed to register class!";
        //------------------------------------------------
        // create the window(s)
        FUSEwindow * window;
        for (size_t i = 0; i < _fusewin32::windows.size(); i++)
        {
            // create the window
            window = &_fusewin32::windows[i];
            window->hwnd = CreateWindowEx(
                NULL,
                _fusewin32::className,
                window->name,
                window->style,
                0,
                0,
                window->w,
                window->h,
                NULL,
                NULL,
                GetModuleHandle(NULL),
                (LPVOID)window
            );
            // check if window was created
            if (window->hwnd == NULL) throw "_fusewin32 :: failed to create window!";
            // show & update the window
            ShowWindow(window->hwnd, SW_SHOW);
            UpdateWindow(window->hwnd);
            // move the window to center
            _fuseAPIWindowMove(window, 0, 0);
        }
        //------------------------------------------------
        // ...finalize...
        _fusewin32::initialized = TRUE;
    }
    // test...
    void _fuseAPIWindowMove(FUSEwindow * window, int x, int y)
    {
        // find chrome size
        RECT client, chrome;
        GetClientRect(window->hwnd, &client);
        GetWindowRect(window->hwnd, &chrome);
        int border = int(float((chrome.right - chrome.left) - (client.right - client.left)) / 2.0f) - 1;
        // set window position
        //SetWindowPos(window->hwnd, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        SetWindowPos(window->hwnd, NULL, x - border, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    }
    // test...
    void _fuseAPIWindowSize(FUSEwindow * window, int w, int h)
    {
        // set window size
        SetWindowPos(window->hwnd, NULL, 0, 0, w, h, SWP_NOMOVE | SWP_NOZORDER);
    }
    // test...
    void _fuseAPIWindowClose(FUSEwindow * window)
    {
        // send close message
        SendMessage(window->hwnd, WM_CLOSE, NULL, NULL);
    }
    // test...
    void _fuseAPIWindowUpdate(FUSEwindow * window)
    {
        // update the window
        UpdateWindow(window->hwnd);
    }
    // test...
    void _fuseAPIWindowTerminate()
    {
        // check if running
        if (_fusewin32::initialized == FALSE) return;
        //------------------------------------------------
        // destroy the window(s)
        FUSEwindow * window;
        for (size_t i = 0; i < _fusewin32::windows.size(); i++)
        {
            // destroy the window
            window = &_fusewin32::windows[i];
            DestroyWindow(window->hwnd);
        }
        //------------------------------------------------
        // unregister window class
        UnregisterClass(_fusewin32::className, GetModuleHandle(NULL));
        //------------------------------------------------
        // ...finalize...
        _fusewin32::app = NULL;
        _fusewin32::initialized = FALSE;
        _fusewin32::windows.clear();
    }
    // test...
    bool _fuseAPIWindowPoolEvents()
    {
        // peek windows messages
        while (PeekMessage(&_fusewin32::msg, NULL, 0, 0, PM_REMOVE))
        {
            // check if quit message
            if (_fusewin32::msg.message == WM_QUIT) return false;
            // dispatch the message
            TranslateMessage(&_fusewin32::msg);
            DispatchMessage(&_fusewin32::msg);
        }
        // no exit messages
        return _fusewin32::windows.size() != 0;
    }
    // test...
    FUSEwindow * _fuseAPIWindowCreate(int w, int h, char * name)
    {
        // construct the window
        size_t size = _fusewin32::windows.size();
        _fusewin32::windows.push_back(FUSEwindow());
        _fusewin32::windows[size].w = w;
        _fusewin32::windows[size].h = h;
        _fusewin32::windows[size].id = size;
        _fusewin32::windows[size].name = name;
        _fusewin32::windows[size].hwnd = NULL;
        _fusewin32::windows[size].style = WS_POPUP | WS_CAPTION | WS_SYSMENU;
        // return address of value
        return &_fusewin32::windows[size];
    }
    // test...
    LRESULT CALLBACK _fusewin32_WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        // get window
        FUSEwindow * window = (FUSEwindow *)GetWindowLong(hwnd, 0);
        // check message
        switch (uMsg)
        {
            // defaults
            case WM_PAINT:
            {
                _fusewin32::app->OnWindowPaint(window);
                break;
            }
            case WM_CREATE:
            {
                _fusewin32::app->OnWindowCreate(window);
                break;
            }
            case WM_DESTROY:
            {
                _fusewin32::app->OnWindowDestroy(window);
                // quit the app
                PostQuitMessage(0);
                break;
            }
            case WM_NCCREATE:
            {
                // create window pointer
                CREATESTRUCT * cs = (CREATESTRUCT *)lParam;
                SetWindowLong(hwnd, 0, (LONG)cs->lpCreateParams);
                break;
            }
            // input events
            case WM_KEYUP:
            {
                _fusewin32::app->OnWindowKeyState(window, wParam, FALSE);
                break;
            }
            case WM_KEYDOWN:
            {
                _fusewin32::app->OnWindowKeyState(window, wParam, TRUE);
                break;
            }
        }
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

//--------------------------------------------------------------------------------------------------
#endif