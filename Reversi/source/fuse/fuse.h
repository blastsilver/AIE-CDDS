#pragma once
//--------------------------------------------------------------------------------------------------
//-- API Objects -----------------------------------------------------------------------------------

    // Fuse window icon
    struct FUSEicon;
    // Fuse window cursor
    struct FUSEcursor;
    // Fuse window handle
    struct FUSEwindow;
    // Fuse app callbacks
    class FUSEapp
    {
    public:
        // Called on end message
        virtual void OnEnd() {};
        // Called on begin message
        virtual void OnBegin() {};
        // Called on error message
        virtual void OnError(const char * name) {};
        // Called on update message
        virtual void OnUpdate(const float delta) {};
        // Called on window paint message
        virtual void OnWindowPaint(FUSEwindow * window) {};
        // Called on window create message
        virtual void OnWindowCreate(FUSEwindow * window) {};
        // Called on window destroy message
        virtual void OnWindowDestroy(FUSEwindow * window) {};
        // Called on window key state message
        virtual void OnWindowKeyState(FUSEwindow * window, int key, int state) {};
        // Called on window mouse move message
        virtual void OnWindowMouseMove(FUSEwindow * window, int posX, int posY) {};
        // Called on window mouse state message
        virtual void OnWindowMouseState(FUSEwindow * window, int key, int state) {};
    };

//--------------------------------------------------------------------------------------------------
//-- API Functions ---------------------------------------------------------------------------------

    // Execute the app
    void fuseExecute(FUSEapp * application);
    // Set window hint
    void fuseWindowHint(int hint, int value);
    // Close the window
    void fuseCloseWindow(FUSEwindow * window);
    // Update the window
    void fuseUpdateWindow(FUSEwindow * window);
    // Set window position
    void fuseSetWindowPos(FUSEwindow * window, int x, int y);
    // Set window dimensions
    void fuseSetWindowSize(FUSEwindow * window, int width, int height);
    // Create a new window handle
    FUSEwindow * fuseCreateWindow(int width, int height, char * name);

//--------------------------------------------------------------------------------------------------