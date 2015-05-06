#include "Print.h"

using namespace std;

void Print::start(void) {
	running = true;
	int num = 0;

	do {
		cout << "Please enter 1 to insert node; " << endl;
		cout << "2 to remove a node; " << endl;
		cout << "3 to search a node; " << endl;
		cout << "4 for in order: ";
		cin >> userInput;
		cout << endl;
		switch (userInput)
		{
		case INSERT:
			cout << "Please insert number: ";
			cin >> num;
			tree.insert(num);
			cout << endl;
			break;
		case REMOVE:
			cout << "Please remove number: ";
			cin >> num;
			tree.remove(num);
			cout << endl;
			break;
		case SEARCH:
			cout << "Pleas search number: ";
			cin >> num;
			tree.search(num);
			cout << endl;
			break;
		case PRINT_IN_ORDER:
			cout << "In Order: ";
			tree.inOrder(tree.getRoot());
			cout << endl;
			break;
		}
		cout << endl;
	} while (running);
}