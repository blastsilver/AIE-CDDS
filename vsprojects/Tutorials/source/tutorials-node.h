#pragma once

namespace tutorials
{
	template<typename T> struct Node
	{
		T value;
		Node * next;
		Node * prev;
		// initialization
		Node() : Node(0, nullptr, nullptr) {};
		Node(const T & value) : Node(value, nullptr, nullptr) {};
		Node(const T & value, Node * prev, Node * next)
		{
			// initialize values
			this->prev = prev;
			this->next = next;
			this->value = value;
		};
		// class core methods
		bool isEmpty() { return this->next == nullptr && this->prev == nullptr; };
	};
}