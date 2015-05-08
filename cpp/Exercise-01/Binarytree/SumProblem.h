#ifndef SUMPROBLEM_H
#define SUMPROBLEM_H

#include "DivisibleProblem.h"
#include "SumSolution.h"

/*SumProblem inherits from DivisbleProblem*/
class SumProblem : public DivisibleProblem{

protected:
	SumSolution* solution;
	void checkSolvability();
	int getSumRecursion(Node* node);
	void getHighestAndSum(Node* node);

public:
	int getSumRecursion(Node* node);
	SumSolution* getSolution();
	void checkSolvability(Node* node);
	SumProblem();

	/*abstract*/
	virtual~SumProblem();
};

#endif