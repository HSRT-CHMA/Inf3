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

	/* Testing on a Binary Tree with -----------------int-------------------  */
	BinaryTree<int> tree = BinaryTree<int>(2);
	std::cout << "Test on BinaryTree-Tree with int ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Causes a line break
	std::cout << "Is 2 in tree : " << std::boolalpha << tree.hasElement(2) <<"\n";
	tree.insert(2.0);
	std::cout << "Is 20 in tree : " << std::boolalpha << tree.hasElement(20) << "\n";
	tree.insert(1);
	std::cout << "Is 1 in tree : " << std::boolalpha << tree.hasElement(1) << "\n";
	tree.del(2);
	std::cout << "Is 2 in tree : " << std::boolalpha << tree.hasElement(2) << "\n";
	
	std::cout << std::endl;	
	std::cout << std::endl;
	// Causes a line break

	/*Testing on a Binary Tree with  --------------------String----------------  */
	std::cout << "Test on BinaryTree-Tree with STRING ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Causes a line break
	
	BinaryTree<std::string> tree_st = BinaryTree<std::string>("Test");
	std::cout << "Is 'Test' in tree : " << std::boolalpha << tree_st.hasElement("Test") << "\n";
	tree_st.insert("T");
	std::cout << "Is 'T' in tree : " << std::boolalpha << tree_st.hasElement("T") << "\n";
	tree_st.insert("Hello");
	std::cout << "Is 'Hello' in tree : " << std::boolalpha << tree_st.hasElement("Hello") << "\n";
	tree.del('T');
	std::cout << "'T' got deleted, thereby false : " << std::boolalpha << tree.hasElement('T') << "\n";
	std::cout << std::endl;
	std::cout << std::endl;
	// Causes a line break
	
	/* Testing on an AVL tree with ------------------------int--------------------- */
	AVLTree<int> * avl = new AVLTree<int>(2);	
	std::cout << "Test on AVL-Tree with int ";
	std::cout << std::endl;
	std::cout << std::endl;
	// Causes a line break
	std::cout << "Ausgabe 2: " << std::boolalpha << avl->hasElement(2) << "\n";
	avl->insert(20);
	std::cout << "Ausgabe 20: " << std::boolalpha << avl->hasElement(20) << "\n";
	avl->insert(1);
	std::cout << "Ausgabe 1: " << std::boolalpha << avl->hasElement(1) << "\n";
	avl->insert(0);
	std::cout << "Ausgabe 0: " << std::boolalpha << avl->hasElement(0) << "\n";
	avl->insert(26);
	std::cout << "Ausgabe 26: " << std::boolalpha << avl->hasElement(26) << "\n";

	avl->del(2);
	std::cout << "Ausgabe 2: " << std::boolalpha << avl->hasElement(2) << "\n";


	std::cout << std::endl;
	std::cout << std::endl;
	// Causes a line break

	avl->printTree();
	std::cout << std::endl << "Balance from Tree: " << avl->getBalanceFromTree() << std::endl << std::endl;



	/*-------------------------------- Task 4 Test ------------------------------------------------------------------------------*/

	std::cout << std::endl << "------- Task 4 Test  : " << std::endl << std::endl;

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
	// Holds open the command line 

	return 0;
	//Showcases the sucessful outcome of the main-function
}

