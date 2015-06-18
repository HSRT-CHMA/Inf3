#ifndef ITREE_HPP_
#define ITREE_HPP_
//Abstract generic class for trees
template<typename T>
class ITree {

public:
	/*
	* Inserts the data into the tree
	* parms: data: The data to be inserted
	*/
	virtual void insert(T data) = 0;

	/*
	* Checks if the tree contains the data
	* parms: data: The data to check the tree for
	*/
	virtual bool has(T data) = 0;

	/*
	* Deletes the data from the tree
	* parms: data: The data that should be deleted
	*/
	virtual void del(T data) = 0;
};
#endif