#include <iostream>
#include "Tree.h"
#include "MaxProblem.h"
#include "MaxSolution.h"
#include "SumProblem.h"
#include <cassert>

using namespace std;

template<MaxSolution>
int main() {
/*	Tree tree;

	tree.insert(12);
	tree.insert(19);
	tree.insert(11);
	tree.insert(5);
	tree.insert(32);
	tree.insert(7);
	tree.insert(18);
	tree.insert(4);
	tree.insert(9);
	tree.insert(4);

	tree.inOrder(tree.getRoot());

	cout << endl;

	tree.remove(4);

	tree.inOrder(tree.getRoot());

	cout << endl;

	tree.search(9);

	cout << endl;

	tree.search(100);*/
	
	MaxProblem max = new MaxProblem();;
	max->setTree(10);
	max.getTree()->insert(12);
	max.calculateSolution();
	cout << "MaxSolution:" << max.getSolution()->getMaximum() << endl;

	SumProblem sum;
	sum.setTree(4);
	sum.getTree()->insert(2);
	sum.getTree()->insert(3);
	sum.getTree()->insert(6);

	sum.calculateSolution();
	cout << "SumSolution:" << sum.getSolution()->getSum() << endl;

	Tree b(8);
	Tree b2(2);
	for (int i = 0; i <= 15; i++)
	{
		b.insert(i);
	}
	assert(b.getBiggest() == 15);
	assert(b.getSmallest() == 0);
	assert(b.getRoot() == b2.getRoot());

	b.inOrder(b.getRoot());
	cout << endl;
	b.remove(10);
	b.inOrder(b.getRoot());

	cin.get();

	return 0;
}