#pragma once
#include "Node.h"
#include <string>

template<typename T>
class AbsctractBinaryTree
{
	
protected:	
	Node<T> * node;

private:
	void insertFunction(T value, Node<T> * node);
	bool hasElementFunction(T value, Node<T> * node);
	void delFunction(T value, Node<T> * node);
public:
	//BinaryTree(T value);
	//~BinaryTree();
	void insert(T value);
	bool hasElement(T value);
	void del(T value);
	void preOrderFunction(Node<T> * root);
	void preOrderFunction(void);
	virtual void insertPostHook(Node<T>  * node) = 0;
	virtual void deletePostHook(Node<T>  * node) = 0;
};


/*
template <class T>
BinaryTree<T>::BinaryTree(T value)
{
	this->node = new Node<T>(value);
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
	//delete(node);
}
*/


template <class T>
void AbsctractBinaryTree<T>::insert(T value)
{
	insertFunction(value, node);
}

template <class T>
void AbsctractBinaryTree<T>::insertFunction(T value, Node<T> * node)
{
	if (node == NULL) {

	}
	else if (value < node->getValue())
	{
		if ( node->getLeftP() == NULL ) {
			Node<T> * tmpNode = new Node<T>(value);
			tmpNode->setParentP(node);
			node->setLeftP(tmpNode);
			insertPostHook(tmpNode);
		}
		else {
			insertFunction(value, node->getLeftP() );
		}
	}
	else if (value > node->getValue()) {
		if (node->getRightP() == NULL) {
			Node<T> * tmpNode = new Node<T>(value);
			tmpNode->setParentP(node);
			node->setRightP(tmpNode);
			insertPostHook(tmpNode);
		}
		else {
			insertFunction(value, node->getRightP() );
		}
	}
}


template <class T>
bool AbsctractBinaryTree<T>::hasElement(T value)
{
	return hasElementFunction(value, node);
}

template <class T>
bool AbsctractBinaryTree<T>::hasElementFunction(T value, Node<T>  * node)
{
	if (node == NULL) {
		return false;
	}
	else if (value == node->getValue()) {
		return true;
	}
	else if (value < node->getValue()) {	
		if (node->getLeftP() == NULL) {
			return false;
		}
		Node<T> * tmpnode = new Node<T>(node->getLeftP()->getValue());
		tmpnode->setLeftP(node->getLeftP()->getLeftP());
		tmpnode->setRightP(node->getLeftP()->getRightP());
		tmpnode->setParentP(node->getLeftP()->getParentP());
		return hasElementFunction(value, tmpnode);
	}
	else if (value > node->getValue()) {
		if (node->getRightP() == NULL) {
			return false;
		}
		Node<T> * tmpnode = new Node<T>(node->getRightP()->getValue());
		tmpnode->setLeftP(node->getRightP()->getLeftP());
		tmpnode->setRightP(node->getRightP()->getRightP());
		tmpnode->setParentP(node->getRightP()->getParentP());
		return hasElementFunction(value, tmpnode);
	}
	else{
		return false;
	}
}

template <class T>
void AbsctractBinaryTree<T>::del(T value)
{
	delFunction(value, this->node);
}

template <class T>
void AbsctractBinaryTree<T>::delFunction(T value, Node<T>  * node)
{
	Node<T> * smallNode;
	Node<T> * tmpNode;

	//IF the Value to Delete is the first Leave on the left side
	//and this leave has no other leaves
	//delete it
	if (node->getLeftP() != NULL) {
		if (node->getLeftP()->getValue() == value && node->getLeftP()->getLeftP() == NULL && node->getLeftP()->getRightP() == NULL)
		{
			node->getLeftP()->setParentP(NULL);
			node->getLeftP()->setLeftP(NULL);
			node->getLeftP()->setValue(NULL);
			node->getLeftP()->setRightP(NULL);
			deletePostHook(node->getLeftP());
			node->setLeftP(NULL);
			delete(node->getLeftP());
			return;
		}
	}
	
	//IF the Value to Delete is the first Leave on the right side
	//and this leave has no other leaves
	//delete it
	if (node->getRightP() != NULL) {
		if (node->getRightP()->getValue() == value && node->getRightP()->getLeftP() == NULL && node->getRightP()->getRightP() == NULL)
		{
			node->getRightP()->setParentP(NULL);
			node->getRightP()->setLeftP(NULL);
			node->getRightP()->setValue(NULL);
			node->getRightP()->setRightP(NULL);
			deletePostHook(node->getRightP());
			node->setRightP(NULL);
			delete(node->getRightP());
			return;
		}
	}
	//IF the root Value is I and there is no other leave delete / or set the main tree = void
	
	if (value == node->getValue() && node->getRightP() == NULL && node->getLeftP() == NULL)
	{
		node->setValue(0);
		delete(node);
	}
	//IF i < root.getValue is the value(i) on the left side of the tree then go in this node
	else if (value < node->getValue()) {
		delFunction(value, node->getLeftP());
	}
	else {
		//Is the Value bigger than the root node
		if (value > node->getValue()) {
			delFunction(value, node->getRightP());
		}
		else //The node to be deleted have been found
			//the Node to be deleted has only a left Leave
			if (node->getLeftP() == NULL) {
				node->setValue(node->getRightP()->getValue());
				node->setParentP(node->getRightP()->getParentP());
				node->setLeftP(node->getRightP()->getLeftP());
				node->setRightP(node->getRightP()->getRightP());
				node->getRightP()->setValue(0);
			}
			else //Node to be deletet has no right Leave
			{
				if (node->getRightP() == NULL)
				{
					node->setValue(node->getLeftP()->getValue());
					node->setRightP(node->getLeftP()->getRightP());
					node->setLeftP(node->getLeftP()->getLeftP());
				}
				else
				{
					//there are two children
					//Search the smallest child from the node to be deleted
					if (node->getRightP()->getValue() < node->getLeftP()->getValue())
					{
						smallNode = node->getRightP();
					}
					else if (node->getRightP()->getValue() > node->getLeftP()->getValue()){
						smallNode = node->getLeftP();
					}
					else{
						smallNode = node;
					}

					if (smallNode == node)
					{
						//No node have been found
						//Change the Node to delete with the smallest child
						//Node has been deleted
						node->setValue(node->getRightP()->getValue());

						//change the tree
						smallNode = node->getRightP();
						node->setRightP(node->getRightP()->getRightP());
						smallNode->setRightP(NULL);
						//delete the storage place
						delete(smallNode);
					}
					else
					{
						//smallest child found
						node->setValue(smallNode->getLeftP()->getValue());
						smallNode->setLeftP(NULL);

					}
				}
			}
	}
}

template<typename T>
void AbsctractBinaryTree<T>::preOrderFunction(Node<T> * root)
{
	if (root != NULL)
	{
		std::cout<< "Value " << root->getValue() << "";
		if (root->getValue() == NULL) {
			std::cout << "NULL \n";
		}
		printf("Left: ");
		preOrderFunction(root->getLeftP());
		if (root->getLeftP() == NULL) {
			std::cout << "NULL \n";
		}
		printf("Right: ");
		preOrderFunction(root->getRightP());
		if (root->getRightP() == NULL) {
			std::cout << "NULL \n";
		}
	}
}

template<typename T>
void AbsctractBinaryTree<T>::preOrderFunction()
{
	if (node != NULL)
	{
		std::cout<< "" << node->getValue() << "";
		printf("Left: ");
		preOrderFunction(node->getLeftP());
		if (node->getLeftP() == NULL) {
			std::cout << "NULL \n";
		}
		printf("Right: ");
		preOrderFunction(node->getRightP());
		if (node->getRightP() == NULL) {
			std::cout << "NULL \n";
		}
	}
}
