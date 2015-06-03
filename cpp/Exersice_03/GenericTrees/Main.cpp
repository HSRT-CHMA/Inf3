// GenericTrees.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BinaryTree.h"
#include "AVLTree.h"
#include <iostream>
#include <string>


/*Serves as the main-function of this programm*/
int _tmain(int argc, _TCHAR* argv[])
{
	BinaryTree<int> tree = BinaryTree<int>(2);
	std::cout << "Ausgabe 2: " << std::boolalpha << tree.hasElement(2) <<"\n";
	tree.insert(20);
	std::cout << "Ausgabe 20: " << std::boolalpha << tree.hasElement(20) << "\n";
	tree.insert(1);
	std::cout << "Ausgabe 1: " << std::boolalpha << tree.hasElement(1) << "\n";
	tree.insert(0);
	std::cout << "Ausgabe 0: " << std::boolalpha << tree.hasElement(0) << "\n";
	tree.insert(26);
	std::cout << "Ausgabe 26: " << std::boolalpha << tree.hasElement(26) << "\n";

	tree.del(2);
	std::cout << "Ausgabe 2: " << std::boolalpha << tree.hasElement(2) << "\n";
	
	
	std::cout << std::endl;	
	// Causes a line break
	std::cout << std::endl;

	AVLTree<int>* root = new AVLTree<int>(30);
	/* Constructing tree given in the above figure  */
	root->insert(10);
	root->insert(20);
	root->insert(40);
	root->insert(50);
	root->insert(25);
	// More testing !!
	// Beware of the del-function


	/* The constructed AVL Tree would be
	      30
	     /  \
	    20   40
	   /  \    \
	  10  25    50
	*/

	printf("\nPre order traversal of the constructed AVL tree is \n");
	root->preOrderFunction();

	
	AVLTree<std::string> test = AVLTree<std::string>("A");
	test.insert("B");	
	std::cout << "String Element B: " << std::boolalpha << test.hasElement("B") << std::endl;

	getchar();
	//Holds open the console until a char is given an ENTER is pressed

	return 0;
	// showcases the sucessful run of this programm
}

