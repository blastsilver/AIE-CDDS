#pragma once
//-- Dependencies ----------------------------------------------------------------------------------

    // library
    #include <string>
    #include <objidl.h>
    #include <gdiplus.h>
    #include <Windows.h>
    using namespace Gdiplus;
    #pragma comment (lib,"Gdiplus.lib")

    // project
    #include "State.h"
    #include "StateManager.h"
    #include "GameManager.h"

//-- Declarations ----------------------------------------------------------------------------------

    extern GameManager singleton;

//--------------------------------------------------------------------------------------------------