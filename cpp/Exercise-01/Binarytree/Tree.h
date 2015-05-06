#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
private:
	Node* root;
	void insertNodeRecursion(int data, Node* NewNode);
	bool removeRecursion(Node* node, int data, Node* parent, bool leftFromParent);
	void underParent(Node* parent, bool left, Node* node);

public:
	Tree();
	Node* getRoot();
	int getSmallestData();
	Node* getSmallestNode(Node* start);
	int getHighestValue();
	Node* getHighestNode(Node* start);
	void setRoot(Node* root);
	void insert(int data);
	bool remove(int data);
	bool search(int data);
	void inOrder(Node* node);

}; // end Binary.H

#endif