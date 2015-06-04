#pragma once

#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>


template<typename T>
class InitializerOfArray
	// This class organises the creation of an array and fills it with random values 
{
protected:
	virtual T random_i(void);
	// Returns ramdom generic values to fill given vectors
	T min, max;
	// Borders of array

public:
	/* Getters for min and max values*/
	T getMin()
	{ 
		return min; 
	}
	T getMax()
	{ 
		return max; 
	}
	virtual void initRandom(std::vector<T> & array);
	virtual void print(const std::vector<T> & array);
	InitializerOfArray(T newMin, T newMax);
};

/* Constructor which receives two border-values*/
template<typename T>
InitializerOfArray<T>::InitializerOfArray(T newMin, T newMax) {
	min = newMin;
	max = newMax;
}

/* 
This method receives a generic vector and fills it with random-values of the same generic type 
by using the random_i() method and size()
*/
template<typename T>
void InitializerOfArray<T>::initRandom(std::vector<T> & array)
{
	for (int index = 0; index < array.size(); ++index) {
		array[index] = random_i();
	}
}

/* This method prints the content of the current generic value */
template<typename T>
void InitializerOfArray<T>::print(const std::vector<T> & array){
	std::cout << "[";
	for (int index = 0; index < array.size(); ++index) {
		std::cout << array[index] << " ";
	}
	std::cout << "]" << std::endl<<std::endl;
}

/* 
This method returns a single value of the given generic type, which is selected randomly 
by using std::rand() and an typecast to the specific type currently used
*/
template<typename T>
T InitializerOfArray<T>::random_i() {
	T result = T((double(std::rand() - 1 / RAND_MAX - 1)) * (max - min + 1) + min);
	return result;
}

