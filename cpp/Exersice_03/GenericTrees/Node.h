#pragma once

template<typename T> 
class Node
{
private:
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
	T value;

public:
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
};



template <class T>
Node<T>::Node(void)
{

}

template <class T>
Node<T>::Node(T value)
{
	setValue(value);
}


template <class T>
Node<T>::Node(T value, Node<T> parent)
{
	setValue(value);
	setParent(parent);
}

template <class T>
Node<T>::~Node(void)
{
	//delete(parent);
	//delete(left);
	//delete(right);
}

template<class T> Node<T> Node<T>::getLeft(void)
{
	return left;
}

template<typename T> Node<T> Node<T>::getRight(void)
{
	return right;
}

template<typename T> Node<T> Node<T>::getParent(void)
{
	return parent;
}

template<typename T> T Node<T>::getValue(void)
{
	return value;
}

template<typename T>
void Node<T>::setValue(T value)
{
	this->value = value;
}

template<typename T>
void Node<T>::setLeft(Node<T> left)
{
	this->left = left;
}

template<typename T>
void Node<T>::setRight(Node<T> right)
{
	this->right = right;
}

template<typename T>
void Node<T>::setParent(Node<T> parent)
{
	this->parent = parent;
}


template<typename T>
void Node<T>::setLeftP(Node<T> * left)
{
	this->left = left;
}

template<typename T>
void Node<T>::setRightP(Node<T> * right)
{
	this->right = right;
}

template<typename T>
void Node<T>::setParentP(Node<T> * parent)
{
	this->parent = parent;
}


template<class T> Node<T>* & Node<T>::getLeftP(void)
{
	return left;
}

template<typename T> Node<T>* & Node<T>::getRightP(void)
{
	return right;
}

template<typename T> Node<T>* & Node<T>::getParentP(void)
{
	return parent;
}