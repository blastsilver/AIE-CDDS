#pragma once
//https://www.panix.com/~elflord/cpp/list_howto/

namespace AIEtutorials
{
	template<typename T> class List
	{
	public:
		struct Node
		{
			T value;
			Node * next;
			Node(const T & value, Node * next = nullptr) : value(value), next(next) {};
		};

		List() : head(nullptr) {};
		void pushFront(const T & value)
		{
			this->head = new Node(value, this->head);
		}

		Node * end() { return nullptr; }
		Node * begin() { return head; }

	private:
		Node * head;
	};
}