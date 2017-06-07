//#define SIZE 81

#include <map>
#include <iostream>
#include <Windows.h>
#include "tutorials.h"

typedef tutorials::Node<int> Node_i;
typedef tutorials::List<int> List_i;
typedef tutorials::AATree<int> Tree_i;
//typedef tutorials::HashMap<int> Hash_i;

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
        printTree(node->left, null, x - 5);
        printTree(node->right, null, x + 5);
    }
}

void main()
{
    Tree_i tree;

    for (int i = 1; i <= 8; i++)
    {
        tree.insert(i);
    }

    printTree(tree.root(), tree.end(), 30);

    //Hash_i hash;

    //hash.insert("key_001", 0);
    //hash.insert("key_002", 1);
    //hash.insert("key_003", 2);
    //hash.insert("key_004", 3);
    //hash.insert("key_005", 4);
    //hash.insert("key_006", 5);

	std::cout << "\n";

        

	system("pause");
}