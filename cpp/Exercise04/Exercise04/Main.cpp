#include "stdafx.h"
#include "iostream"
#include <string>
#include "TestForString.h"
#include "TestForFloat.h"
// Main for Executing Program
int _tmain(int argc, _TCHAR* argv[]) {

	std::cout << "----------------- Test 1 - BinaryTree with strings ------------------" << std::endl;
	//Testing Binarytree with strings - Test 1
	BinaryTree<std::string> * STree = new BinaryTree<std::string>();
	TestForString * testStr = new TestForString(STree);
	//fill the tree with random strings
	testStr->initRandom(1, 6, 20);
	STree->inOrderOut();
	// filter the tree for strings size >=3 
	std::cout << "strings with length >=3:" << std::endl;
	STree->filter([](std::string data){return (data.length() >= 3); });
	STree->printStringFilter();
	// filter the tree for strings with the letter s
	std::cout << "strings with s or S:" << std::endl;
	STree->filter([](std::string data){std::size_t found = ((data.find_first_of("s")) & (data.find_first_of("S"))); return (found != std::string::npos); });
	STree->printStringFilter();

	std::cout << "----------------- Test 2 - BinaryTree with floats ------------------" << std::endl;
	//Testing Binarytree with floats - Test 2
	BinaryTree<float> * FTree = new BinaryTree<float>();
	TestForFloat * testFlt = new TestForFloat(FTree);
	//fill the tree with random floats
	testFlt->initRandom(-50, 50, 10);
	FTree->insert(2.00);
	FTree->inOrderOut();
	// filter the tree for even elements
	std::cout << "floats even:" << std::endl;
	FTree->filter([](float data){return (((int)data % 2) == 0) && ((data - (int)data) == 0); });
	FTree->printFloatFilter();
	// filter the tree for elements <=5
	std::cout << "floats <= 5:" << std::endl;
	FTree->filter([](float data){return (data <= 5); });
	FTree->printFloatFilter();
	// filter the tree for negativ elements
	std::cout << "floats negativ:" << std::endl;
	FTree->filter([](float data){return (data < 0); });
	FTree->printFloatFilter();
/*
	std::cout << "----------------- Test 3 - BinaryTree with floats manual ------------------" << std::endl;
	//Testing manual floats - Test 3
	std::cout << "BinaryTree<float> -> filter(even)" << std::endl;
	BinaryTree<float> * bin = new BinaryTree<float>(1.53);
	bin->insert(1.33);
	bin->insert(1.72);
	bin->insert(1.75);
	bin->insert(6.37);
	bin->insert(9.39);
	bin->insert(6.51);
	bin->insert(2.00);
	bin->preOrderOut();
	bin->filter([](float data){return (((int)data % 2) == 0);});
	std::cout << "Floats even: " << std::endl;
	std::vector<float> v1 = bin->getV();
	for (float f : v1)
	{
		float y = roundf(f * 100.00f) / 100.00f;
		std::cout << y << " ";
	}
	std::cout << " " << std::endl;

	std::cout << "----------------- Test 4 - BinaryTree with strings manual ------------------" << std::endl;
	// Testing manual strings - Test 4
	std::cout << "BinaryTree<std::string> -> filter(stringsWithS)" << std::endl;
	BinaryTree<std::string> * bin2 = new BinaryTree<std::string>("vrhagwbhi");
	bin2->insert("sxioehfigr");
	bin2->insert("PhiinIOoubUI");
	bin2->insert("JkvucDZDrjeh");
	bin2->insert("HuhIHzdset");
	bin2->insert("NIONUISD");
	bin2->insert("juUTxedSRWs");
	bin2->insert("jipgjoigny");
	bin2->preOrderOut();
	bin2->filter([](std::string data){std::size_t found = ((data.find_first_of("s")) & (data.find_first_of("S"))); return (found != std::string::npos); });
	std::cout << "Strings with s: " << std::endl;
	std::vector<std::string> v2 = bin2->getV();
	for (std::string s : v2)
	{
		std::cout << s << " ";
	}
	std::cout << " " << std::endl;
*/
	std::cout << "Program finished. Press any Key to exit... " << std::endl;
	std::getchar();
	return 0;
}






