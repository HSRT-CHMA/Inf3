#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "TestForFloat.h"
#include <ctime>
#include <vector>
#include <random>
#include "GeneratorRandoms.h"
// Tester for Float Types
/*
* Constructor for TestForFloat
* parms: tree: tree to be filled
*/
TestForFloat :: TestForFloat(BinaryTree<float> * tree) {
	b = tree;
}

/*
* Method to start test
* parms: items: number of items to be inserted
*/
void TestForFloat::initRandom(int min, int max, int items) {
	if (min > max){
		std::cout << "Error : min is bigger than max !!!" << std::endl;
	}
	if (items <1){
		std::cout << "Error : items is smaller than 1 !!!" << std::endl;
	}
	else{
		for (int i = 0; i < items; i++) {
			b->insert(randomFloat(min, max));
		}
	}
}