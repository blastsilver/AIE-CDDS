#pragma once
//--------------------------------------------------------------------------------------------------
//-- Dependencies ----------------------------------------------------------------------------------

    #include "fuse-core.h"

//--------------------------------------------------------------------------------------------------
//-- Definitions -----------------------------------------------------------------------------------

    void _fuseAPIWindowInit(FUSEapp * app);
    void _fuseAPIWindowMove(FUSEwindow * window, int x, int y);
    void _fuseAPIWindowSize(FUSEwindow * window, int w, int h);
    void _fuseAPIWindowClose(FUSEwindow * window);
    void _fuseAPIWindowUpdate(FUSEwindow * window);
    void _fuseAPIWindowTerminate();
    bool _fuseAPIWindowPoolEvents();
    FUSEwindow * _fuseAPIWindowCreate(int w, int h, char * name);

//--------------------------------------------------------------------------------------------------