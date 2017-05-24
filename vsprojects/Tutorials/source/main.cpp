#include <ctime>
#include <random>
#include <iostream>
#include <Windows.h>
#include <CCON\ccon.h>

void main()
{


    ccon::cconInit();
    ccon::cconSize(40, 40);
    ccon::cconViewport(0, 0, 40, 40);

    while (ccon::cconRunning())
    {
        
    }

    ccon::cconTerminate();
}