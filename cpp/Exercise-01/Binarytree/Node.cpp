#include <iostream>

using namespace std;

class Node{
private:
	Node* left;
	Node* right;
	Node* parent;
	int value;

	/*
	
	Constructor for Node with int and Node values
	
	*/
public:
	/* Constructor for Node with int and Node values */
	Node(int value, Node* parent){
		this->value = value;
		setLeft(left);
		setRight(right);
		setParent(parent);
	}

	/* Constructor for Node with int value */
	Node(int value){
		this->value = value;
		setLeft(left);
		setRight(right);
	}

	/* Setter for Node Class*/
	void setValue(int value){
		this->value = value;
	}

	void setLeft(Node* left){
		this->left = left;
	}

	void setRight(Node* right){
		this->right = right;
	}

	void setParent(Node* parent){
		this->parent = parent;
	}

	/* Getter for Node*/
	Node* getLeft(){
		return left;
	}

	Node* getRight(){
		return right;
	}

	int getValue(){
		return value;
	}

	Node* getParent(){
		return parent;
	}
};