#include "SumProblem.h"
#include <cassert>
#include <cstdlib>

/*Constructor create a new SumSolution*/
SumProblem::SumProblem(){
	solution = new SumSolution();
}

/*
if the node ist not null
sums all nodes from the left side of the Tree and the right side of the tree and
@return the sum
*/
int SumProblem::getSumRecursion(Node* node){
	int sum = 0;
	if (node != nullptr){
		sum += node->getData() + getSumRecursion(node->getLeft()) + getSumRecursion(node->getRight());
	}
	return sum;
}

/*
if the rigth and the left node are Null, than its not directly solvable
and set the sum
*/
void SumProblem::checkSolvability(Node* node){
	if (node->getRight() == nullptr && node->getLeft() == nullptr){
		isDirectlySolvalbe = false;
		solution->setSum(node->getData());
	}
}

/*@return the solution of SumProblem*/
SumSolution* SumProblem::getSolution(){
	return solution;
}

/*set the sum of the getSumRecursion with the param node*/
void SumProblem::getHighestAndSum(Node* node){
	solution->setSum(this->getSumRecursion(node));
}