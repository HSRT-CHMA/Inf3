// GenericTrees.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BinaryTree.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <cassert>
#include "TesterOfINT.h"
#include  "TesterOfString.h"



/*Serves as the main-function of this programm*/
int _tmain(int argc, _TCHAR* argv[])
{

	/* Testing on a Binary Tree with int  */
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
	std::cout << std::endl;
	// Causes a line break

	/* Testing on an AVL tree with int */
	AVLTree<int> * avl = new AVLTree<int>(2);	
	avl->insert(20);
	avl->insert(1);
	avl->insert(0);
	avl->insert(26);
	avl->insert(300);
	avl->insert(1000);
	avl->insert(500);
	avl->insert(400);
	avl->insert(5000);


	std::cout << std::endl;
	std::cout << std::endl;
	// Causes a line break

	avl->printTree();
	std::cout << std::endl << "Balance from Tree: " << avl->getBalanceFromTree() << std::endl << std::endl;



	/*-------------------------------- Task 4 Test ------------------------------------------------------------------------------*/

	//Integer

	TesterOfINT<int> tester = TesterOfINT<int>(3, 1000, 1000);
	std::vector<int> tmp = tester.getArray();

	std::cout << "Create Tree with : " << tmp[0] << std::endl;
	AVLTree<int> * root = new AVLTree<int>(tmp[0]);

	for (int a = 1; a < tmp.size(); a++)
	{
		std::cout << "Insert: "<< tmp[a] << std::endl;
		root->insert(tmp[a]);
		assert( root->hasElement(tmp[a]) );
		std::cout << "Balance from Tree after insert: " << root->getBalanceFromTree() << std::endl;
	}
	for (int a = 1; a < tmp.size(); a++)
	{
		root->del(tmp[a]);
		assert(!root->hasElement(tmp[a]));
		std::cout << "Deleted: " << tmp[a] << std::endl;
		std::cout << "Balance from Tree after delete: " << root->getBalanceFromTree() << std::endl;
	}
	root->del(tmp[0]);
	assert(!root->hasElement(tmp[0]));
	std::cout << "Deleted: " << tmp[0] << std::endl;

	getchar();

	return 0;
}

