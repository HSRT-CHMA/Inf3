#include <stdio.h>
#include <assert.h>
#include <iostream>
#include "Node.h"


Node::Node(){
	//assert(this->parent == NULL && this->right == NULL && this->left == NULL & this->data == NULL);
}
//node with data
Node::Node(int data){
	this->parent = nullptr;
	this->right = nullptr;
	this->left = nullptr;
	this->setData(data);
}

void Node::setRight(Node* right){
	//assert(right != NULL);
	this->right = right;
}
void Node::setLeft(Node* left){
	//assert(left != NULL);
	this->left = left;
}

void Node::setParent(Node* parent){
	//assert(parent != NULL);
	this->parent = parent;
}

void Node::setData(int data){
	//assert(data <= 0 || data >= 0);
	this->data = data;
}

Node* Node::getRight(){
	//assert(right == Node::getRight());
	return right;
}

Node* Node::getLeft(){
	//assert(left == Node::getLeft());
	return left;
}

Node* Node::getParent(){
	//assert(parent == Node::getParent());
	return parent;
}

int Node::getData(){
	//assert(data <= 0 || data >= 0);
	return data;
}