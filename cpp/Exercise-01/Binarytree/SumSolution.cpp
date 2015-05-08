#include "SumSolution.h"
#include <cassert>

/*set the sum*/
void SumSolution::setSum(int sum){
	assert(sum <= 0 || sum >= 0);
	this->sum = sum;
}

