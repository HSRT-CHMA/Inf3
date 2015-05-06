#ifndef NODE_H
#define NODE_H

class Node {
private:
	Node* right;
	Node* left;
	Node* parent;
	int data;

public:
	//empty node
	Node();
	//node with data
	Node(int data);
	void setRight(Node* right);
	void setLeft(Node* left);
	void setParent(Node* parent);
	void setData(int data);
	Node* getRight();
	Node* getLeft();
	Node* getParent();
	int getData();
	bool search(int data);
}; // end Node class



#endif