#include "MaxSolution.h"
#include <cassert>

/*set the maximum*/
void MaxSolution::setMaximum(int max){
	assert(max <= 0 || max >= 0);
	this->max = max;
}


