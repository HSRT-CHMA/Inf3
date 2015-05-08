#include "DivisibleProblem.h"


/**/
void DivisibleProblem::calculateSolution(){
	checkSolvability(tree->getRoot());
	if (isDirectlySolvalbe){
		printf("directlySolvable is true!");
	}
	else{
		getHighestAndSum(tree->getRoot());
	}
}

