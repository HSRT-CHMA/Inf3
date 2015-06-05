#pragma once
#include "Node.h"
#include "BinaryTree.h"


template<typename T>
class AVLTree : public MainBinaryTree < T >
	// This class extends the MainBinaryTree and contains methods for rebalancing the AVLTree
{
private:
	int max(int a, int b);
	void rightRotate(Node<T> * &node, Node<T> * &parent);
	void leftRotate(Node<T> * &node, Node<T> * &parent);
	void leftRotateParent(Node<T> * &node, Node<T> * &parent);
	void rightRotateParent(Node<T> * &node, Node<T> * &parent);
	void insertDeleteHook(Node<T>  * node);
public:
	AVLTree(T value);
	int getBalanceFromTree();
	int getBalance(Node<T> * node);
	int getHeight(Node<T> * node);
	~AVLTree();
};


/*	
Constructor of AVLTree which receives a generic value 
A node with given value gets created and serves as root
*/
template<typename T>
AVLTree<T>::AVLTree(T value)
{
	this->node = new Node<T>(value);
}

/* 
This method returns an int-value that represents the height of the tree.
This method receives a node, in this case the root of a tree to get the heigth for 
*/
template<typename T>
int AVLTree<T>::getHeight(Node<T> * node)
{
	int result = 0;
	if (node != NULL){
		result++;
		result += max(getHeight(node->getLeftP()), getHeight(node->getRightP()));
	}
	return result;
}

/*	
	Calls the Balance Function with the complete Tree
*/
template<typename T>
int AVLTree<T>::getBalanceFromTree() {
	return getBalance(this->node);
}

/*	
	Goes Recursively through the given Node and returns the Maximum Height of the SubTree
*/
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
		result = (getHeight(node->getLeftP()) - getHeight(node->getRightP()));
	}
	return result;
}

/*	
	max()-Method on greater_than operator 
	Comapares 2 Int values and returns the greater value 
*/
template<typename T>
int AVLTree<T>::max(int a, int b)
{
	return (a > b) ? a : b;
}


/*
	This method rotates from the Current Node the Left Child to the Parent Right child.
	And sets of the Current Node on now empty Left child the node->getLeftP()getRightP().
	The actuall Node get's the node->getLeft as Parent
*/
template<typename T>
void AVLTree<T>::rightRotate(Node<T> * &node, Node<T> * &parent)
{
	Node<T> * tmp = node->getLeftP();
	parent->setRightP(tmp);
	node->setLeftP(tmp->getRightP());
	tmp->setRightP(node);
	node->setParentP(tmp);
	tmp->setParentP(parent);
	Node<T> * temp = node;
	node = tmp;
	tmp = temp;
}


/*	
	This method does the reverse action from rightRotate() 
*/
template<typename T>
void AVLTree<T>::leftRotate(Node<T> * &node, Node<T> * &parent)
{
	Node<T> * tmp = node->getRightP();
	parent->setLeftP(tmp);
	node->setRightP(tmp->getLeftP());
	tmp->setLeftP(node);
	node->setParentP(tmp);
	tmp->setParentP(parent);
	Node<T> * temp = node;
	node = tmp;
	tmp = temp;
}

/*	rightRotateParent
Does the reverse from rightRotate with a given parent 
*/
template<typename T>
void AVLTree<T>::rightRotateParent(Node<T> * &node, Node<T> * &parent)
{
	//checks if the Parent the Root Node 
	if (parent == this->node) {
		this->node = node;
	}
	else {
		if (parent == parent->getParentP()->getRightP()) {
			parent->getParentP()->setRightP(node);
		}
		else {
			parent->getParentP()->setLeftP(node);
		}
	}

	node->setParentP(parent->getParentP());
	parent->setParentP(node);
	parent->setLeftP(node->getRightP());

	if (node->getRightP() != NULL) {
		node->getRightP()->setParentP(parent);
	}
	node->setRightP(parent);
}

/*	leftRotateParent
Does the reverse from rightRotate
*/
template<typename T>
void AVLTree<T>::leftRotateParent(Node<T> * &node, Node<T> * &parent)
{
	//checks if the Parent is the Root Node 
	if (parent == this->node) {
		this->node = node;
	}
	else {
		if (parent == parent->getParentP()->getRightP()) {
			parent->getParentP()->setRightP(node);
		}
		else {
			parent->getParentP()->setLeftP(node);
		}
	}

	node->setParentP(parent->getParentP());
	parent->setParentP(node);
	parent->setRightP(node->getLeftP());

	if (node->getLeftP() != NULL) {
		node->getLeftP()->setParentP(parent);
	}
	node->setLeftP(parent);
}

/* 
	This function get called if the AVLTree gets a new Node or a Node have been deleted.
	This Function goes to the Parent and look if the Balance of the Tree is -1; 0, 1
	If not rotates' the Node's
*/
template<typename T>
void AVLTree<T>::insertDeleteHook(Node<T>  * node) {
	Node<T> * parent = node->getParentP();
	while (parent != NULL){
		if (node == parent->getLeftP()) {
			if (getBalance(parent) == 2) {
				if (getBalance(node) == -1) {
					//Rotate left
					leftRotate(node, parent);
				}
				//Rotate Right
				//is the Parent the Root Node ??
				rightRotateParent(node, parent);
			}
		}
		else {
			if (getBalance(parent) == -2) {
				if (getBalance(node) == 1) {
					//RotateRight
					rightRotate(node, parent);
				}
				//leftRotate(parent);
				//Rotate left
				leftRotateParent(node, parent);
			}
		}
		node = parent;
		parent = node->getParentP();
	}
}

/*
Destructor of AVLTree (deletes the AVLTree) because C++ doesn't have a garbage collector 
*/
template<typename T>
AVLTree<T>::~AVLTree()
{
}