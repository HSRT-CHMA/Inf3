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
	void preOrderFunction(Node<T> * root);
	virtual void insertDeleteHook(Node<T>  * node) = 0;

public:
	void insert(T value);
	bool hasElement(T value);
	void del(T value);
	void printTree(void);
};

/* Calls the InsertFunction*/
template <class T>
void AbsctractBinaryTree<T>::insert(T value)
{
	insertFunction(value, node);
}

/*Inserts the Value recursively in the tree.
*/
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
}

/*Calls the hasElementFunction*/
template <class T>
bool AbsctractBinaryTree<T>::hasElement(T value)
{
	return hasElementFunction(value, node);
}

/*	HasElementFunction
*	searches for the Value recursively in the Tree
*/
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

/*Calls the delete Method*/
template <class T>
void AbsctractBinaryTree<T>::del(T value)
{
	if (hasElement(value)) {
		delFunction(value, this->node);
	}
	else {
		std::cout<< "\nThe value "<<value<< " is already not in this Tree!" << std::endl;
	}
}


/*	DelFunction
*	This Function searche and delete the value recursively
*/
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
	This Function is only for printing 
	the Tree recursively on the CMD Line.
*/
template<typename T>
void AbsctractBinaryTree<T>::preOrderFunction(Node<T> * root)
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

/*This function prints the header and Tree Recursivle
*/
template<typename T>
void AbsctractBinaryTree<T>::printTree()
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
}