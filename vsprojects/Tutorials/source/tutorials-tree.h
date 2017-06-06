#pragma once

namespace tutorials
{
	template<typename T> class Tree
	{
	public:
		Node<T> * m_root;
        Node<T> * NULLNODE;
		// initialization
		inline Tree()
		{
			// init values
			this->init();
		}
		inline ~Tree()
		{
			// clear values
			//this->clear();
		}
		inline Tree(const Tree<T> & other)
		{
			// init values
			this->init();
			// copy the tree
			this->copyNode(this->m_root, other.m_root);
		}
		inline void operator=(const Tree<T> & other)
		{
			// clear values
			this->clear();
			// copy the tree
			this->copyNode(this->m_root, other.m_root);
		}
        inline void remove(const T & value)
        {
            // remove value
            this->removeNode(this->m_root, value);
        }
		inline void insert(const T & value)
		{
			// insert value
            this->insertNode(this->m_root, value);
		}
		inline bool isEmpty()
		{
			// check if empty
			return this->m_root == this->NULLNODE;
		}
		inline Node<T> * end()
		{
			// return empty node
			return this->NULLNODE;
		}
		inline Node<T> * root()
		{
			// return root node
			return this->m_root;
		}

        void skew(Node<T> * & node)
        {
            // check for left horizontal link
            if (node->prev->level == node->level)
            {
                // rotate right
                this->rotateNodeRight(node);
            }
        }
        void split(Node<T> * & node)
        {
            // check for double red's
            if (node->next->next->level == node->level)
            {
                // rotate left
                this->rotateNodeLeft(node);
                node->level++;
            }
        }

	private:
		inline void init()
		{
			// initialize values
            this->NULLNODE = new Node<T>(nullptr, nullptr);
            this->NULLNODE->next = this->NULLNODE;
            this->NULLNODE->prev = this->NULLNODE;
            // set root as null (NULLNODE prevents problems with skew & split)
			this->m_root = Tree::NULLNODE;
		}
		inline void copyNode(Node<T> * & node, Node<T> * & other)
		{
			// check if empty
			if (other == nullptr) return;
			// store the value
			node = new Node<T>(other->value);
			// copy nested nodes
			this->copyNode(node->next, other->next);
			this->copyNode(node->prev, other->prev);
		};
        inline void insertNode(Node<T> * & node, const T & value)
		{
			// check if empty
            if (node == this->NULLNODE)
            {
                // create new node (NULLNODE prevents problems with skew & split)
                node = new Node<T>(value, this->NULLNODE, this->NULLNODE);
            }
			// keep searching nodes
			else
			{
                // insert on left node
                this->insertNode((value < node->value) ? node->prev : node->next, value);
			}
            // skew & split node
            this->skew(node);
            this->split(node);
		}
        inline void removeNode(Node<T> * & node, const T & value)
        {
            static Node<T> * lastNode, * deletedNode = this->NULLNODE;
            // check if empty
            if (node == this->NULLNODE) return;
            // Step 1: Search down the tree and set lastNode and deletedNode
            lastNode = node;
            if (value < node->value)
                this->removeNode(node->prev, value);
            else
            {
                deletedNode = node;
                this->removeNode(node->next, value);
            }
            // Step 2: If at the bottom of the tree and x is present, we remove it
            if (node == lastNode)
            {
                if (deletedNode == this->NULLNODE || value != deletedNode->value)
                    return;   // Item not found; do nothing
                deletedNode->value = node->value;
                deletedNode = this->NULLNODE;
                node = node->next;
                delete lastNode;
            }
            // Step 3: Otherwise, we are not at the bottom; rebalance
            else if (node->prev->level < node->level - 1 || node->next->level < node->level - 1)
            {
                if (node->next->level > --node->level) node->next->level = node->level;
                skew(node);
                skew(node->next);
                skew(node->next->next);
                split(node);
                split(node->next);
            }
        }
        inline void rotateNodeLeft(Node<T> * & node)
        {
            Node<T> * temp = node->next;
            node->next = temp->prev;
            temp->prev = node;
            node = temp;
        }
        inline void rotateNodeRight(Node<T> * & node)
        {
            Node<T> * temp = node->prev;
            node->prev = temp->next;
            temp->next = node;
            node = temp;
        }
        inline Node<T> * & searchNode(Node<T> * & node, const T & value)
        {
            // check for empty
            if (node == this->NULLNODE) return nullptr;
            // check for value
            if (node->value == value) return node;
            // keep searching nodes
            return this->searchNode((value < node->value) ? node->prev : node->next, value);
        }
	};
}