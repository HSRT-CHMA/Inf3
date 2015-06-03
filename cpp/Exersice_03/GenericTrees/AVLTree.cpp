#include "stdafx.h"
#include "AVLTree.h"


template<typename T>
AVLTree<T>::AVLTree()
{
}

template<typename T>
AVLTree<T>::AVLTree(int height, int value)
{
	node = AVLNode(height, value);
}
template<typename T>
AVLTree<T>::~AVLTree()
{
}
