// Exersice03.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <iostream>
#include "BinaryTree.h"
#include <cassert>

using namespace std;

int main() {
	//BinaryTree<float> tree;
	BinaryTree<int> * tree = new BinaryTree<int>(68069);
	/* tree.insert(12);
	tree.insert(19);
	tree.insert(11);
	tree.insert(5);
	tree.insert(32);
	tree.insert(7);
	tree.insert(18);
	tree.insert(4);
	tree.insert(9);
	tree.insert(4);
	tree.inOrder(tree.getRoot());
	cout << endl;
	tree.remove(4);
	tree.inOrder(tree.getRoot());
	cout << endl;
	tree.search(9);
	cout << endl;
	tree.search(100); */
	cin.get();

	return 0;

}

