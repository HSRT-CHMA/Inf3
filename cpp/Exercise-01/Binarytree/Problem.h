#ifndef PROBLEM_H
#define PROBLEM_H
#include "Solution.h"

class Problem{
public:
	/*abstract*/
	virtual Solution & getSolution() const = 0;
};

#endif