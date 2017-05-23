#include <ctime>
#include <random>
#include <iostream>
#include <CCON\ccon.h>

#include "List.h"

void main()
{
	using namespace AIEtutorials;

	List<int> list;
	list.pushFront(3);
	list.pushFront(2);
	list.pushFront(1);

	for (List<int>::Node* i = list.begin(); i != list.end(); i = i->next)
		std::cout << i->value << std::endl;

	system("pause");

    ccon::cconInit();
    ccon::cconSize(40, 40);
    ccon::cconViewport(0, 0, 40, 40);

    while (ccon::cconRunning())
    {
        
    }

    ccon::cconTerminate();
}