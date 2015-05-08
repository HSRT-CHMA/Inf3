#include <stdio.h>
#include <assert.h>
#include "Tree.h"
#include <iostream>


using namespace std;

/*Default Constructor*/
Tree::Tree(){
	root = NULL;
}

//das hinzugefügt
Tree::Tree(int value){
	root = new Node(value);
}

/*returns the Root*/
Node* Tree::getRoot(){
	//assert(root != NULL || root == NULL);
	return root;
}

/*methode to set a Root*/
void Tree::setRoot(Node* root){
	//assert(root != NULL || root == NULL);
	this->root = root;
}

/*return the smallest value of the tree*/
int Tree::getSmallest(){
	Node*node = getSmallestNode(root);
	if (root != NULL){
		return root->getData();
	}
	else{
		throw new exception("Root is null !");
	}
}

/*
the smallest Node is the lowest node on the left side of the Tree
this method running as long the lowest node on the left side is not Null
than return the node
*/
Node* Tree::getSmallestNode(Node* start){
	//assert(start != NULL);
	if (start != NULL){
		while (start->getLeft() != NULL){
			start = start->getLeft();
		}
		return start;
	}
	else{
		//assert(start == NULL);
		throw new exception("Root is missing");
	}
}

/*return the biggest value of the tree*/
int Tree::getBiggest(){
	Node*start = getBiggestNode(root);
	if (root != NULL){
		return start->getData();
	}
	else{
		throw new exception("Root is missing");
	}
}

/*
the biggest Node is the lowest node on the right side of the Tree
this method running as long the lowest node on the right side is not Null
than return the node
*/
Node* Tree::getBiggestNode(Node* start){
	//assert(start != NULL);
	if (start != NULL){
		while (start->getRight() != NULL){
			start = start->getRight();
		}
		return start;
	}
	else{
		//assert(start == NULL);
		throw new exception("Root is missing");
	}
}

/*
if the tree is empty, creat a new Node with the value
else we call the method insertNodeRecursion()
*/
void Tree::insert(int data){
	//assert(data <= 0 || data >= 0);
	//if empty assign to node
	if (root == NULL) {
		root = new Node(data);
	}
	//if more than one node
	else {
		//assert(data <= 0 || data >= 0);
		insertNodeRecursion(data, root);
	}
}

/*creates new nodes left an right*/
void Tree::insertNodeRecursion(int data, Node* node){
	//assert(data <= 0 || data >= 0);
	if (data < node->getData()) {
		if (node->getLeft() != 0) {
			/*if left not empty keep looking*/
			insertNodeRecursion(data, node->getLeft());
		}
		/*create left node*/
		else {
			Node* left = new Node(data);
			node->setLeft(left);
		}
	}
	else {
		if (node->getRight() != 0) {
			/*if right not empty keep looking*/
			insertNodeRecursion(data, node->getRight());
		}
		/*create left node*/
		else {
			Node* right = new Node(data);
			node->setRight(right);
		}
	}
}

/*calls the method removeRecursion*/
bool Tree::remove(int data){
	return removeRecursion(root, data, NULL, false);
}


bool Tree::removeRecursion(Node* node, int data, Node* parent, bool leftFromParent){
	//assert(data <= 0 || data >= 0);
	//assert(node != NULL);
		if (node == NULL){
			return false;
		}
		if ((data == node->getData())){
			//assert(node->getLeft() == NULL || node->getRight() == NULL);
			if ((node->getLeft() == NULL) && (node->getRight() == NULL)){
				if (parent == NULL){
					root = NULL;
				}
				else{
					//assert(node->getLeft() != NULL || node->getRight() != NULL);
					underParent(parent, leftFromParent, NULL);
				}
			}
			//assert(node->getLeft() == NULL && node->getRight() != NULL);
			if ((node->getLeft() == NULL) && (node->getRight() != NULL)){
				if (root == NULL){
					root = node->getRight();
				}
				else{
					//assert(node->getRight() != NULL);
					underParent(parent, leftFromParent, node->getRight());
					parent->setParent(node);
				}
			}
			//assert(node->getLeft() != NULL && node->getRight() == NULL);
			if ((node->getLeft() != NULL) && (node->getRight() == NULL)){
				if (root == NULL){
					root = node->getLeft();
				}
				else{
					//assert(node->getLeft() != NULL);
					underParent(parent, leftFromParent, node->getLeft());
					parent->setParent(node);
				}
			}
			if ((node->getLeft() != NULL) && (node->getRight() != NULL)){
				Node*newNode = getBiggestNode(node->getLeft());
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
	//assert(left == true || left == false);
	//assert(node != NULL);
	if (left){
		parent->setLeft(node);
	}
	else{
		parent->setRight(node);
	}
}

bool Tree::search(int data){
	//assert(data == NULL);
	if (root == NULL){
		return false;
	}
	else{
		//assert(data != NULL);
		return root->search(data);
	}
}

bool Node::search(int data){
	//assert(data <= 0 || data >= 0);
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
	//assert(node != NULL);
	if (node) {
		//go left
		inOrder(node->getLeft());
		//root
		cout << node->getData() << " ";
		//go right
		inOrder(node->getRight());
	}
}