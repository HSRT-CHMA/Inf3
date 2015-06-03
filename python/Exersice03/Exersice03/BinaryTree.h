#ifndef BinaryTree_H
#define BinaryTree_H

#include "Node.h"
#include "AbstractTree.h"


template <typename T>
class BinaryTree /*: public AbstractTree <T> */ {
	//Instantiation condition : T is a comparable type

protected:

	Node<T> * root = NULL;

	bool found = false;
	// To be used in hasRecursion() to showcase the outcome of this Methode



	bool removeRecursion(Node<T>* node, T data, Node<T>* parent, bool leftFromParent){
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

	void underParent(Node<T>* parent, bool left, Node<T>* node){
		//assert(left == true || left == false);
		//assert(node != NULL);
		if (left){
			parent->setLeft(node);
		}
		else{
			parent->setRight(node);
		}
	}

	/*returns the Root*/
	Node<T>* getRoot(){
		//assert(root != NULL || root == NULL);
		return root;
	}

	/*methode to set a Root*/
	void setRoot(Node<T>* root){
		//assert(root != NULL || root == NULL);
		this->root = root;
	}

	/*return the smallest value of the BinaryTree*/
	T getSmallest(){
		Node*node = getSmallestNode(root);
		if (root != NULL){
			return root->getData();
		}
		else{
			throw new exception("Root is null !");
		}
	}

	/*
	the smallest Node is the lowest node on the left side of the BinaryTree
	this method running as long the lowest node on the left side is not Null
	than return the node
	*/
	Node<T>* getSmallestNode(Node<T>* start){
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

	/*return the biggest value of the BinaryTree*/
	T getBiggest(){
		Node*start = getBiggestNode(root);
		if (root != NULL){
			return start->getData();
		}
		else{
			throw new exception("Root is missing");
		}
	}

	/*
	the biggest Node is the lowest node on the right side of the BinaryTree
	this method running as long the lowest node on the right side is not Null
	than return the node
	*/
	Node<T>* getBiggestNode(Node<T>* start){
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

	/*creates new nodes left and right*/
	void insertNodeRecursion(T data, Node<T>* node){
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

	bool hasRecursion(Node<T> * node, T data) {
		this->found = false;
		if (node != NULL && node->getData() == data) {
			this->found = true;
		}
		else {
			if (node != NULL && !(this->found)) {
				if (data < node->getData()) {
					hasRecursion(node->getLeft(), data);
				}
				else {
					hasRecursion(node->getRight(), data);
				}
			}
		}
		return found;
	}



public:

	BinaryTree(T value){
		root = new Node(value);
	}

	bool search(T data){
		//assert(data == NULL);
		if (root == NULL){
			return false;
		}
		else{
			//assert(data != NULL);
			return hasRecursion(this->root, data);
		}
	}

	/*This methode will delete the node with the given value , if it exists in the tree*/
	bool remove(T data)
	{
		return removeRecursion(root, data, NULL, false);
	}


	/*
	if the BinaryTree is empty,this method will create a new Node with the given value
	else it will call the method insertNodeRecursion() to insert the given value
	*/
	void insert(T data){
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

};



/*class BinaryTree {
private:
Node* root;
Node* getSmallestNode(Node* start);
Node* getBiggestNode(Node* start);
void insertNodeRecursion(int data, Node* NewNode);
bool removeRecursion(Node* node, int data, Node* parent, bool leftFromParent);
void underParent(Node* parent, bool left, Node* node);

public:
BinaryTree();
BinaryTree(int value); //das hinzugefügt
Node* getRoot();
int getSmallest();
int getBiggest();
void setRoot(Node* root);
void insert(int data);
bool remove(int data);
bool search(int data);
void inOrder(Node* node);

}; */ // end Binary.H

#endif