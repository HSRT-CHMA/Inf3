#ifndef GENERATOR_RANDOMS_HPP_
#define GENERATOR_RANDOMS_HPP_
#include <string>
#include <stdio.h>
// class to generate Random floats and ints
class GeneratorRandoms{

protected:
	/*
	* Returns random float
	* parms: min: The minimum value for randomized float
	*        max: The maximum value for randomized float
	*/
	virtual float randomFloat(int min, int max);

	/*
	* Returns a random string
	* parms: min: The minimum length for randomized string.
	*        max: The maximum length for randomized string
	*/
	virtual std::string randomString(int minLength, int maxLength);


	//The constructor for GeneratorRandoms
	GeneratorRandoms();
};
#endif
