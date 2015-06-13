#ifndef ABSTRACT_TREE_HPP_
#define ABSTRACT_TREE_HPP_

//Abstract generic superclass for multiple kinds of trees in this project
template<typename T>
class AbstractTree {

public:
	/*
	Adds generic data in form of a new node to the tree
	The method musst be overwritten by subclasses, here it is declared abstract
	*/
	virtual void insert(T value) = 0;

	/*
	Checks if the tree contains a node containing the received generic value.
	The method musst be overwritten by subclasses, here it is declared abstract
	*/
	virtual bool hasElement(T value) = 0;

	/*
	Deletes the node containing the received generic value from the tree.
	The method musst be overwritten by subclasses, here it is declared abstract
	*/
	virtual void del(T value) = 0;

};

#endif