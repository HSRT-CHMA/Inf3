#pragma once
#include "Node.h"
#include "BinaryTree.h"


template<typename T>
class AVLTree : public AbsctractBinaryTree<T>
{
private:

public:
	AVLTree();
	AVLTree(T value);
	int getBalance(Node<T> * node);
	int getHeight(Node<T> * node);
	int max(int a, int b); //Noch löschen!!!
	void rightRotate(Node<T> * y);
	void leftRotate(Node<T> * x);
	void insertPostHook(Node<T>  * node);
	void deletePostHook(Node<T>  * node);
	~AVLTree();
};

template<typename T>
AVLTree<T>::AVLTree()
{
}

template<typename T>
AVLTree<T>::AVLTree(T value) //:BinaryTree(value)
{
	this->node = new Node<T>(value);
}


template<typename T>
int AVLTree<T>::getHeight(Node<T> * node)
{
	int result = 0;
	if (node == NULL)
	{
		result = 0;
	}
	else {
		result = getHeight(node->getLeftP());
		int tmp = getHeight(node->getRightP());
		if (result < tmp) {
			result = tmp;
		}
	}
	return result;
}


// Get Balance factor of node 
template<typename T>
int AVLTree<T>::getBalance(Node<T> * node)
{
	int result = 0;
	if (node == NULL)
	{
		result = 0;
	}
	else
	{
		result = ( getHeight(node->getLeftP() ) - getHeight(node->getRightP() ) );
	}
	return result;
}

// A utility function to get maximum of two integers
template<typename T>
int AVLTree<T>::max(int a, int b)
{
	return (a > b) ? a : b;
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
template<typename T>
void AVLTree<T>::rightRotate(Node<T> *y)
{
	Node<T> * newRoot = y->getParentP();
	Node<T> * tmp = newRoot->getRightP();
	// Perform rotation
	newRoot->setRightP(y);
	y->setLeftP(tmp);
	// Update heights
	//y->setHeight(max(getHeight(y->getLeftP()), getHeight(y->getRightP())) + 1);
	//newRoot->setHeight(max ( getHeight( newRoot->getLeftP()), getHeight(newRoot->getRightP()) ) + 1);
	// Return new root
}

template<typename T>
void AVLTree<T>::leftRotate(Node<T> *x)
{
	Node<T> *y = x->getRightP();
	Node<T> * tmp = y->getParentP();
	// Perform rotation
	y->setRightP(x);
	x->setLeftP(tmp);
	//  Update heights
	//x->setHeight(max(getHeight(x->getLeftP()), getHeight(x->getRightP())) + 1);
	//y->setHeight(max(getHeight(y->getLeftP()), getHeight(y->getRightP())) + 1);
	// Return new root
}


template<typename T>
void AVLTree<T>::insertPostHook(Node<T>  * node) {
	node = node->getParentP();
	if (node) {
		Node<T> * p = node->getParentP();
		while (p != NULL){
			if (node == p->getLeftP()) {
				if (getBalance(p) == 2) {					
					std::cout << "Balance: " << getBalance(node);
					if (getBalance(node) == -1) {
						leftRotate(node);
					}
					rightRotate(p);
				}
			}
			else {
				if (getBalance(p) == -2) {					
					std::cout << "Balance: " << getBalance(node);
					if (getBalance(node) == 1) {
						rightRotate(node);
					}
					leftRotate(p);
				}
			}
			node = p;
			p = node->getParentP();
		}
	}	
}

template<typename T>
void AVLTree<T>::deletePostHook(Node<T>  * node) {
	node = node->getParentP();
	if (node) {
		Node<T> * p = node->getParentP();
		while (p != NULL){
			if (node == p->getRightP()) {
				if ( getBalance(p) == 1 ) {
					if (getBalance(node) == -1) {
						leftRotate(node);
					}
					rightRotate(p);
					if (getBalance(node) == 0) { // (in the picture the small blue (0) at node 4)
						break;	// Height does not change: Leave the loop
					}
				}
				if ( getBalance(p) == 0 ) {
					break;
				}
			}
			else {
				if (getBalance(p) == -1) {
					if (getBalance(node) == 1) {
						rightRotate(node);
					}
					leftRotate(p);
					if (getBalance(node) == 0) {
						break;
					}
				}
			}
			node = p;
			p = node->getParentP();
		}
	}
}

template<typename T>
AVLTree<T>::~AVLTree()
{
}