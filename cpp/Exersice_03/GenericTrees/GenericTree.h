#pragma once
#include "Node.h"

template <typename T>
class GenericTree
{
public:

	~GenericTree();
	void insert(T value);
	bool hasElement(T value);
	void del(T value);
	void preOrderFunction(Node<T> * root);
	virtual void insertPostHook(Node<T>  * node) = 0;

private:
	Node<T> * node;

	void insertFunction(T value, Node<T> * &node);
	bool hasElementFunction(T value, Node<T> * &node);
	void delFunction(T value, Node<T> * &node);
};

