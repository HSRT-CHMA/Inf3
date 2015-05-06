#include <stdio.h>
#include <assert.h>
#include "Tree.h"
#include <iostream>


using namespace std;
	
Tree::Tree(){
	root = NULL;
}

Node* Tree::getRoot(){
	assert(root != NULL);
	return root;
}

void Tree::setRoot(Node* root){
	this->root = root;
}

int Tree::getSmallestData(){
	Node*node = getSmallestNode(root);
	if (root != NULL){
		return root->getData();
	}
	else{
		throw new exception("Root is null !");
	}
}

Node* Tree::getSmallestNode(Node*start){
	if (start != NULL){
		while (start->getLeft() != NULL){
			start = start->getLeft();
		}
		return start;
	}
	else{
		throw new exception("Root is missing");
	}
}

int Tree::getHighestValue(){
	Node*start = getHighestNode(root);
	if (root != NULL){
		return start->getData();
	}
	else{
		throw new exception("Root is missing");
	}
}

Node* Tree::getHighestNode(Node*start){
	if (start != NULL){
		while (start->getRight() != NULL){
			start = start->getRight();
		}
		return start;
	}
	else{
		throw new exception("Root is missing");
	}
}

void Tree::insert(int data){
	//if empty assign to node
	if (root == NULL) {
		root = new Node(data);
	}
	//if more than one node
	else {
		insertNodeRecursion(data, root);
	}
}

void Tree::insertNodeRecursion(int data, Node* NewNode){
	if (data < NewNode->getData()) {
		if (NewNode->getLeft() != 0) {
			//if left not empty keep looking
			insertNodeRecursion(data, NewNode->getLeft());
		}
		//create left node
		else {
			Node* left = new Node(data);
			NewNode->setLeft(left);
		}
	}
	else {
		if (NewNode->getRight() != 0) {
			//if right not empty keep looking
			insertNodeRecursion(data, NewNode->getRight());
		}
		//create left node
		else {
			Node* right = new Node(data);
			NewNode->setRight(right);
		}
	}
}

bool Tree::remove(int data){
	return removeRecursion(root, data, NULL, false);
}

bool Tree::removeRecursion(Node* node, int data, Node*parent, bool leftFromParent){
		if (node == NULL){
			return false;
		}
		if ((data == node->getData())){
			if ((node->getLeft() == NULL) && (node->getRight() == NULL)){
				if (parent == NULL){
					root = NULL;
				}
				else{
					underParent(parent, leftFromParent, NULL);
					//printf("%i", node->getData());
				}
			}
			if ((node->getLeft() == NULL) && (node->getRight() != NULL)){
				if (root == NULL){
					root = node->getRight();
				}
				else{
					underParent(parent, leftFromParent, node->getRight());
					parent->setParent(node);
					//printf("%i", node->getData());
				}
			}
			if ((node->getLeft() != NULL) && (node->getRight() == NULL)){
				if (root == NULL){
					root = node->getLeft();
				}
				else{
					underParent(parent, leftFromParent, node->getLeft());
					parent->setParent(node);
				}
			}
			if ((node->getLeft() != NULL) && (node->getRight() != NULL)){
				Node*newNode = getHighestNode(node->getLeft());
				remove(newNode->getData());
				if (parent == NULL){
					newNode->setLeft(root->getLeft());
					newNode->setRight(root->getRight());
					root = newNode;
				}
				else{
					newNode->setLeft(node->getLeft());
					newNode->setRight(node->getRight());
					underParent(parent, leftFromParent, newNode);
					parent->setParent(newNode);
				}
			}
			removeRecursion(root, data, NULL, false);
			return true;
		}
		if ((data < node->getData())){
			if (node->getLeft() == NULL){
				return false;
			}
			return removeRecursion(node->getLeft(), data, node, true);
		}
		if (data > node->getData()){
			if (node->getRight() == NULL){
				return false;
			}
			else{
				return removeRecursion(node->getRight(), data, node, false);
			}
		}
		return false;
}

void Tree::underParent(Node* parent, bool left, Node* node){
	if (left){
		parent->setLeft(node);
	}
	else{
		parent->setRight(node);
	}
}

bool Tree::search(int data){
	if (root == NULL){
		return false;
	}
	else{
		return root->search(data);
	}
}

bool Node::search(int data){
	if (data == this->data){
		printf("true");
		return true;
	}
	else if (data < this->data){
		if (left == NULL){
			printf("false");
			return false;
		}
		else{
			return left->search(data);
		}
	}
	else if (data > this->data) {
		if (right == NULL){
			printf("false");
			return false;
		}
		else{
			return right->search(data);
		}
	}
	printf("false");
	return false;
}

void Tree::inOrder(Node* node) {
	if (node) {
		//go left
		inOrder(node->getLeft());
		//root
		cout << node->getData() << " ";
		//go right
		inOrder(node->getRight());
	}
}