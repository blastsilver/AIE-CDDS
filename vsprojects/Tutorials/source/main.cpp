//#define SIZE 81

#include <iostream>
#include <Windows.h>
#include "tutorials.h"

typedef tutorials::Node<int> Node_i;
typedef tutorials::List<int> List_i;
typedef tutorials::Tree<int> Tree_i;

void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void printTree(Node_i * node, Node_i * null, int x)
{
    if (node != null)
    {
        gotoxy(x, node->level);
        std::cout << "[" << node->value << "]";
        printTree(node->prev, null, x - 5);
        printTree(node->next, null, x + 5);
    }
}

void main()
{
    Tree_i tree;
    int * buffer;
    int iterator = 5;

    for (int i = 1; i <= 8; i++)
    {
        tree.insert(i);
    }

    printTree(tree.root(), tree.end(), 30);

	std::cout << "\n";

	system("pause");
}