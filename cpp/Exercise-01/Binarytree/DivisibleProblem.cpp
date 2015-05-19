#include "DivisibleProblem.h"


/**/
template<Solution>
void DivisibleProblem::calculateSolution(){
	while (true){
		checkSolvability(tree->getRoot());
		checkSolvability(tree->getRoot());
		if (isDirectlySolvalbe){
			printf("directlySolvable is true!");
		}
		else{
			getHighestAndSum(tree->getRoot());
		}
	}
}

