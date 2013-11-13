#ifndef AVL_TREE_
#define AVL_TREE_

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Template class of classic data structure: AVL tree
 * The nodes in AVL tree are of type Comparable, which is a template class parameter
 */

template <typename Comparable>
class AVLtree {
	public:
		/** 
		 * Constructor 
		 */
		AVLtree(const std::vector<Comparable>& rhs) : root(NULL)
		{
			buildTree(rhs);
		}
		AVLtree() { }	// Default constructor

		/**
		 * Destructor 
		 */
		~AVLtree()
		{
			deleteTree(root);
		}

		/**
		 * AVL tree node 
		 */
		typedef struct AvlNode {
			Comparable val;
			AvlNode *left, *right;
			int height;

			AvlNode(Comparable val, AvlNode *left, AvlNode *right, int height = 0) :
				val(val), left(left), right(right), height(height) { }
		} AvlNode;

		/**
		 Return the # of AVL tree nodes 
		 */
		int size() const
		{
			return nsize;
		}

		/**
		 Return the height of AVL tree 
		 */
		int height() const
		{
			return height(root);
		}

		/**
		 * Insert Comparable a into AVL tree if a is not in AVL tree
		 * Nothing will be done if a is already in AVL tree
		 */
		void insert(const Comparable& a) 
		{
			insert(root, a);			
		}

		/**
		 * Delete Comparable a in AVL tree if existed 
		 * Otherwise, nothing will be done
		 */
		void remove(const Comparable& a)
		{
			remove(root, a);
		}

		/**
		 * Return ture if Comparable a is in AVL tree
		 * Return false if Comparable a is not in AVL tree
		 */
		bool isContain(const Comparable& a)
		{
			return search(a) != NULL;
		}

		/**
		 * Return pointer to AVL tree node that contains Comparable a if a is existed 
		 * Return NULL otherwise
		 */
		AvlNode * & search(const Comparable& a)
		{
			return search(root, a);
		}

		/**
		 * Print out the AVL tree on the screen
		 */
		void show() const
		{
			show(root);
			std::cout << std::endl;
		}
		
		/**
		 * Print out the AVL tree with depth
		 */
		void showWithDepth() const
		{
			showWithDepth(root, 0);
			std::cout << std::endl;
		}

	private:
		int nsize;		// # of AVL tree nodes
		AvlNode *root;	// The root of AVL tree
		
		int height(AvlNode *node) const
		{
			return node == NULL ? -1 : node -> height;
		}

		void rotateWithLeft(AvlNode * &r);	// LL
		void rotateWithRight(AvlNode * &r);	// RR
		void doubleRotateWithLeft(AvlNode * &r); // LR
		void doubleRotateWithRight(AvlNode * &r);	// RL
		void deleteTree(AvlNode * r);
		void buildTree(const std::vector<Comparable>& rhs);
		void insert(AvlNode * & r, const Comparable& a);
		void remove(AvlNode * & r, const Comparable& a);
		void show(AvlNode *root) const;
		void showWithDepth(AvlNode *r, int depth) const;
		AvlNode * & search(AvlNode * & root, const Comparable& a);
};


/**
 * Implementation of AVL tree data structure
 */

template <typename Comparable>
void AVLtree<Comparable>::buildTree(const std::vector<Comparable>& a)
{
	for (int i = 0; i != a.size(); i ++)
		insert(a[i]);
}

template <typename Comparable>
void AVLtree<Comparable>::deleteTree(typename AVLtree<Comparable>::AvlNode *root)
{
	if (root == NULL)
		return;
	deleteTree(root -> left);	// Delete left subtree
	deleteTree(root -> right);	// Delete right subtree
	delete root;				// Delete root node 
}

template <typename Comparable>
typename AVLtree<Comparable>::AvlNode * & AVLtree<Comparable>::search(typename AVLtree<Comparable>::AvlNode *& root, const Comparable& a)
{
	if (root == NULL || root -> val == a)
		return root;
	else if (a > root -> val) 
		return search(root -> right, a);
	else 
		return search(root -> left, a);
}

template <typename Comparable>
void AVLtree<Comparable>::rotateWithLeft(typename AVLtree<Comparable>::AvlNode * &r)
{
	AvlNode *tmp = r -> left;
	r -> left = tmp -> right;
	r -> height = std::max(height(r -> left), height(r -> right)) + 1;
	tmp -> right = r;
	tmp -> height = std::max(height(tmp -> left), height(tmp -> right)) + 1;
	r = tmp;
}

template <typename Comparable>
void AVLtree<Comparable>::rotateWithRight(typename AVLtree<Comparable>::AvlNode * &r)
{
	AvlNode *tmp = r -> right;
	r -> right = tmp -> left;
	r -> height = std::max(height(r -> left), height(r -> right)) + 1;
	tmp -> left = r;
	tmp -> height = std::max(height(tmp -> left), height(tmp -> right)) + 1;
	r = tmp;
}

template <typename Comparable>
void AVLtree<Comparable>::doubleRotateWithLeft(typename AVLtree<Comparable>::AvlNode * &r)
{
	rotateWithRight(r -> left);
	rotateWithLeft(r);
}

template <typename Comparable>
void AVLtree<Comparable>::doubleRotateWithRight(typename AVLtree<Comparable>::AvlNode * &r)
{
	rotateWithLeft(r -> right);
	rotateWithRight(r);
}

/**
 * Insert Comparable a into AVL tree if a is not in AVL tree
 * Nothing will be done if a is already in AVL tree
 */
template <typename Comparable>
void AVLtree<Comparable>::insert(typename AVLtree<Comparable>::AvlNode * & root, const Comparable& a)
{
	if (root == NULL) 
		root = new AvlNode(a, NULL, NULL);
	else if (a < root -> val) {
		insert(root -> left, a);	// Insert a into root's left subtree
		if (height(root -> left) - height(root -> right) == 2) {
			if (a < root -> left -> val)
				rotateWithLeft(root);
			else 
				doubleRotateWithLeft(root);
		}
	}
	else if (a > root -> val) {
		insert(root -> right, a);
		if (height(root -> right) - height(root -> left) == 2) {
			if (a > root -> right -> val)
				rotateWithRight(root);
			else 
				doubleRotateWithRight(root);
		}
	}
	else
		;
	root -> height = std::max(height(root -> left), height(root -> right)) + 1;
}

/**
 * Delete Comparable a in AVL tree if existed 
 * Otherwise, nothing will be done
 */
/** 
 * Bugs exist!!!
 */
/*
template <typename Comparable>
void AVLtree<Comparable>::remove(typename AVLtree<Comparable>::AvlNode * & root, const Comparable& a)
{

	if (root == NULL)
		return;
	else if (a < root -> val) {	// Node contains a is on the left subtree
		remove(root -> left, a);

		int h1 = height(root -> right-> left);
		int h2 = height(root -> right -> right);
		if (h2 - h1 == 0 || h2 - h1 == 1)		// RR
			rotateWithRight(root);
		else if (h2 - h1 == -1)		// RL
			doubleRotateWithRight(root);
	}
	else if (a > root -> val) {
		remove(root -> right, a);	// Node contains a is on the right subtree
		int h1 = height(root -> left -> left);
		int h2 = height(root -> left -> right);
		if (h2 - h1 == 0 || h2 - h1 == -1)		// LL
			rotateWithLeft(root);
		else if (h2 - h1 == 1)		// LR
			doubleRotateWithLeft(root);
	}
	else {							// Root is the node that contains a
		if (root -> left && root -> right) {	// Root has two children  
			AvlNode	*pTmp = root;
			AvlNode *tmp = root -> right;
			while (tmp -> left) {	// Find leftmost node of root's right subtree
				if (height(tmp -> left) - height(tmp -> right) == 1)
					tmp -> height --;
				pTmp = tmp;
				tmp = tmp -> left;
			}
			std::swap(tmp -> val, root -> val);
			pTmp -> left = tmp -> right;
			delete tmp;
			pTmp -> height = std::max(height(pTmp -> left), height(pTmp -> right)) + 1;
		}
		else if (!root -> left && !root-> right) {	// Root has no child
			root = NULL;
			return;
		}
		else if (root -> left)	{	// Root just has left child
			AvlNode *tmp = root;
			root = root -> left;
			delete tmp;
			return;
		}
		else {	// Root just has right child
			AvlNode *tmp = root;
			root = root -> right;
			delete tmp;
			return;
		}
	}
	root -> height = std::max(height(root -> left), height(root -> right)) + 1;
}
*/
template <typename Comparable>
void AVLtree<Comparable>::remove(typename AVLtree<Comparable>::AvlNode * & root, const Comparable& a)
{
	std::cout << "AVLtree<Comparable>::reomve() is not implemented!!!" << std::endl;
}

template <typename Comparable>
void AVLtree<Comparable>::show(typename AVLtree<Comparable>::AvlNode*root) const
{
	/* In-order traver */
	if (root == NULL)
		return;
	show(root -> left);
	std::cout << root -> val << " ";
	show(root -> right);
}

template <typename Comparable>
void AVLtree<Comparable>::showWithDepth(typename AVLtree<Comparable>::AvlNode* root, int depth) const
{
	if(root != NULL) {
		showWithDepth(root -> right, depth + 1);
		for (int i = 0; i < depth; i ++) {
			std::cout << " ";
		}
		std::cout << root -> val << std::endl;
		showWithDepth(root -> left, depth + 1);
	}
}
#endif	// AVL_TREE_
