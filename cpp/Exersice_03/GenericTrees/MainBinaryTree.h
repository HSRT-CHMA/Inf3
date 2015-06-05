#pragma once
#include "Node.h"
#include "AbstractTree.h"
#include <string>

template<typename T>
class MainBinaryTree : public AbstractTree< T >
	// This class contains methods suitable for AVL-Trees and 'normal' Binary Trees alike and serves therefor as a superclass 
{

protected:	
	Node<T> * node;
	// This Node-Object serves as the root of a tree

private:
	void insertFunction(T value, Node<T> * node);
	bool hasElementFunction(T value, Node<T> * node);
	void delFunction(T value, Node<T> * node);
	void preOrderFunction(Node<T> * root);
	// This Method must be overwritten by sub-classes
	virtual void insertDeleteHook(Node<T>  * node) = 0;
	// Those methods are beeing used by the public functions below and are 
	// therefore private and only accessable by this class 

public:
	void insert(T value);
	bool hasElement(T value);
	void del(T value);
	void printTree(void);
};

/* This public calls the private submethod to insert a given value in the existing tree*/
template <class T>
void MainBinaryTree<T>::insert(T value)
{
	insertFunction(value, node);
}

/*
This Method finds the logical place for a new value and inserts a new node with given value in the tree
A value smaller than the root of a subtree is added left , A value greater than or equal gets added right
After every insertion, the pointer for parent of the new node are set to the parent
and the pointer for the now parent is set upon its new left or right child.
Also, the method vor the rebalancing of the tree is called, which in case of a binary tree is empty
and in case of an AVL-tree organises a rebalanciation of the AVL-tree
*/
template <class T>
void MainBinaryTree<T>::insertFunction(T value, Node<T> * node)
{

	/*
	if !(node == NULL)
	{
	if (value < node->getValue())
	{
	if (node->getLeftP() == NULL)
	{
	Node<T> * tmpNode = new Node<T>(value);
	tmpNode->setParentP(node);
	node->setLeftP(tmpNode);
	insertDeleteHook(node->getLeftP());
	}
	else
	{
	insertFunction(value, node->getLeftP());
	}
	}
	else if (value > node->getValue())
	{
	Node<T> * tmpNode = new Node<T>(value);
	tmpNode->setParentP(node);
	node->setRightP(tmpNode);
	insertDeleteHook(node->getRightP());
	}
	else
	{
	insertFunction(value, node->getRightP());
	}
	} */

	if (node == NULL) {
	// This is stupid code , please change
	}
	else if (value < node->getValue())
	{
	if ( node->getLeftP() == NULL ) {
	Node<T> * tmpNode = new Node<T>(value);
	tmpNode->setParentP(node);
	node->setLeftP(tmpNode);
	insertDeleteHook(node->getLeftP());
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
	insertDeleteHook(node->getRightP());
	}
	else {
	insertFunction(value, node->getRightP() );
	}
	}

} // End of Method

/*This method calls the hasElementFunction*/
template <class T>
bool MainBinaryTree<T>::hasElement(T value)
{
	return hasElementFunction(value, node);
}

/*
HasElementFunction searches for the Value recursively in the Tree and returns a bool to showcase the outcome
*/
template <class T>
bool MainBinaryTree<T>::hasElementFunction(T value, Node<T>  * node)
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
		// Method does not change the structur of the given tree
		// so no rebalancing is needed
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
		// Method does not change the structur of the given tree
		// so no rebalancing is needed
	}
	else{
		return false;
	}
}

/*This method calls the delete Method*/
template <class T>
void MainBinaryTree<T>::del(T value)
{
	if (hasElement(value)) {
		delFunction(value, this->node);
	}
	else {
		std::cout<< "\nThe value does not exist in this Tree!" << std::endl;
	}
}


/*
This Function searches the node with given value and removes the node containing the value recursively
The method works on the possible cases in which the node in question can be
- No children  -- Node is a leaf
- Only left or only right child
- Left and right child
*/
template <class T>
void MainBinaryTree<T>::delFunction(T value, Node<T>  * node)
{
	Node<T> * smallNode;
	//Node-Object to be used as tmp-Variable
	Node<T> * tmpNode;
	//Node-Object to be used as tmp-Variable

	//IF the Value to Delete is the first Leaf on the left side
	//and this leaf has no other leafs
	//The method now deletes it
	if (node->getLeftP() != NULL) {
		if (node->getLeftP()->getValue() == value && node->getLeftP()->getLeftP() == NULL && node->getLeftP()->getRightP() == NULL)
		{
			Node<T> * parent = node->getLeftP()->getParentP();
			node->getLeftP()->setParentP(NULL);
			node->getLeftP()->setLeftP(NULL);
			node->getLeftP()->setValue(NULL);
			node->getLeftP()->setRightP(NULL);
			node->setLeftP(NULL);
			delete(node->getLeftP());
			insertDeleteHook(parent);
			return;
		}
	}

	//IF the Value to Delete is the first Leave on the right side
	//and this leave has no other leaves
	//delete it
	if (node->getRightP() != NULL) {
		if (node->getRightP()->getValue() == value && node->getRightP()->getLeftP() == NULL && node->getRightP()->getRightP() == NULL)
		{
			Node<T> * parent = node->getRightP()->getParentP();
			node->getRightP()->setParentP(NULL);
			node->getRightP()->setLeftP(NULL);
			node->getRightP()->setValue(NULL);
			node->getRightP()->setRightP(NULL);
			node->setRightP(NULL);
			delete(node->getRightP());
			insertDeleteHook(parent);
			return;
		}
	}
	//IF the root Value is I and there is no other leave delete / or set the main tree = void
	if (value == node->getValue() && node->getRightP() == NULL && node->getLeftP() == NULL)
	{
		this->node->setValue(NULL);
		//delete(this->node);
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
			//the Node to be deleted has only a right Leave
			if (node->getLeftP() == NULL) {
				Node<T> * parent = node->getParentP();
				node->setValue(node->getRightP()->getValue());
				node->setLeftP(node->getRightP()->getLeftP());
				node->setRightP(node->getRightP()->getRightP());
				insertDeleteHook(parent);
			}
			else //Node to be deleted has no right Leave
			{
				if (node->getRightP() == NULL)
				{
					if (node == this->node) {
						this->node = node->getLeftP();
						this->node->setParentP(NULL);
					}
					else {
						Node<T> * parent = node->getParentP();
						node->setValue(node->getLeftP()->getValue());
						node->setRightP(node->getLeftP()->getRightP());
						node->setLeftP(node->getLeftP()->getLeftP());
						insertDeleteHook(parent);
					}

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
						insertDeleteHook(node->getParentP());
					}
					else
					{
						//smallest child found
						node->setValue(smallNode->getValue());
						//node->setValue(smallNode->getLeftP()->getValue());
						//smallNode->setLeftP(NULL);
						if (this->node == node) {
							insertDeleteHook(this->node);
						}
						else {														
							insertDeleteHook(node->getParentP());
						}
					}
				}
			}
	}
}

/*	
This Method is only for printing the Tree recursively on the CMD Line.
This method allows to return the nodes of a tree in pre-Order.
It works recursiv and only performs while the next node is not null
*/
template<typename T>
void MainBinaryTree<T>::preOrderFunction(Node<T> * root)
{
	if (root != NULL)
	{
		std::cout<< root->getValue() << " ";
		if(node->getLeftP()) {
			//printf(" Left: ");
		}
		preOrderFunction(root->getLeftP());

		if(node->getRightP()) {		
			//printf(" Right: ");
		}
		preOrderFunction(root->getRightP());

	}
}

/*This methods is for testing and prints the header and Tree Recursively
*/
template<typename T>
void MainBinaryTree<T>::printTree()
{
	if (node != NULL)
	{
		std::cout << "printTree Function called: " << std::endl;
		std::cout << "Main Value: " << node->getValue() << std::endl << std::endl;
		if(node->getLeftP()) {
			std::cout << "\nLeft Subtree: ";
		}
		preOrderFunction(node->getLeftP());
		if (node->getLeftP() == NULL) {
			std::cout << std::endl;
		}
		if(node->getRightP()) {		
			std::cout << "\nRight Subtree: ";
		}
		preOrderFunction(node->getRightP());
		if (node->getRightP() == NULL) {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	// Causes Line Break after printing done by method
}