#pragma once
#include "AbstractBinaryTree.h"

template<typename T>
class BinaryTree : public AbsctractBinaryTree<T>
{
private:

public:
	BinaryTree(T value) {
		AbsctractBinaryTree::node = new Node<T>(value);
	};

	~BinaryTree(void){
	};

	void insertPostHook(Node<T>  * node) {
	};

	void deletePostHook(Node<T>  * node){
	};
};

