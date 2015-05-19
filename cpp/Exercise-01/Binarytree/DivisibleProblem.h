#ifndef DIVISIBLEPROBLEM_H
#define DIVISIBLEPROBLEM_H

#include "Problem.h"
#include "SumSolution.h"
#include "MaxSolution.h"
#include "Tree.h"
#include <iostream>

/*DivisibleProblem inherits from Problem*/
template<Solution>
class DivisibleProblem : public Problem<Solution>{

protected:
	bool isDirectlySolvalbe;
	Tree* tree = nullptr;

public:
	/*abtract*/
	virtual void checkSolvability(Node* node) = 0; 
	virtual void getHighestAndSum(Node* node) = 0;
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