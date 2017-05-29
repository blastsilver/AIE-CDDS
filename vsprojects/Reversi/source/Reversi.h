#pragma once
//-- Dependencies ----------------------------------------------------------------------------------

    #include <string>
    #include <objidl.h>
    #include <gdiplus.h>
    #include <Windows.h>
    using namespace Gdiplus;
    #pragma comment (lib,"Gdiplus.lib")

    #include "State.h"
    #include "GameManager.h"
    #include "StateManager.h"
    #include "StateClasses.h"

//-- Declarations ----------------------------------------------------------------------------------

    extern GameManager singleton;

//--------------------------------------------------------------------------------------------------