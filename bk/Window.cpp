//-- Dependencies ----------------------------------------------------------------------------------

    #include "main.h"

//--------------------------------------------------------------------------------------------------
//-- Definitions -----------------------------------------------------------------------------------

    Window::Window(int width, int height, char * name)
    {
        // assign values
        this->hwnd = NULL;
        this->name = name;
        this->sizeX = width;
        this->sizeY = height;
    }
    void Window::hide()
    {
        // check parameters
        FUSE_ASSERT(this->hwnd != NULL, "window was not created");
        // hide the window
        ShowWindow(this->hwnd, SW_HIDE);
    }
    void Window::show()
    {
        // check parameters
        FUSE_ASSERT(this->hwnd != NULL, "window was not created");
        // show the window
        ShowWindow(this->hwnd, SW_SHOW);
    }
    void Window::move(int x, int y)
    {
        // check parameters
        FUSE_ASSERT(this->hwnd != NULL, "window was not created");
        // set the window size
        SetWindowPos(this->hwnd, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    }
    void Window::size(int width, int height)
    {
        // check parameters
        FUSE_ASSERT(this->hwnd != NULL, "window was not created");
        // set the window size
        this->sizeX = width;
        this->sizeY = height;
        SetWindowPos(this->hwnd, NULL, 0, 0, width, height, SWP_NOREPOSITION | SWP_NOZORDER);
    }
    void Window::close()
    {
        // check parameters
        FUSE_ASSERT(this->hwnd != NULL, "window was not created");
        // close the window
        CloseWindow(this->hwnd);
    }