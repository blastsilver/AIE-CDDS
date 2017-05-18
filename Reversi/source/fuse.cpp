//--------------------------------------------------------------------------------------------------
//-- Dependencies ----------------------------------------------------------------------------------

    #include "fuse-core.h"
    #include "fuse-window.h"

//--------------------------------------------------------------------------------------------------
//-- Fuse Declarations -----------------------------------------------------------------------------

    void fuseWindowHint(int hint, int value)
    {
        throw "fuse :: not working!";
    }
    void fuseCloseWindow(FUSEwindow * window)
    {
        // Fuse :: stop the window
        _fuseAPIWindowClose(window);
    }
    void fuseUpdateWindow(FUSEwindow * window)
    {
        // Fuse :: update the window
        _fuseAPIWindowUpdate(window);
    }
    void fuseSetWindowPos(FUSEwindow * window, int x, int y)
    {
        // Fuse :: move the window
        _fuseAPIWindowMove(window, x, y);
    }
    void fuseSetWindowSize(FUSEwindow * window, int width, int height)
    {
        // Fuse :: resize the window
        _fuseAPIWindowSize(window, width, height);
    }
    void fuseExecute(FUSEapp * application)
    {
        try
        {
            // Fuse :: begin application
            application->OnBegin();
            // Fuse :: initialize all
            _fuseAPIWindowInit(application);
            // Fuse :: update while window is running
            while (_fuseAPIWindowPoolEvents()) application->OnUpdate(0);
        }
        // Fuse :: a error message was caught
        catch (const char * error) { application->OnError(error); }
        // Fuse :: a unknow message was thrown
        catch (...) { application->OnError("fuse :: Unknown exception was thrown!"); }
        // Fuse :: end application
        application->OnEnd();
        _fuseAPIWindowTerminate();
    }
    FUSEwindow * fuseCreateWindow(int width, int height, char * name)
    {
        // Fuse :: create new window
        return _fuseAPIWindowCreate(width, height, name);
    }

//--------------------------------------------------------------------------------------------------