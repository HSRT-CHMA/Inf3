
#ifndef NODE_H
#define NODE_H

class Node{

private:
	Node* left;
	Node* right;
	Node* parent;
	int value;

public:
	Node(int value, Node* parent);
	Node(int value);
	void setValue(int value);
	void setLeft(Node* left);
	void setRight(Node* right);
	void setParent(Node* parent);

	Node* getLeft();
	Node* getRight();
	int getValue();
	Node* getParent();
};

#endif