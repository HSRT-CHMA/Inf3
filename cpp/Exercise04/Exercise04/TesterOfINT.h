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
	// The container which gets filled with values for the test
	InitializerOfArray<T> * ia;

public:
	/* Getter for current generic vector*/
	std::vector<T> & getArray()
	{
		return *array;
	}
	/* Getter for current generic Array-Initializer*/
	InitializerOfArray<T> & getIA()
	{
		return *ia;
	};
	TesterOfINT(int size, T min, T max);
};

/*
Constructor of this class
In it, a new generic vector of the given size gets created and set, also a new instance of the
InitializerOfArray-class to use its initRandom() on the vector to fill it with random values
Also, the filled container gets printed on the console
*/
template <typename T>
TesterOfINT<T>::TesterOfINT(int size, T min, T max) {
	array = new std::vector<T>(size);
	ia = new InitializerOfArray<T>(min, max);
	ia->initRandom(*array);
	std::cout << "\narray: ";
	ia->print(*array);
}