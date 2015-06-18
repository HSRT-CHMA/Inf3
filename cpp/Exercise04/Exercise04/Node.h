#ifndef NODE_HPP_
#define NODE_HPP_
#include <cstddef>
//class to create generic nodes
template<typename T>
class Node {

private:

	//The data of the node
	T data;
	//The left,right and parent node
	Node<T> * left, *right, *parent = NULL;

public:

	/*
	* Constructor Node
	* parms: data: The data to be stored in the node
	*		 left: The left child of the node
	*		 right: The right child of the node
	*		 parent: The parent of the node
	*/
	Node(T data, Node<T> * left, Node<T> * right, Node<T> * parent) {
		this->data = data;
		this->left = left;
		this->right = right;
		this->parent = parent;
	}

	//Returns the data of node
	T getData() {
		return this->data;
	}

	/*
	* Sets data of node
	* parms: data: The data of node
	*/
	void setData(T data) {
		this->data = data;
	}

	// Returns left child of node
	Node<T> * getLeft() {
		return this->left;
	}

	/*
	* Sets the left child node
	* parms: n: The node that should be the left child node
	*/
	void setLeft(Node<T> * n) {
		this->left = n;
	}

	// Returns right child of node
	Node<T> * getRight() {
		return this->right;
	}

	/*
	* Sets the right child of the node
	* parms: n: The node that should be the right child node
	*/
	void setRight(Node<T> * n) {
		this->right = n;
	}

	// Returns the parent child node
	Node<T> * getParent() {
		return this->parent;
	}

	/*
	* Sets the parent of the node.
	* parms: n: The node that should be the parent node
	*/
	void setParent(Node<T> * n) {
		this->parent = n;
	}
};
#endif