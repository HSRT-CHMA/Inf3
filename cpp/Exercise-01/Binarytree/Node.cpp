#include <iostream>
#include "Node.h"

using namespace std;

class Node{
	Node* left;
	Node* right;
	Node* parent;
	int value;

	/* Constructor for Node with int and Node values */
	Node::Node(int value, Node* parent){
		this->value = value;
		setLeft(left);
		setRight(right);
		setParent(parent);
	}

	/* Constructor for Node with int value */
	Node::Node(int value){
		this->value = value;
		setLeft(left);
		setRight(right);
	}

	/* Setter for Node Class*/
	void Node::setValue(int value){
		this->value = value;
	}

	void Node::setLeft(Node* left){
		this->left = left;
	}

	void Node::setRight(Node* right){
		this->right = right;
	}

	void Node::setParent(Node* parent){
		this->parent = parent;
	}

	/* Getter for Node*/
	Node* Node::getLeft(){
		return left;
	}

	Node* Node::getRight(){
		return right;
	}

	int Node::getValue(){
		return value;
	}

	Node* Node::getParent(){
		return parent;
	}
};