#include <ctime>
#include <random>
#include <iostream>
#include <Windows.h>
#include <CCON\ccon.h>

#include "List.h"

void main()
{
    List<int> list;

    for (int i = 0; i < 10; i++)
    {
        list.pushBack(i);
        //list.pushFront(i);
    }
    for (int i = 0; i < 5; i++)
    {
        list.popBack();
        list.popFront();
    }

    for (List<int>::Node * i = list.first(); i != list.end(); i = i->next)
    {
        std::cout << i->value << ",";
    }

    ccon::cconInit();
    ccon::cconSize(40, 40);
    ccon::cconViewport(0, 0, 40, 40);

    while (ccon::cconRunning())
    {
        
    }

    ccon::cconTerminate();
}