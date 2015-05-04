#include "Tree.h"
#include <string>
#include <math.h>					//Include for max function
#include <algorithm>
#include <iostream>
#include <assert.h>					//Include for asserts

using namespace std;

class Tree{

private:
	Node* root = NULL;

	/*
	Constructor of BinaryTree
	Creates a new TreeNode which contains the value of value
	*/
	Tree::Tree(int value)	{
		assert(value >= 0 || value <= 0);
		root = new Node(value);
	}

	/*Returns the root*/
	Node* Tree::root(){
		return root;
	}

	/*
	Writes the smallest value of the BinaryTree into the TreeNode Object
	and calls the getSmallest method with root as the parameter
	If the TreeNode Object is empty because the BinaryTree was empty it returns NULL
	Else it returns the smallest value inside the BinaryTree
	*/
	int Tree::getSmallest(){
		Node* k = getSmallest(root);
		if (k == NULL){
			return NULL;
		}
		else{
			return k->getValue();
		}
	}

	/*
	if a root(BinaryTree) exists
	Goes through all TreeNode Levels until it reaches the last left TreeNode
	returns start which contains the smallest value of the BinaryTree
	*/
	Node* Tree::getSmallest(Node* start){
		assert(start != NULL);
		if (start != NULL){
			while (start->getLeft() != NULL){
				start = start->getLeft();
			}
		}
		return start;
	}

	/*
	Writes the biggest value of the BinaryTree into the TreeNode Object
	and calls the getBiggest method with root as the parameter
	If the TreeNode Object is empty because the BinaryTree was empty it returns NULL
	Else it returns the biggest value inside the BinaryTree
	*/
	int Tree::getBiggest(){
		Node* k = getBiggest(root);
		if (k == NULL){
			return NULL;
		}
		else{
			return k->getValue();
		}
	}

	/*
	Exact same function as getSmallest,instead of finding the smallest
	find the TreeNode with the biggest value of the BinaryTree
	by going through all the right TreeNodes from all the TreeNode levels
	And then it returns the biggest value of the BinaryTree
	*/
	Node* Tree::getBiggest(Node* start){
		assert(start == NULL || start != NULL);
		if (start != NULL){
			while (start->getRight() != NULL){
				start = start->getRight();
			}
		}
		return start;
	}

	/*
	Prints out the values of the BinaryTree in the following order: 
	Goes from left to root to right
	*/
	void Tree::inOrderOutPut(Node* k){
		if (k != NULL){
			/*left side*/
			inOrderOutPut(k->getLeft());
			/*root*/
			cout << k->getValue() << " ";
			/*right side*/
			inOrderOutPut(k->getRight());
		}
	}

	/*
	Inserts a value to the Tree
	If a Tree doesnt exist, Creates a new Tree
	Calls the recursion with the parameters root and value which contains the value to be inserted into the tree
	*/
	void Tree::insert(int value){
		assert(value <= 0 || value >= 0);
		if (root == NULL){
			root = new Node(value);
		}
		this->insertValue(root, value);
	}

	/*
	if TreeNode doesnt exist, Creates a new TreeNode with the value to be inserted
	If Tree doesnt exist, the TreeNode becomes the root
	If value to be inserted is smaller the the parent(root) and If a left TreeNode exists
	goes through the Recursion until it finds an empty left TreeNode
	if a left TreeNode doesnt exist ist creates a new TreeNode
	and puts the value on the left side of the parent(root)
	If value to be inserted is bigger the the parent(root) and If a right TreeNode exists
	goes through the Recursion until it finds an empty right TreeNode
	if a right TreeNode doesnt exist ist creates a new TreeNode
	and puts the value on the right side of the parent(root)
	*/
	void Tree::insertValue(Node* k, int value){
		assert(value <= 0 || value >= 0);
		
		if (k == NULL){
			k = new Node(value);
			if (root == NULL){
				root = k;
			}
		}
		else{
			if ((value < (k->getValue()))){
				if (k->getLeft() != NULL){
					insertValue(k->getLeft(), value);
				}
				else{
					k->setLeft(new Node(value));
				}
			}
			if ((value > (k->getValue()))){
				if (k->getRight() != NULL){
					insertValue(k->getRight(), value);
				}
				else{
					k->setRight(new Node(value));
				}
			}
		}
	}

	/*
	Deletes a TreeNode
	Calls the deleteRecursion with the parameters root,value which contains the value to be deleted,
	NULL for the parent,and false for left from parent
	*/
	bool Tree::deleteValue(int value){
		assert(value <= 0 || value >= 0);
		return deleteValueRecursion(root, value, NULL, false);
	}

	/*
	if value to delete equals value from parent(root)
	If Parent(root) has no children Is Node
	If Parent(root) doesnt exist, Parent(root) is NULL Deletes root
	Calls Method hangingUnderParent to put Node on the left or right side of the Parent,v 
	but in this case parent doesnt have childen
	If Parent has child only on the right side, Root gets the value of right Node
	Calls hangingUnderParent and deletes right side because it is NULL
	If Parent has child only on the left side, Root gets the value of the left side
	Calls hangingUnderParent and deletes left side because it is NULL
	If Parent has two childen it gets the smallest form the right child
	Deletes the TreeNode
	If parent doesnt exist
	*/
	bool Tree::deleteValueRecursion(Node* k, int value, Node* parent, bool leftFromParent){
		assert(value <= 0 || value >= 0);
		if (k == NULL){
			return false;
		}
		if ((value == (k->getValue()))){
			if ((k->getLeft() == NULL) && (k->getRight() == NULL)){
				if (parent == NULL){
					root = NULL;
				}
				else{
					underParent(parent, leftFromParent, NULL);
				}
				return true;
			}
			if ((k->getLeft() == NULL) && (k->getRight() != NULL)){
				if (parent == NULL){
					root = k->getRight();
				}
				else{
					underParent(parent, leftFromParent, k->getRight());
				}
				return true;
			}
			if ((k->getLeft() != NULL) && (k->getRight() == NULL)){
				if (parent == NULL){
					root = k->getLeft();
				}
				else{
					underParent(parent, leftFromParent, k->getLeft());
				}
				return true;
			}
			Node* x = getSmallest(k->getRight());
			deleteValue(x->getValue());
			/**/
			if (parent == NULL){
				/*Sets the children from the old parent which was the root*/
				x->setLeft(root->getLeft());
				/*to the new parent*/
				x->setRight(root->getRight());
				/*The smallest child becomes the new parent(root)*/
				root = x;
			}
			else{
				/*Gets the left Node from the deleted Parent*/
				x->setLeft(k->getLeft());
				/*Gets the right Node from the deleted Parent*/
				x->setRight(k->getRight());
				/*Delets the TreeNode*/
				underParent(parent, leftFromParent, x);
			}
		}
		/*If value is on the left side*/
		if ((value < (k->getValue()))){
			if (k->getLeft() == NULL){
				return false;
			}
			/*Goes through the recursion until it finds the right Node on the left side*/
			return deleteValueRecursion(k->getLeft(), value, k, true);
		}
		/*If value is on the right side*/
		if ((value >(k->getValue()))){
			if (k->getRight() == NULL){
				return false;
			}
			/*Goes through the recursion until it finds the right Node on the right side*/
			return deleteValueRecursion(k->getRight(), value, k, false);
		}
		return false;
	}

	void Tree::underParent(Node* parent, bool left, Node* k)
	{
		assert(left == true || left == false);
		if (left){
			/*Deletes Left side by setting Left to NULL*/
			parent->setLeft(k);
		}
		else{
			/*Deletes Left side by setting Right to NULL*/
			parent->setRight(k);
		}
	}


	/*
	If HasValue returns null --> nothing found or no tree --> false
	If HasValue returns an Node --> Value found in tree --> true
	*/
	bool Tree::has(int value){
		assert(value <= 0 || value >= 0);
		bool result;

		if (hasValueRecursion(root, value) != NULL){
			result = true;
		}
		else{
			result = false;
		}

		return result;
	}

	Node* Tree::hasValueRecursion(Node* n, int value){
		assert(value <= 0 || value >= 0);
		Node result = NULL;

		if (n == NULL){
			result = NULL;
		}

		if (n->getValue() == value){ //Found it
			return n;
		}

		if (n->getValue() <	 value){
			if (n->getLeft() == NULL){
				result = NULL;
			}
			else{
				hasValueRecursion(n->getLeft(), value);
			}
		}

		if (n->getValue() > value){
			if (n->getRight() == NULL){
				result = NULL;
			}
			else{
				hasValueRecursion(n->getRight(), value);
			}
		}
	}

};

int main(){
	Tree t();

}