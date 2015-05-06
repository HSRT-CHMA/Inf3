#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <istream>

#include "Tree.h"

class Print {
private:
	bool running;
	int userInput;

	enum {
		INSERT = 1,
		REMOVE = 2,
		SEARCH = 3,
		PRINT_IN_ORDER
	};

	Tree tree;
public:
	Print(){
		running = false;
		userInput = 0;
	}

	void quit(void) {
		running = false;
	}

	void start(void);
};

#endif