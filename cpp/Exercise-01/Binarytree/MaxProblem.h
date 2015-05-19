#ifndef MAXPROBLEM_H
#define MAXPROBLEM_H

#include "DivisibleProblem.h"
#include "MaxSolution.h"

/*MaxProblem inherits from DivisibleProblem*/
template<MaxSolution>
class MaxProblem : public DivisibleProblem<MaxSolution>{

protected:
	MaxSolution* solution;

public:
	MaxProblem();
	void checkSolvability(Node* node);
	MaxSolution* getSolution();
	void getHighestAndSum(Node* node);
};

#endif