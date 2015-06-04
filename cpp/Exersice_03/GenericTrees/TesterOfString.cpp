#include "stdafx.h"

#include <iostream>
#include "TesterOfString.h"
#include "AVLTree.h"
#include <string>
TesterOfString::TesterOfString(int size, int min, int max) {
	this->min = min;
	this->max = max;
	this->size = size;
	this->initRandomeStrings();
}

std::string TesterOfString::randomStrings() {
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789";
	int length = std::rand() %5 + max;
	std::string result = "";

	for (int i = 0; i < length; i++) {
		result += alphabet[std::rand() % 52];
	}
	return result;
}

void TesterOfString::initRandomeStrings() {
	AVLTree<std::string> * test = new AVLTree<std::string>(randomStrings());
	for (int index = 0; index < size; ++index) {
		stringArray[index].push_back(randomStrings());
		test->insert(stringArray->back());
		std::cout <<std::endl <<"Has " << stringArray->back() << ": " << std::boolalpha << test->hasElement(stringArray->back()) << std::endl;
		test->printTree();
		std::cout << std::endl;

	}
}



void TesterOfString::print() {
	std::cout << "[";
	for (int index = 0; index < size; ++index) {
		std::cout << stringArray[index].back() << " ";
	}
	std::cout << "]" << std::endl << std::endl;
}