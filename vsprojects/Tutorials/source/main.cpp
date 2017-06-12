//#define SIZE 81

#include "util.h"

#include <map>
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace util;

void gotoxy(int x, int y)
{
	COORD p = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void main()
{
	std::cout << "testing AATree\n\n";

	HashMap<int> map;

	map.insert("my key 00",  1);
	map.insert("my key 01",  2);
	map.insert("my key 02",  4);
	map.insert("my key 03",  8);
	map.insert("my key 04", 16);
	map.insert("my key 05", 32);
	map.insert("my key 06", 64);

	std::cout << map.get("my key 06") << std::endl;

	system("pause");
}