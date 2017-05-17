#pragma once
//-- Definitions -----------------------------------------------------------------------------------

    class Window
    {
    public:
        // Window :: hide the window
        void hide();
        // Window :: show the window
        void show();
        // Window :: set window position
        void move(int x, int y);
        // Window :: set window size
        void size(int width, int height);
        // Window :: close the window
        void close();
    private:
        // :: friends
        friend WindowClass;
        // :: variables
        int sizeX;
        int sizeY;
        HWND hwnd;
        char * name;
        // :: constructor
        Window(int width, int height, char * name);
    };

//--------------------------------------------------------------------------------------------------