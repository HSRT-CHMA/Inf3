#pragma once
#include "AbstractBinaryTree.h"

template<typename T>
class BinaryTree : public AbsctractBinaryTree<T>
{

public:
	BinaryTree(T value) {
		AbsctractBinaryTree::node = new Node<T>(value);
	};

	~BinaryTree(void){
	};

	void insertDeleteHook(Node<T>  * node) {
	};

};

