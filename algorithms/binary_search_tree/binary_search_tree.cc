/*************************************************************************
	> File Name: binary_search_tree.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年09月24日 星期二 16时12分01秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include "binary_search_tree.h"

using namespace std;

template <typename Object>
BinarySearchTree<Object>::BinarySearchTree(const BinarySearchTree<Object>& rhs)
{
		root = clone(rhs.root);
}

template <typename Object>
BinarySearchTree<Object>::~BinarySearchTree()
{
	makeEmpty(root);
}

template <typename Object>
const Object& BinarySearchTree<Object>::findMax() const
{
	return findMax(root) -> element;
}

template <typename Object>
const Object& BinarySearchTree<Object>::findMin() const
{
	return findMin(root) -> element;
}

template <typename Object>
bool BinarySearchTree<Object>::contains(const Object& o) const
{
	return contains(o, root);
}

template <typename Object>
bool BinarySearchTree<Object>::isEmpty() const
{
	return isEmpty(root);
}

template <typename Object>
void BinarySearchTree<Object>::printTree() const
{
	printTree(root);
}

template <typename Object>
void BinarySearchTree<Object>::makeEmpty()
{
	makeEmpty(root);
}

template <typename Object>
void BinarySearchTree<Object>::insert(const Object& o)
{
	insert(o, root);
}

template <typename Object>
void BinarySearchTree<Object>::remove(const Object& o)
{
	remove(o, root);
}

// Copy assignment function
template <typename Object>
const BinarySearchTree<Object>& BinarySearchTree<Object>::operator=(const BinarySearchTree& rhs)
{
	if (this != &rhs) {
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

/* Inner implementation of API */
template <typename Object>
typename BinarySearchTree<Object>::BinaryNode *BinarySearchTree<Object>::findMax(const BinarySearchTree<Object>::BinaryNode *root) const
{
	if (root -> right == NULL)
		return root;
	return findMax(root -> right);
}

template <typename Object>
typename BinarySearchTree<Object>::BinaryNode *BinarySearchTree<Object>::findMin(const BinaryNode *root) const
{
	if (root -> left == NULL)
		return root;
	return findMin(root -> left);
}

template <typename Object>
bool BinarySearchTree<Object>::contains(const Object& o, const BinarySearchTree<Object>::BinaryNode * bn) const
{
	if (bn == NULL)
		return false;
	if (bn -> element == o)
		return true;
	else if (bn -> element < o)
		return contains(bn -> left);
	else 
		return contains(bn -> right);
}

template <typename Object>
bool BinarySearchTree<Object>::isEmpty(const BinarySearchTree<Object>::BinaryNode *bn) const
{
	if (bn == NULL)
		return false;
	return true;
}

template <typename Object>
void BinarySearchTree<Object>::makeEmpty(BinaryNode *& bn)
{
	if (bn != NULL) {
		makeEmpty(bn -> left);
		makeEmpty(bn -> right);
		delete bn;
		bn = NULL;
	}
}

/* 
 * Return NULL if it's a empty tree
 * Return the pointer to the node contains the element if the element exists
 * Return the pointer where to insert it if the tree doesn't contain it
 */
template <typename Object>
typename BinarySearchTree<Object>::BinaryNode *BinarySearchTree<Object>::search(const Object& ele, const BinaryNode *root) const
{
	if (root == NULL)
		return NULL;
	BinaryNode *pre;
	BinaryNode *pbn = root;
	while (pbn != NULL) {
		pre = pbn;
		if (pbn -> element < ele)
			pbn = pbn -> right;
		else if (pbn -> element == ele)
			return pbn;
		else 
			pbn = pbn -> left;
	}
	return pre;
}

template <typename Object>
void BinarySearchTree<Object>::insert(const Object& ele, BinaryNode *& root)
{
	BinaryNode *pbn = new BinaryNode(ele, NULL, NULL);

	// Empty tree
/*
	if (root == NULL) {
		root = pbn;
		return;
	}
	
	BinaryNode *ptmp = root;
	BinaryNode *pptmp;
	while (ptmp != NULL) {
		pptmp = ptmp;
		if (ele < ptmp -> element) {
			ptmp = ptmp -> left;
		}
		else {
			ptmp = ptmp -> right;
		}
	}
	if (ele < pptmp -> element)
		pptmp -> left = pbn;
	else 
		pptmp -> right = pbn;
*/
	BinaryNode *p = search(ele, root);
	if (p == NULL) {	// Empty tree
		root = pbn;
		return;
	}	
	else if (p -> element == ele)	// Element to be inserted is already in the tree
		return;
	else if (p -> element < ele)
		p -> right = pbn;
	else 
		p -> left = pbn;

}

template <typename Object>
void BinarySearchTree<Object>::remove(const Object& ele, BinaryNode *& root)
{
	BinaryNode *pbn = search(ele, root);

	if (pbn == NULL || pbn -> element != ele)
		return;		// Empty tree or the tree doesn't contain element
	if (!pbn -> left && !pbn -> right)
		;
	else if (pbn -> left && pbn -> right) {
		BinaryNode *pre = pbn;
		BinaryNode *tmp = pbn -> right;
		while (tmp -> left != NULL) {
			pre = tmp;
			tmp = tmp -> left;
		}
		Object o;
		o = tmp -> element;
		tmp -> element = pbn -> element;
		pbn -> element = o;
		if (tmp -> right)
			pre -> right = tmp -> right;
		delete tmp;
	}
	else if (!pbn -> left) {
	}
	else {
	}
}

/* Inorder pass */
template <typename Object>
void BinarySearchTree<Object>::printTree(const BinaryNode *root) const
{
	if (root == NULL)
		return;
	BinaryNode *pbn = root;
	
	printTree(pbn -> left);
	cout << pbn -> element << " ";
	printTree(pbn -> right);
}

template <typename Object>
typename BinarySearchTree<Object>::BinaryNode *BinarySearchTree<Object>::clone(BinaryNode *root)
{	
	if (root == NULL)
		return;
	BinaryNode *pbn = new BinaryNode(root -> element, NULL, NULL);
	pbn -> left = clone(root -> left);
	pbn -> right = clone(root -> right);
	return pbn;
}


