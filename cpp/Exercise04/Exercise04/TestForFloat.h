#ifndef TEST_FOR_FLOAT_HPP_
#define TEST_FOR_FLOAT_HPP_
#include "BinaryTree.h"
#include <vector>
#include <string>
#include <iostream>
#include "GeneratorRandoms.h"
// Class for testing Floats
class TestForFloat : GeneratorRandoms {

protected:

	//Creates tree with random floats
	BinaryTree<float> * b = new BinaryTree<float>();

	//Vector to store the generated floats so that delete can later be tested
	std::vector<float> * items = new std::vector<float>();

public:

	//Constructor for the test
	TestForFloat(BinaryTree<float>*tree);

	/*
	* Method to start test
	* parms: items: number of items to be inserted
	*/
	void initRandom(int min, int max, int items);
};
#endif