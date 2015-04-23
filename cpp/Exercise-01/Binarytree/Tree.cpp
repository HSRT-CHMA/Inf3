#include <iostream>
#include "Node.cpp";
#include <string>;

using namespace std;

class Tree{
private:
	Node* root = NULL;
	void insertValue(Node, int);
	Node hasValue(Node, int);
	bool deleteValue(Node, int, Node, bool);
	void findParent(Node, bool, Node);
	string inOrder(Node);



public:
	Tree(int);
	void insert(int);
	bool has(int);
	bool del(int);
	int getSmallest();
	Node getSmal(Node start);
	int getBiggest();
	Node getBig(Node start);
	string inOrderOutPut();





	/* Constructor for BinaryTree with int values */
	Tree(int value){
		root = new Node(value);
	}

	/*
	Method creates a tree with given value as root, or
	adds new given int-value to existing tree by calling InsertValue-Metod
	*/
	void insert(int value){
		cout << "New Tree with root-value" << value << endl;

		if (root == NULL){
			root = new Node(value, NULL);
		}
		else{
			this->insertValue(root, value);
		}
	}

	/*
	Method to insert values, smaller than root on the left child,
	bigger than root or equal on the rigth child
	*/
	void insertValue(Node* new_n, int new_value){
		if (new_n == NULL){
			new_n = new Node(new_value, NULL);
		}

		if (root == NULL){
			root = new_n;
		}
		else{
			if ((new_value->compare(new_n->getValue())) < 0){
				if (new_n->getLeft() != NULL){
					insertValue(new_n->getLeft(), new_value);
				}
				else{
					new_n->setLeft(new Node(new_value));
					cout << "Left: " << new_value << endl;
				}

			}

			if (new_value.compare(new_n->getValue()) >= 0){
				if (new_n->getRight() != NULL){
					insertValue(new_n->getRight(), new_value);
				}
				else{
					new_n->setRight(new Node(new_value));
					cout << "Right: " << new_value << endl;
				}
			}
		}
	}

	/*
	If HasValue2 returns null --> nothing found or no tree --> false
	If HasValue2 returns an Node --> Value found in tree --> true
	*/
	bool has(int new_value){
		bool result;

		if (hasValue(root, value) != NULL){
			result = true;
		}
		else{
			result = false;
		}

		return result;
	}

	Node hasValue(Node* n, int value){
		Node result = NULL;

		if (n == NULL){
			result = NULL;
		}

		if (value->compare(n->getValue()) == 0){ //Found it
			return *n;
		}

		if (value->compare(n->getValue()) < 0){
			if (n->getLeft() == NULL){
				result = NULL;
			}
			else{
				result = hasValue(n->getLeft(), value);
			}
		}

		if (value->compare(n->getValue()) > 0){
			if (n->getRight() == NULL){
				result = NULL;
			}
			else{
				result = hasValue(n->getRight(), value);
			}
		}

		return result;
	}


	/* Method redirects to DeleteValue() */
	bool del(int new_value){
		return deleteValue(root, new_value, NULL, false);
	}

	/*
	If Tree is empty, nothing can be deleted
	Method receive root-Node , new value, the parent node and flag if node is left
	*/
	bool deleteValue(Node* new_n, int new_value, Node* parent, bool is_left){
		if (new_n == NULL){
			return false;
		}

		if (new_value->compare(new_n->getValue()) == 0){
			if ((new_n->getLeft() == NULL) && (new_n->getRight() == NULL)){
				if (parent == NULL){
					root = NULL;
				}
				else{
					findParent(*parent, is_left, NULL);
				}
				return true;

			}

			if ((new_n->getLeft() != NULL) && (new_n->getRight() == NULL)){
				if (parent == NULL){
					root = NULL; // Sicher ? Warum nicht : new_n.GetLeft() ?
				}
				else{
					findParent(*parent, is_left, *new_n->getLeft());
				}

				return true;
			}


			if ((new_n->getLeft() == NULL) && (new_n->getRight() != NULL)){
				if (parent == NULL){
					root = new_n->getRight();

				}
				else{
					findParent(*parent, is_left, *new_n->getRight());
				}

				return true;
			}

			Node* n = getSmal(*new_n->getRight());
			del(n->getValue());
			if (parent == NULL){
				n->setLeft(root->getLeft());
				n->setRight(root->getRight());
				root = n;
			}
			else{
				n->setLeft(new_n->getLeft());
				n->setRight(new_n->getRight());
				findParent(*parent, is_left, n);
			}
		}

		/*Found nothing : continue search on left side*/
		if (new_value->compare(new_n->getValue()) < 0){
			if (parent->getLeft() == NULL){
				return deleteValue(new_n->getLeft(), new_value, parent, true);
			}
		}

		//Found nothing : continue search on right side
		if (new_value->compare(new_n->getValue()) > 0){
			if (parent->getRight() == NULL){
				return deleteValue(new_n->getRight(), new_value, parent, false);
			}
		}

		return false;

	}

	/*
	Method returns the smallest value existing in the current tree
	Warning if there exists no tree
	*/
	int getSmallest(){
		Node* node = getSmal(root);
		int value = 0;

		if (node != NULL){
			value = node->getValue();
		}
		else{
			cout << "Class BinaryTree, Method getSmallest, no Tree exists" << endl;
		}

		return value;
	}

	/*
	Method returns the Node which is the last on the left side,
	so the one with the smallest value (if added correctly)
	*/
	Node getSmal(Node* start){
		if (start != NULL){
			while (start->getLeft() != NULL){
				start = start->getLeft();
			}
		}
		return *start;
	}

	/*
	Method returns the biggest value existing in the current tree
	Warning if there exists no tree
	*/
	int getBiggest(){
		Node* node = getBig(root);
		int value = 0;

		if (node != NULL){
			value = node->getValue();
		}
		else{
			cout << "Class BinaryTree, Method GetBiggest, no Tree exists " << endl;
		}
		return value;
	}

	/*
	Method returns the Node which is the last on the rigth side,
	so the one with the biggest value (if added correctly)
	*/
	Node GetBiggest(Node* start){
		if (start != NULL){
			while (start->getRight() != NULL){
				start = start->getRight();
			}
		}
		return *start;
	}

	/*Method for Testig : Redirects to In-Order (L, W, R) - Method*/
	string InOrderOutput(){
		return InOrder(root);
	}

	/*
	* Method for Testig : Returns the values of tree in In-Order (L, W, R)
	*/
	string InOrder(Node* node){
		string value = "";

		if (node == NULL){
			cout << "This binary tree is empty " << endl;
		}

		//L
		if (node->getLeft() != NULL){
			value += InOrder(node->getLeft());
			value += " | ";
		}

		//W
		value += node->getValue();
		value += " | ";

		//
		if (node->getRight() != NULL){
			value += InOrder(node->getRight());
			value += " | ";
		}

		return value;
	}

	/*Method to set a Node "under" a given parent-node , either left or rigth */
	void FindParent(Node* parent, bool left, Node* new_n){
		if (left){
			parent->setLeft(new_n);
		}
		else{
			parent->setRight(new_n);
		}
	}
};