#pragma once

#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>


template<typename T>
class InitializerOfArray
{
protected:
	virtual T randomeItem(void);
	T min, max;

public:
	T getMin(){ return min; }
	T getMax(){ return max; }
	virtual void initRandom(std::vector<T> & array);
	virtual void print(const std::vector<T> & array);
	InitializerOfArray(T newMin, T newMax);
};

template<typename T>
InitializerOfArray<T>::InitializerOfArray(T newMin, T newMax) {
	min = newMin;
	max = newMax;
}

template<typename T>
void InitializerOfArray<T>::initRandom(std::vector<T> & array)
{
	for (int index = 0; index < array.size(); ++index) {
		array[index] = randomeItem();
	}
}

template<typename T>
void InitializerOfArray<T>::print(const std::vector<T> & array){
	std::cout << "[";
	for (int index = 0; index < array.size(); ++index) {
		std::cout << array[index] << " ";
	}
	std::cout << "]" << std::endl<<std::endl;
}

template<typename T>
T InitializerOfArray<T>::randomeItem() {
	T result = T((double(std::rand() - 1 / RAND_MAX - 1)) * (max - min + 1) + min);
	return result;
}

