#pragma once
#include <string>
#include <vector>

class TesterOfString
{
protected:
	std::string randomStrings();
	std::vector<std::string> * stringArray = new std::vector<std::string>();
	int min;
	int max;
	int size;

public:
	int getMin(){ return min; }
	int getMax(){ return max; }
	TesterOfString(int size, int min, int max);
	void print();
	void initRandomeStrings();
};

