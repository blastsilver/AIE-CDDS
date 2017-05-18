#pragma once
#if defined(_WIN32)
//--------------------------------------------------------------------------------------------------
//-- Dependencies ----------------------------------------------------------------------------------

    #include <Windows.h>
    #include "fuse-core.h"
    #include "fuse-window.h"

//--------------------------------------------------------------------------------------------------
//-- Definitions -----------------------------------------------------------------------------------

    // Windows :: window icon
    struct FUSEicon
    {
        HICON hicon;
    };
    // Windows :: window cursor
    struct FUSEcursor
    {
        HCURSOR hcursor;
    };
    // Windows :: window handle
    struct FUSEwindow
    {
        // Object requirements
        int w;
        int h;
        int id;
        char * name;
        // Windows :: requirements
        HWND hwnd;
        DWORD style;
    };
    // Windows :: window procedure
    LRESULT CALLBACK _fusewin32_WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//--------------------------------------------------------------------------------------------------
#endif