#include "stdafx.h"
#include "TestForString.h"
#include <ctime>
#include <string>
#include "GeneratorRandoms.h"
// Tester for String types
/*
* Constructor for TestForString
* parms: tree : tree to be filled
*/
TestForString :: TestForString(BinaryTree<std::string> * tree) {
	b = tree;
}

/*
* Method to start test
* parms: items: number of items to be inserted
*/
void TestForString::initRandom(int min, int max, int items) {
	if (min > max){
		std::cout << "Error : min is bigger than max !!!" << std::endl;
	}
	if (items <1){
		std::cout << "Error : items is smaller than 1 !!!" << std::endl;
	}
	if (min <1){
		std::cout << "Error : min is smaller than 1 it is no regualar string!!!" << std::endl;
	}
	else{
		for (int i = 0; i < items; i++) {
			b->insert(randomString(min, max));
		}
	}
}