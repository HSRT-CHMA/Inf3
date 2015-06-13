#pragma once

template<typename T>
class Node
{
private:
	/* All private elements of this class */
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
	// Pointer-variables of type Node<Generic>
	T value;

public:
	/* All public elements of this class */
	Node(void);
	Node(T value);
	Node(T value, Node<T>parent);
	Node<T> getLeft(void);
	Node<T> getRight(void);
	Node<T> getParent(void);
	Node<T>* & getLeftP(void);
	Node<T>* & getRightP(void);
	Node<T>* & getParentP(void);
	T getValue(void);
	void setValue(T value);
	void setLeft(Node<T> left);
	void setRight(Node<T> right);
	void setParent(Node<T> parent);
	void setLeftP(Node<T> * left);
	void setRightP(Node<T> * right);
	void setParentP(Node<T> * parent);
	~Node(void);
	// Destructor of class Node
};


/*Explicit standart constructor*/
template <class T>
Node<T>::Node(void)
{

}

/*Constructor with an input of generic type*/
template <class T>
Node<T>::Node(T value)
{
	setValue(value);
}


/*Constructor with an input of generic type and a parent-node which contains a generic type*/
template <class T>
Node<T>::Node(T value, Node<T> parent)
{
	setValue(value);
	setParent(parent);
}

/*Deconstructor of a single Node-Object*/
template <class T>
Node<T>::~Node(void)
{
	//delete(parent);
	//delete(left);
	//delete(right);
}

/* Getter for left child of node*/
template<class T> Node<T> Node<T>::getLeft(void)
{
	return left;
}
/* Getter for right child of node*/
template<typename T> Node<T> Node<T>::getRight(void)
{
	return right;
}

/* Getter for parent of node */
template<typename T> Node<T> Node<T>::getParent(void)
{
	return parent;
}

/* Getter for the value a node contains*/
template<typename T> T Node<T>::getValue(void)
{
	return value;
}

/* Setter for the value a node contains*/
template<typename T>
void Node<T>::setValue(T value)
{
	this->value = value;
}

/* Setter for the left child of a node*/
template<typename T>
void Node<T>::setLeft(Node<T> left)
{
	this->left = left;
}

/* Setter for the right child of a node*/
template<typename T>
void Node<T>::setRight(Node<T> right)
{
	this->right = right;
}

/* Setter for the parent child of a node*/
template<typename T>
void Node<T>::setParent(Node<T> parent)
{
	this->parent = parent;
}

/* Setter for a pointer on the left child of a node*/
template<typename T>
void Node<T>::setLeftP(Node<T> * left)
{
	this->left = left;
}

/* Setter for a pointer on the right child of a node*/
template<typename T>
void Node<T>::setRightP(Node<T> * right)
{
	this->right = right;
}

/* Setter for a pointer on the parent of a node*/
template<typename T>
void Node<T>::setParentP(Node<T> * parent)
{
	this->parent = parent;
}

/* Getter for a pointer on the left child of a node*/
template<class T> Node<T>* & Node<T>::getLeftP(void)
{
	return left;
}

/* Getter for a pointer on the right child of a node*/
template<typename T> Node<T>* & Node<T>::getRightP(void)
{
	return right;
}

/* Getter for a pointer on the parent of a node*/
template<typename T> Node<T>* & Node<T>::getParentP(void)
{
	return parent;
}