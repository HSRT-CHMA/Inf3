#include <iostream>
#include "Node.h"


Node::Node(){
}
//node with data
Node::Node(int data){
	this->parent = nullptr;
	this->right = nullptr;
	this->left = nullptr;
	this->setData(data);
}

void Node::setRight(Node* right){
	this->right = right;
}
void Node::setLeft(Node* left){
	this->left = left;
}

void Node::setParent(Node* parent){
	this->parent = parent;
}

void Node::setData(int data){
	this->data = data;
}

Node* Node::getRight(){
	return right;
}

Node* Node::getLeft(){
	return left;
}

Node* Node::getParent(){
	return parent;
}

int Node::getData(){
	return data;
}