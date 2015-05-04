#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree{
private:
	void insertValue(Node, int);
	Node hasValueRecursion(Node, int);
	bool deleteValueRecursion(Node, int, Node, bool);
	void underParent(Node, bool, Node);
	string inOrder(Node);

public:
	Node* root();
	Tree(int);
	void insert(int);
	bool has(int);
	bool deleteValue(int);
	int getSmallest();
	Node* getSmallest(Node* start);
	int getBiggest();
	Node* getBiggest(Node* start);
	void inOrderOutPut(Node*);
};

#endif