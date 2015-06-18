#include "stdafx.h"
#include "GeneratorRandoms.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <random>
#include <string>
#pragma once
// Creating random floats and Strings
/*
* Returns random float
* parms: min: The minimum value for randomized float
*        max: The maximum value for randomized float
*/
float GeneratorRandoms::randomFloat(int min, int max)
{
	float tmp = 0;
	float r3 = min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
	tmp = r3;
	tmp = (float)((int)tmp * 62) / 100;

	return tmp;
}

/*
* Returns random string
* parms: min: The minimum length for randomized string
*        max: The maximum length for randomized string
*/
std::string GeneratorRandoms::randomString(int minLength, int maxLength)
{
	std::string alphanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int len = rand() % maxLength + minLength;
	std::string s = "";
	for (int i = 0; i < len - 1; i++) {
		s += alphanum[rand() % 50];
	}
	return s;
}

// Constructor for GeneratorRandoms
GeneratorRandoms::GeneratorRandoms(){

}