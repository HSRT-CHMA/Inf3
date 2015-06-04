#pragma once


#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>

#include "InitializerOfArray.h"

template <typename T>
class TesterOfINT
{
protected:
	std::vector<T> * array;
	InitializerOfArray<T> * ia;

public:
	std::vector<T> & getArray() { return *array; }
	InitializerOfArray<T> & getIA() { return *ia; };
	TesterOfINT(int size, T min, T max);
};


template <typename T>
TesterOfINT<T>::TesterOfINT(int size, T min, T max) {
	array = new std::vector<T>(size);
	ia = new InitializerOfArray<T>(min, max);
	ia->initRandom(*array);
	std::cout << "\narray: ";
	ia->print(*array);
}