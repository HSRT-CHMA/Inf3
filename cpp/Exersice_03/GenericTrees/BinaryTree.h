#pragma once
#include "MainBinaryTree.h"

template<typename T>
class BinaryTree : public MainBinaryTree<T>
{

public:
	/*
	Constructor for BinaryTree which receives a value of the given generic type
	A new node with given value gets created and serves as the new root for the tree
	*/
	BinaryTree(T value) {
		MainBinaryTree::node = new Node<T>(value);
	};

	/*Deconstructor for BinaryTree*/
	~BinaryTree(void){
	};

	/*
	This method must be overwritten because this class extends the class AbstractBinaryTree.
	Method gets called after every removal or insertion of nodes ,
	but in case of an Binary tree, no special action on the tree must be performed
	*/
	void insertDeleteHook(Node<T>  * node) {
	};

};

