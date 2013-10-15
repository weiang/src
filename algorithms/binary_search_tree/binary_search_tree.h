#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

template <typename Object>
class BinarySearchTree
{
	public:
		BinarySearchTree() : root() {}	// Default constructor
		BinarySearchTree(const BinarySearchTree &);	// Copy constructor
		~BinarySearchTree();	// Deconstructor

		const Object& findMax() const;
		const Object& findMin() const;
		bool contains(const Object&) const;
		bool isEmpty() const;
		void printTree() const;

		void makeEmpty();
		void insert(const Object&);
		void remove(const Object&);

		const BinarySearchTree& operator=(const BinarySearchTree&);	// Copy assignment

	private:
		/* Embeded data structure */
		struct BinaryNode 
		{
			Object element;
			BinaryNode *left;
			BinaryNode *right;
			
			BinaryNode(const Object& theElement, BinaryNode *lt, BinaryNode *rt) : element(theElement), left(lt), right(rt) {}
		};

		BinaryNode *root;
		void insert(const Object&, BinaryNode *&);
		void remove(const Object&, BinaryNode *&);
		BinaryNode *search(const Object&, const BinaryNode *) const;
		BinaryNode *findMax(const BinaryNode *) const;
		BinaryNode *findMin(const BinaryNode *) const;
		bool contains(const Object&, const BinaryNode *) const;
		bool isEmpty(const BinaryNode *) const;
		void makeEmpty(BinaryNode *&);
		void printTree(const BinaryNode *) const;
		BinaryNode *clone(BinaryNode *i);
};

#endif // _BINARY_SEARCH_TREE_
