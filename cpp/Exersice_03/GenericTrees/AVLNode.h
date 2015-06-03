#pragma once
#include "Node.h"

template<typename T>
class AVLNode
{
private:
	AVLNode<T>* left;
	AVLNode<T>* right;
	AVLNode<T>* parent;
	T value;
	int height;

public:
	AVLNode();
	AVLNode(T value);
	AVLNode(int height, T value);
	AVLNode(int height, T value, AVLNode<T>parent);

	int getHeight();
	void setHeight(int height);
	~AVLNode();


	AVLNode<T> getLeft(void);
	AVLNode<T> getRight(void);
	AVLNode<T> getParent(void);
	AVLNode<T>* & getLeftP(void);
	AVLNode<T>* & getRightP(void);
	AVLNode<T>* & getParentP(void);
	T getValue(void);
	void setValue(T value);
	void setLeft(AVLNode<T> left);
	void setRight(AVLNode<T> right);
	void setParent(AVLNode<T> parent);
	void setLeftP(AVLNode<T> * left);
	void setRightP(AVLNode<T> * right);
	void setParentP(AVLNode<T> * parent);

};
template <typename T>
AVLNode<T>::AVLNode()
{

}


template <typename T>
AVLNode<T>::AVLNode(T value)
{
	setValue(value);
}

template <typename T>
AVLNode<T>::AVLNode(int height, T value)
{
	this->height = height;
	setValue(value);
	//node = new Node(value);
}

template <typename T>
AVLNode<T>::AVLNode(int height, T value, AVLNode<T> parent)
{
	setValue(value);
	setParent(parent);
}

template <typename T>
int AVLNode<T>::getHeight()
{
	return height;
}

template <typename T>
void AVLNode<T>::setHeight(int height)
{
	this->height = height;
}

template <typename T>
AVLNode<T>::~AVLNode()
{

}



template<class T> AVLNode<T> AVLNode<T>::getLeft(void)
{
	return left;
}

template<typename T> AVLNode<T> AVLNode<T>::getRight(void)
{
	return right;
}

template<typename T> AVLNode<T> AVLNode<T>::getParent(void)
{
	return parent;
}

template<typename T> T AVLNode<T>::getValue(void)
{
	return value;
}

template<typename T>
void AVLNode<T>::setValue(T value)
{
	this->value = value;
}

template<typename T>
void AVLNode<T>::setLeft(AVLNode<T> left)
{
	this->left = left;
}

template<typename T>
void AVLNode<T>::setRight(AVLNode<T> right)
{
	this->right = right;
}

template<typename T>
void AVLNode<T>::setParent(AVLNode<T> parent)
{
	this->parent = parent;
}


template<typename T>
void AVLNode<T>::setLeftP(AVLNode<T> * left)
{
	this->left = left;
}

template<typename T>
void AVLNode<T>::setRightP(AVLNode<T> * right)
{
	this->right = right;
}

template<typename T>
void AVLNode<T>::setParentP(AVLNode<T> * parent)
{
	this->parent = parent;
}


template<class T> 
AVLNode<T>* & AVLNode<T>::getLeftP(void)
{
	return left;
}

template<typename T> 
AVLNode<T>* & AVLNode<T>::getRightP(void)
{
	return right;
}

template<typename T> 
AVLNode<T>* & AVLNode<T>::getParentP(void)
{
	return parent;
}