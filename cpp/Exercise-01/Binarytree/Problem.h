#ifndef PROBLEM_H
#define PROBLEM_H
#include "Solution.h"

template<Solution>
class Problem<Solution>{
public:
	/*abstract*/
	virtual Solution & getSolution() const = 0;
};

#endif