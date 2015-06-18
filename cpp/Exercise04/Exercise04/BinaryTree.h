#ifndef BINARY_TREE_HPP_
#define BINARY_TREE_HPP_
#include "AbstractTree.h"
//Class to create generic binarytrees
template<typename T>
class BinaryTree : public AbstractTree <T> {

protected:

	/*
	* Method that is called after insert or delete a node
	* This Method is not implemented for binarytree
	*/
	void insertAndDelPostHook(Node<T> * n) {

	}

public:

	//The standard constructor for binarytree
	BinaryTree() {
		this->root = NULL;
	}

	/*
	* Constructor with root parameter for binarytree
	* parms: data: The data for the root node of the binarytree
	*/
	BinaryTree(T data) {
		this->root = new Node<T>(data, NULL, NULL, NULL);
	}
};
#endif