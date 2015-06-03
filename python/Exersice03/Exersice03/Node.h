#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {

private:
	T data;
	// The given value of this Node, is of type T, 
	//former : int data;

	Node<T> * right = NULL;
	Node<T> * left = NULL;
	Node<T> * parent = NULL;
	/*
	Node<T> * right;
	Node<T> * left;
	Node<T> * parent;
	*/

	// Pointer-variables of typ Node<Generic>

public:

	//Constructor for Node with data-variable as input 
	Node(T data){
		this->parent = nullptr;
		this->right = nullptr;
		this->left = nullptr;
		this->setData(data);
	}

	//template <typename T>
	T getData()
	{
		//assert(data <= 0 || data >= 0);
		return this->data;
	}

	void setData(T data)
	{
		this->data = data;
	}

	Node<T> * getParent()
	{
		return this->parent;
	}

	void setParent(Node<T> * new_parent)
	{
		this->parent = new_parent;
	}

	Node<T> * getRight()
	{
		return this->right;
	}

	void setRight(Node<T> * new_right)
	{
		this->right = new_right;
	}

	Node<T> * getLeft() {
		return this->left;
	}

	void setLeft(Node<T> * new_left) {
		this->left = new_left;
	}

	/*
	//empty node
	Node();
	//node with data
	Node(int data);
	void setRight(Node* right);
	void setLeft(Node* left);
	void setParent(Node* parent);
	void setData(int data);
	Node* getRight();
	Node* getLeft();
	Node* getParent();
	int getData();
	bool search(int data);
	*/
}; // end Node class



#endif