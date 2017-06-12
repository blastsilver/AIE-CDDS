#pragma once

namespace util
{
	template <typename T> class AATree
	{
		// typedef
		typedef Iterator<T> AAIterator;
        // variables
		AAIterator * m_root;
		AAIterator * m_NULL; // ### NEEDS TO BE REMOVED ###
	public:
		// public defaults
		inline AATree()
		{
			// initialize values
			this->m_NULL = new AAIterator();
			this->m_NULL->left() = this->m_NULL;
			this->m_NULL->right() = this->m_NULL;
			// set root as NULL (check skew & split)
			this->m_root = this->m_NULL;
		}
		inline ~AATree()
		{
			// erase tree
			this->erase();
		}
		inline AATree(const AATree<T> & other) : AATree()
		{
			// copy the tree
			this->copyIterator(this->m_root, other.m_root);
		}
        // public functions
        inline void erase()
        {
            // delete the root
            this->deleteIterator(this->m_root);
            // set root as NULL (check skew & split)
            this->m_root = this->m_NULL;
        }
        inline void remove(const T & value)
        {
            // remove value
            this->removeNode(this->m_root, value);
        }
		inline void insert(const T & value)
		{
			// insert value
            this->insertIterator(this->m_root, value);
		}
		inline bool isEmpty()
		{
			// check if empty
			return this->isIteratorNull(m_root);
		}
		inline AAIterator * & end()
		{
			// return empty node
			return this->m_NULL;
		}
		inline AAIterator * & root()
		{
			// return root node
			return this->m_root;
		}
        inline T & find(const T & value)
        {
            // serach value
            return this->searchIterator(this->m_root, value)->value();
        }
        // public operator overloading
		inline void operator=(const AATree<T> & other)
		{
			// clear values
			this->clear();
			// copy the tree
			this->copyIterator(this->m_root, other.m_root);
		}
	private:
        // private functions
        inline void skewIterator(AAIterator * & iterator)
        {
            // check for left horizontal link
            if (iterator->left()->level() == iterator->level())
            {
                // rotate iterator right
				AAIterator * temp = iterator->left();
				iterator->left() = temp->right();
				temp->right() = iterator;
				iterator = temp;
            }
        }
		inline void copyIterator(AAIterator * & iterator, AAIterator * & other)
		{
			// check if empty
			if (this->isIteratorNull(other)) return;
			// create new value
			iterator = new AAIterator(other->value());
			// copy branch nodes
			this->copyIterator(iterator->prev(), other->prev);
			this->copyIterator(iterator->next(), other->next);
		};
        inline void splitIterator(AAIterator * & iterator)
        {
            // check for double red's
            if (iterator->right()->right()->level() == iterator->level())
            {
                // rotate iterator left
				AAIterator * temp = iterator->right();
				iterator->right() = temp->left();
				temp->left() = iterator;
				iterator = temp;
				// increment iterator level
				iterator->level()++;
            }
        }
		inline bool isIteratorNull(AAIterator * & iterator)
		{
			// check if iterator points to itself
			return iterator->next() == iterator;
		}
        inline void deleteIterator(AAIterator * & iterator)
        {
            // check if empty
            if (this->isIteratorNull(iterator)) return;
            // delete branches
            this->deleteIterator(iterator->prev());
            this->deleteIterator(iterator->next());
            // delete current node
            delete iterator;
        }
        inline void insertIterator(AAIterator * & iterator, const T & value)
		{
			// check if empty & create new node
			if (this->isIteratorNull(iterator)) iterator = new AAIterator(value, this->m_NULL, this->m_NULL);
			// keep searching nodes
			else this->insertIterator(T(value) < iterator->value() ? iterator->prev() : iterator->next(), value);
            // skew & split node
            this->skewIterator(iterator);
            this->splitIterator(iterator);
		}
		// #########################
		// ### NEEDS IMPROVEMENT ###
        inline void removeNode(AAIterator * & node, const T & value)
        {
            static AAIterator * lastNode, * deletedNode = this->m_NULL;
            // check if empty
            if (node == this->m_NULL) return;
            // Step 1: Search down the tree and set lastNode and deletedNode
            lastNode = node;
            if (T(value) < node->value())
                this->removeNode(node->left(), value);
            else
            {
                deletedNode = node;
                this->removeNode(node->right(), value);
            }
            // Step 2: If at the bottom of the tree and x is present, we remove it
            if (node == lastNode)
            {
                if (deletedNode == this->m_NULL || T(value) != deletedNode->value())
                    return;   // Item not found; do nothing
                deletedNode->value() = node->value();
                deletedNode = this->m_NULL;
                node = node->right();
                delete lastNode;
            }
            // Step 3: Otherwise, we are not at the bottom; rebalance
            else if (node->left()->level() < node->level() - 1 || node->right()->level() < node->level() - 1)
            {
                if (node->right()->level() > --node->level()) node->right()->level() = node->level();
                skewIterator(node);
                skewIterator(node->right());
                skewIterator(node->right()->right());
                splitIterator(node);
                splitIterator(node->right());
            }
        }
		// ### NEEDS IMPROVEMENT ###
		// #########################
        inline AAIterator * & searchIterator(AAIterator * & iterator, const T & value)
        {
            // check for empty
            if (this->isIteratorNull(iterator)) throw "AATree :: value not found!";
            // check for value
            if (T(value) == iterator->value()) return iterator;
            // keep searching nodes
            return this->searchIterator((T(value) < iterator->value()) ? iterator->left() : iterator->right(), value);
        }
	};
}