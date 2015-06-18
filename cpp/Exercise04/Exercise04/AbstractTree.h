#ifndef ABSTRACT_TREE_HPP_
#define ABSTRACT_TREE_HPP_
#include "stdafx.h"
#include "iostream"
#include <string>
#include "Node.h"
#include <cstddef>
#include "ITree.h"
#include <vector>
#include <functional>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
//Abstract generic class for Trees
template < typename T >
class AbstractTree : public ITree <T> {

protected:

	//Used for method has()
	bool found;

	//The root node of the tree
	Node<T> * root = NULL;
	
	// Vector for filter()-ing
	std::vector <T> v = NULL;

	/*
	* The recursion to insert data in the tree.
	* called by insert()
	* parms: n: The node to start from.
	*		 data: The data to be inserted.
	*/
	void insertRec(Node<T> * n, T data) {
		if (data < n->getData()) {
			if (n->getLeft() == NULL) {
				n->setLeft(new Node<T>(data, NULL, NULL, n));
				insertAndDelPostHook(n->getLeft());
			}
			else {
				insertRec(n->getLeft(), data);
			}
		}
		if (data >= n->getData()) {
			if (n->getRight() == NULL) {
				n->setRight(new Node<T>(data, NULL, NULL, n));
				insertAndDelPostHook(n->getRight());
			}
			else {
				insertRec(n->getRight(), data);
			}
		}
	}

	/*
	* Virtual method called after insert() or delete() a node
	*/
	virtual void insertAndDelPostHook(Node<T> * n) = 0;

	/*
	* The recursion to search for data in the tree
	* called by has()
	* parms: n: The node to start from
	*		 data: The data to search for
	*/
	bool hasRec(Node<T> * n, T data) {
		this->found = false;
		if (n != NULL && n->getData() == data) {
			this->found = true;
		}
		else {
			if (n != NULL && !(this->found)) {
				if (data < n->getData()) {
					hasRec(n->getLeft(), data);
				}
				else {
					hasRec(n->getRight(), data);
				}
			}
		}
		return found;
	}

	/*
	The recursion to delete data in the tree
	called by delete()
	parms: n: The node to start from
		   data: The data to be deleted
	*/
	void delRec(Node<T> * n, T data) {
		if (n != NULL && n == this->root && n->getData() == data) {
			if (n->getLeft() == NULL && n->getRight() == NULL) {
				this->root = NULL;
				delete n;
			}
			else if (n->getLeft() != NULL && n->getRight() == NULL) {
				n->getLeft()->setParent(NULL);
				this->root = n->getLeft();
				delete n;
			}
			else if (n->getLeft() == NULL && n->getRight() != NULL) {
				n->getRight()->setParent(NULL);
				this->root = n->getRight();
				delete n;
			}
			else if (n->getLeft() != NULL && n->getRight() != NULL) {
				delNodeWTwoChild(n);
			}
		}
		else if (n != NULL && n != this->root && n->getData() == data) {
			if (n->getLeft() == NULL && n->getRight() == NULL) {
				Node<T> * p = n->getParent();
				if (n == n->getParent()->getLeft()) {
					n->getParent()->setLeft(NULL);
				}
				else {
					n->getParent()->setRight(NULL);
				}
				delete n;
				insertAndDelPostHook(p);
			}
			else if (n->getLeft() != NULL && n->getRight() == NULL) {
				Node<T> * p = n->getParent();
				if (n == n->getParent()->getLeft()) {
					n->getParent()->setLeft(n->getLeft());
				}
				else {
					n->getParent()->setRight(n->getLeft());
				}
				n->getLeft()->setParent(n->getParent());
				delete n;
				insertAndDelPostHook(p);
			}
			else if (n->getLeft() == NULL && n->getRight() != NULL) {
				Node<T> * p = n->getParent();
				if (n == n->getParent()->getLeft()) {
					n->getParent()->setLeft(n->getRight());
				}
				else {
					n->getParent()->setRight(n->getRight());
				}
				n->getRight()->setParent(n->getParent());
				delete n;
				insertAndDelPostHook(p);
			}
			else if (n->getLeft() != NULL && n->getRight() != NULL) {
				delNodeWTwoChild(n);
			}
		}
		else if (n != NULL && n->getData() != data) {
			if (data < n->getData()) {
				delRec(n->getLeft(), data);
			}
			else {
				delRec(n->getRight(), data);
			}
		}
	}

	/*
	* Method to delete nodes with two children
	* called by delRec()
	* parms: n: The node with two children to be deleted
	*/
	void delNodeWTwoChild(Node<T> * n) {
		Node<T> * smallest = getSmallest(n->getRight());
		n->setData(smallest->getData());
		delRec(smallest, smallest->getData());
	}

	/*
	* Gets the smallest node of subtree
	* parms: n: The node of the subtree
	*/
	Node<T> * getSmallest(Node<T> * n) {
		while (n->getLeft() != NULL) {
			n = n->getLeft();
		}
		return n;
	}

	/*
	* Prints elements of tree in-order to the console
	* called by inOrderOut()
	* parms: n : Node to start from
	*/
	void inOrderRec(Node<T> * n) {
		if (n != NULL) {
			inOrderRec(n->getLeft());
			std::cout << n->getData() << std::ends;
			inOrderRec(n->getRight());
		}
	}

	/*
	* Prints elements of tree pre-order to the console
	* called by preOrderOut()
	* parms: n : Node to start from
	*/
	void preOrderRec(Node<T> * n) {
		if (n != NULL) {
			std::cout << n->getData() << std::ends;
			inOrderRec(n->getLeft());
			inOrderRec(n->getRight());
		}
	}

	/*
	* Method recursively filter data of tree by lambda expression
	* called by filter()
	* parms: node: The node to start from
	*        f: The lambda expression to filter for
	*		 v: put the filtered Nodes in vector v.
	*/
	void filterRec(Node<T>* node, std::function <bool(T)> f) {
		if (node != NULL) {

			if (f(node->getData())){
				v.push_back(node->getData());
			}
			filterRec(node->getRight(), f);
			filterRec(node->getLeft(), f);
		}
	}

public:

	/*
	* Method to insert data in the tree
	* parms: data: The data to be inserted
	*/
	void insert(T data) {
		if (this->root == NULL) {
			this->root = new Node<T>(data, NULL, NULL, NULL);
		}
		else {
			insertRec(this->root, data);
		}
		std::cout << data << " inserted." << std::endl;
	}

	/*
	* Method to search for data in the tree
	* parms: data: The data to search for
	*/
	bool has(T data) {
		return hasRec(this->root, data);
	}

	/*
	* Method to delete data from a tree
	* parms: data: The data to delete
	*/
	void del(T data) {
		while (this->root != NULL && has(data)) {
			std::cout << data << " deleted." << std::endl;
			delRec(this->root, data);
		}
	}

	/*
	* Method for in-order-output of the tree
	*/
	void inOrderOut() {
		if (this->root != NULL) {
			std::cout << "In-Order-Output:" << std::ends;
			inOrderRec(this->root);
			std::cout << std::endl;
		}
		else {
			std::cout << "Tree is empty." << std::endl;
		}
	}

	/*
	* Method for pre-order-output of the tree
	*/
	void preOrderOut() {
		if (this->root != NULL) {
			std::cout << "Pre-Order-Output:" << std::ends;
			preOrderRec(this->root);
			std::cout << std::endl;
		}
		else {
			std::cout << "Tree is empty." << std::endl;
		}
	}


	/*
	* Filters data in the tree by Lamda Expression
	* calls filterRec()
	* parms: l: The lambda expression for filtering
	*/
	void filter(std::function <bool(T)> f){
		v.clear();
		filterRec(getRoot(), f);
	}

	/* 
	* Prints the elements type string filtered for console-output
	*/
	void printStringFilter(){
		for (std::string s : getV())
		{
			std::cout << s << " ";
		}
		std::cout << " " << std::endl;
	}

	/*
	* Prints the elements type float filtered for console-output
	*/
	void printFloatFilter(){
		for (float f : v)
		{
			float y = roundf(f * 100.0f) / 100.0f;
			std::cout << y << " ";
		}
		std::cout << " " << std::endl;
	}

	/*
	* Method to get the vector with filtered Node items from tree
	*/
	std::vector<T> getV(){
		return v;
	}

	/*
	* Method to get the root Node from tree
	*/
	Node<T>* getRoot(){
		assert(root != NULL || root == NULL);
		return root;
	}
};
#endif