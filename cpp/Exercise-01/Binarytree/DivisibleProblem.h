#ifndef DIVISIBLEPROBLEM_H
#define DIVISIBLEPROBLEM_H

#include "Problem.h"
#include "SumSolution.h"
#include "MaxSolution.h"
#include "Tree.h"
#include <iostream>

/*DivisibleProblem inherits from Problem*/
class DivisibleProblem : public Problem{

protected:
	bool isDirectlySolvalbe = false;
	Tree* tree = nullptr;

public:
	/*abtract*/
	virtual void checkSolvability(Node* node); 
	virtual void getHighestAndSum(Node* node);
	virtual void calculateSolution();

	/*set a new Tree*/
	void setTree(int value){
		tree = new Tree;
	}

	/*@return the Tree*/
	Tree* getTree(){
		return tree;
	}

	/*abstract*/
	/*virtual void calculateSolution();*/

};



#endif 