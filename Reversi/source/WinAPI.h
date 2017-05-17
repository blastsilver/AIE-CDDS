#pragma once
//-- Dependencies ----------------------------------------------------------------------------------

    struct Icon;
    struct Cursor;
    struct Window;
    struct WindowClass;
    struct WindowEvents;

//--------------------------------------------------------------------------------------------------
//-- Definitions -----------------------------------------------------------------------------------

    void WindowHint(Window * window, int hint);
    void WindowClose(Window * window);
    void SetWindowPos(Window * window, int x, int y);
    void SetWindowSize(Window * window, int width, int height);
    void SetWindowCallbacks(WindowClass * wClass, WindowEvents * wEvents);
    bool WindowClassShouldClose(WindowClass * wClass);
    Window * CreateWindow(int width, int height, char * name, WindowClass * wClass);
    WindowClass * CreateWindowClass(char * name, Icon * icon, Cursor * cursor);

//--------------------------------------------------------------------------------------------------