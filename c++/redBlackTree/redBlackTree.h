#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

#include <iostream>

/**
 * Red-black tree class
 */

template <typename Comparable>
class RedBlackTree {
	public:
		explicit RedBlackTree(const Comparable& negInf);
		RedBlackTree(const RedBlackTree& rhs);
		~RedBlackTree();

		const Comparable& findMax()const;
		const Comparable& findMin() const;
		Comparable find(const Comparable&);
		bool contains(const Comparable&);
		bool isEmpty() const;
		void printTree() const;

		void makeEmpty();
		void insert(const Comparable&);
		void remove(const Comparable&);

		enum { RED, BLACK };

		const RedBlackTree& operator=(const RedBlackTree& rhs);

	private:
		typedef struct RedBlackNode {
			Comparable element;
			RedBlackNode *left;
			RedBlackNode *right;
			RedBlackNode *parent;
			int color;

			RedBlackNode(const Comparable theElement = Comparable(), RedBlackNode *left = NULL, RedBlackNode *right = NULL, RedBlackNode *parent = NULL, int color = BLACK) :
							element(theElement), left(left), right(right), parent(parent), color(color) { }
		} RedBlackNode;

		RedBlackNode *header;
		RedBlackNode *nullNode;
		const Comparable ITEM_NOT_FOUND;
		RedBlackNode *grand;
		RedBlackNode *parent;
		RedBlackNode *current;
	
		void initTree();
		bool isBlack(const RedBlackNode *) const;
		bool isRed(const RedBlackNode*) const;
		RedBlackNode *findAux(const Comparable&);

		// Usual recursive stuff
		void printTree(const RedBlackNode *) const;
		RedBlackNode* clone(const RedBlackNode *);
		void makeEmpty(RedBlackNode*);

		// Red-Black tree manipulations 
		void colorExchange(RedBlackNode *);
		void fixUp(RedBlackNode *);
		void rotateWithLeftChild(RedBlackNode *);
		void rotateWithRightChild(RedBlackNode *);
		void insertButtomUp(const Comparable&);
		void insertTopDown(const Comparable&);
};

#include "redBlackTree.cc"
#endif	// RED_BLACK_TREE_H_