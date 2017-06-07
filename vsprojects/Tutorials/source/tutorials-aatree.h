#pragma once

namespace tutorials
{
	template <typename T> class AATree
	{
        // variables
		Node<T> * m_root;
        Node<T> * m_NULLNODE;
	public:
		// initialization
		inline AATree()
		{
			// init values
			this->init();
		}
		inline ~AATree()
		{
			// clear values
			this->erase();
		}
		inline AATree(const AATree<T> & other)
		{
			// init values
			this->init();
			// copy the tree
			this->copyNode(this->m_root, other.m_root);
		}
        // public functions
        inline void erase()
        {
            // delete all nodes
            this->removeNodes(this->m_root);
            // set root as null (NULLNODE prevents problems with skew & split)
            this->m_root = m_NULLNODE;
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
			return this->m_root == this->m_NULLNODE;
		}
		inline Node<T> * & end()
		{
			// return empty node
			return this->m_NULLNODE;
		}
		inline Node<T> * & root()
		{
			// return root node
			return this->m_root;
		}
        inline Node<T> * & find(const T & value)
        {
            // serach value
            return this->searchNode(this->m_root, value);
        }
        // public operator overloading
		inline void operator=(const AATree<T> & other)
		{
			// clear values
			this->clear();
			// copy the tree
			this->copyNode(this->m_root, other.m_root);
		}
	private:
        // private functions
		inline void init()
		{
			// initialize values
            this->m_NULLNODE = new Node<T>(nullptr, nullptr);
            this->m_NULLNODE->right = this->m_NULLNODE;
            this->m_NULLNODE->left = this->m_NULLNODE;
            // set root as null (NULLNODE prevents problems with skew & split)
			this->m_root = AATree::m_NULLNODE;
		}
        inline void skewNode(Node<T> * & node)
        {
            // check for left horizontal link
            if (node->left->level == node->level)
            {
                // rotate right
                this->rotateNodeRight(node);
            }
        }
		inline void copyNode(Node<T> * & node, Node<T> * & other)
		{
			// check if empty
			if (other == nullptr) return;
			// store the value
			node = new Node<T>(other->value);
			// copy nested nodes
			this->copyNode(node->right, other->right);
			this->copyNode(node->left, other->left);
		};
        inline void splitNode(Node<T> * & node)
        {
            // check for double red's
            if (node->right->right->level == node->level)
            {
                // rotate left
                this->rotateNodeLeft(node);
                node->level++;
            }
        }
        inline void insertNode(Node<T> * & node, const T & value)
		{
			// check if empty
            if (node == this->m_NULLNODE)
            {
                // create new node (NULLNODE prevents problems with skew & split)
                node = new Node<T>(value, this->m_NULLNODE, this->m_NULLNODE);
            }
			// keep searching nodes
			else
			{
                // insert on left node
                this->insertNode((value < node->value) ? node->left : node->right, value);
			}
            // skew & split node
            this->skewNode(node);
            this->splitNode(node);
		}
        inline void removeNode(Node<T> * & node, const T & value)
        {
            static Node<T> * lastNode, * deletedNode = this->m_NULLNODE;
            // check if empty
            if (node == this->m_NULLNODE) return;
            // Step 1: Search down the tree and set lastNode and deletedNode
            lastNode = node;
            if (value < node->value)
                this->removeNode(node->left, value);
            else
            {
                deletedNode = node;
                this->removeNode(node->right, value);
            }
            // Step 2: If at the bottom of the tree and x is present, we remove it
            if (node == lastNode)
            {
                if (deletedNode == this->m_NULLNODE || value != deletedNode->value)
                    return;   // Item not found; do nothing
                deletedNode->value = node->value;
                deletedNode = this->m_NULLNODE;
                node = node->right;
                delete lastNode;
            }
            // Step 3: Otherwise, we are not at the bottom; rebalance
            else if (node->left->level < node->level - 1 || node->right->level < node->level - 1)
            {
                if (node->right->level > --node->level) node->right->level = node->level;
                skewNode(node);
                skewNode(node->right);
                skewNode(node->right->right);
                splitNode(node);
                splitNode(node->right);
            }
        }
        inline void removeNodes(Node<T> * & node)
        {
            // check if empty
            if (node == this->m_NULLNODE) return;
            // delete branches
            this->removeNodes(node->left);
            this->removeNodes(node->right);
            // delete the current node
            delete node;
        }
        inline void rotateNodeLeft(Node<T> * & node)
        {
            Node<T> * temp = node->right;
            node->right = temp->left;
            temp->left = node;
            node = temp;
        }
        inline void rotateNodeRight(Node<T> * & node)
        {
            Node<T> * temp = node->left;
            node->left = temp->right;
            temp->right = node;
            node = temp;
        }
        inline Node<T> * & searchNode(Node<T> * & node, const T & value)
        {
            // check for empty
            if (node == this->m_NULLNODE) throw "AATree :: value not found!";
            // check for value
            if (node->value == value) return node;
            // keep searching nodes
            return this->searchNode((value < (*node)) ? node->left : node->right, value);
        }
	};
}