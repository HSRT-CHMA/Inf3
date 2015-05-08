#include "MaxProblem.h"

/*Constructor create a new MaxSolution*/
MaxProblem::MaxProblem(){
	solution = new MaxSolution();
}

/*
if the rigth and the left node are Null, than its not directly solvable
and set the maximum with the node value.
*/
void MaxProblem::checkSolvability(Node* node){
	if (node->getRight == nullptr && node->getLeft() == nullptr){
		isDirectlySolvalbe = false;

		solution->setMaximum(node->getData());
	}
}

/*@return the solution*/
MaxSolution* MaxProblem::getSolution(){
	return solution;
}

/*
run as long a node is not null on the right side of the tree
save the lowest node on the right side in "node"
and set the value from the node as the maximum
*/
void MaxProblem::getHighestAndSum(Node* node){
	while (node->getRight() != nullptr){
		node = node->getRight();
	}
	solution->setMaximum(node->getData());
}

/*
destructor
Object is being deleted
*/
MaxProblem::~MaxProblem(){
}
