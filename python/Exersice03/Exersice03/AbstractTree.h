#ifndef ABSTRACT_TREE_HPP_
#define ABSTRACT_TREE_HPP_

template<typename T>
class AbstractTree {

public:

	virtual void insert(T data) = 0;

	virtual bool search(T data) = 0;

	virtual void remove(T data) = 0;
	// These Methods are marked as virtual by the virtual-keyword : 
	// A virtual method is a function or method whose 
	// behavior can be overridden within an inheriting class by a function with the same signature.
};

#endif