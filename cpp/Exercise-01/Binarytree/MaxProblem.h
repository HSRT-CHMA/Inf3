#ifndef MAXPROBLEM_H
#define MAXPROBLEM_H

#include "DivisibleProblem.h"
#include "MaxSolution.h"

/*MaxProblem inherits from DivisibleProblem*/
class MaxProblem : public DivisibleProblem{

protected:
	MaxSolution* solution;

public:
	MaxProblem();
	void checkSolvability(Node* node);
	MaxSolution* getSolution();
	void getHighestAndSum(Node* node);
	~MaxProblem();
};

#endif