#include "util.h"
#include <iostream>
using namespace util;

void print(Iterator<int> & obj)
{
	// print iterator
	if (&obj == obj.next()) return;
	std::cout << "\t<< Iterator[" << &obj << "] >>\n";
	std::cout << "\t- iterator.value() = " << (int)obj << "\n";
	std::cout << "\t- iterator.right() = " << obj.right() << "\n";
	std::cout << "\t- iterator.left()  = " << obj.left() << "\n\n";
	if (obj.next() != nullptr) print(*obj.next());
}
void print(Iterator<Comparable<int>> & obj)
{
	// print iterator
	if (&obj == obj.next()) return;
	if (obj.left() != nullptr) print(*obj.left());
	std::cout << "\t<< ComparableIterator[" << &obj << "] >>\n";
	std::cout << "\t- iterator.value() = " << (int)obj << "\n";
	std::cout << "\t- iterator.level() = " << obj.level() << "\n";
	std::cout << "\t- iterator.right() = " << obj.right() << "\n";
	std::cout << "\t- iterator.left()  = " << obj.left() << "\n\n";
	if (obj.right() != nullptr) print(*obj.right());
}
void print(Iterator<HashComparable<int>> & obj)
{
	// print iterator
	if (&obj == obj.next()) return;
	if (obj.left() != nullptr) print(*obj.left());
	std::cout << "\t<< HashComparableIterator[" << &obj << "] >>\n";
	std::cout << "\t- iterator.value() = " << (int)obj << "\n";
	std::cout << "\t- iterator.right() = " << obj.right() << "\n";
	std::cout << "\t- iterator.left()  = " << obj.left() << "\n";
	std::cout << "\t- iterator.hash()  = " << obj.value().hash() << "\n\n";
	if (obj.right() != nullptr) print(*obj.right());
}
void print(HashMap<int> & obj)
{
	// print hash map
	std::cout << "<< HashMap | " << &obj << " >>\n\n";
	print(*obj.root());
}
void print(LinkedList<int> & obj)
{
	// print linked list
	std::cout << "<< LinkedList | " << &obj << " >>\n\n";
	print(*obj.head());
}
void print(AATree<Comparable<int>> & obj)
{
	// print aa tree
	std::cout << "<< AATree | " << &obj << " >>\n\n";
	print(*obj.root());
}

void main()
{
    // #################################################################################################
    // #################################################################################################
    // #################################################################################################

    std::cout << "--------------------------------------------------\n";
    std::cout << "--[ Unit Test 1] ---------------------------------\n";
    std::cout << "-- Expected values : [2, 1, -1, -2]\n";
    std::cout << "--------------------------------------------------\n\n";
    // testing Lists
    LinkedList<int> list;
    // insert values [3, 2, 1, 0, -1, -2, -3]
    list.insert(0);
    list.pushBack(-1);
    list.pushBack(-2);
    list.pushBack(-3);
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    print(list);
    // remove values [0, -3, 3]
    list.remove(0);
    list.popBack();
    list.popFront();
    print(list);

    // #################################################################################################
    // #################################################################################################
    // #################################################################################################

    std::cout << "--------------------------------------------------\n";
    std::cout << "--[ Unit Test 2] ---------------------------------\n";
    std::cout << "-- Expected values : [ 1, 2, 5, 9, 10, 13, 15 ]\n";
    std::cout << "--------------------------------------------------\n\n";
    // testing Trees
    AATree<Comparable<int>> tree;
    // insert values [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
    for (int i = 0; i < 15; i++) tree.insert(i + 1);
    print(tree);
    // remove value [3, 4, 6, 7, 8, 11, 12, 14]
    tree.remove(8);
    tree.remove(3);
    tree.remove(4);
    tree.remove(11);
    tree.remove(6);
    tree.remove(12);
    tree.remove(14);
    tree.remove(7);
    print(tree);

    // #################################################################################################
    // #################################################################################################
    // #################################################################################################

    std::cout << "--------------------------------------------------\n";
    std::cout << "--[ Unit Test 3] ---------------------------------\n";
    std::cout << "-- Expected values : [ 1, 2 ]\n";
    std::cout << "--------------------------------------------------\n\n";
    // testing HashMaps
    HashMap<int> map;
    // insert values [{ "keep": 0, "your": 1, "data": 2, "here": 3 }]
    map.insert("keep", 0);
    map.insert("your", 1);
    map.insert("data", 2);
    map.insert("here", 3);
    print(map);
    // remove values ["keep", "here"]
    map.remove("keep");
    map.remove("here");
    print(map);

    // #################################################################################################
    // #################################################################################################
    // #################################################################################################

    std::cout << "--------------------------------------------------\n";
    std::cout << "--[ Unit Test 4] ---------------------------------\n";
    std::cout << "--------------------------------------------------\n\n";
    // testing StateManager
    StateManager manager;
    manager.set(States::State1);
    for (int i = 0; i < 25; i++)
    {
        switch (i % 4)
        {
        case 0:
            break;
        case 1:
            i = i + 4;
            manager.set(States::State1);
        case 2:
            i = i - 3;
            manager.set(States::State2);
        case 3:
            manager.set(States::State3);
            break;
        }
        manager.update();
    }
    std::cout << std::endl;

    // #################################################################################################
    // #################################################################################################
    // #################################################################################################

	std::cout << "--------------------------------------------------\n";
	std::cout << "\n~~ Unit Tests Complete! ~~\n\n";
	system("pause");
}