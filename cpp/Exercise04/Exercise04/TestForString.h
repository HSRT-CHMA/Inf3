#ifndef TEST_FOR_STRING_HPP_
#define TEST_FOR_STRING_HPP_
#include "BinaryTree.h"
#include "GeneratorRandoms.h"	
#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>
// Class to test Strings
class TestForString : GeneratorRandoms
{

protected:

	//Creates tree with random strings
	BinaryTree<std::string> * b = new BinaryTree<std::string>();

	//Vector to store the generated strings so that delete can later be tested
	std::vector<std::string> * items = new std::vector<std::string>();

public:

	//Constructor for the test
	TestForString(BinaryTree<std::string> * tree);

	/*
	* Method to start test
	* parms: items: number of items to be inserted
	*/
	void initRandom(int min, int max, int items);
};
#endif