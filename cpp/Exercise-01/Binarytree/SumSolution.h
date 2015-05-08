#ifndef SUMSOLUTION_H
#define SUMSOLUTION_H

class SumSolution{
protected:
	int sum;

public:
	/*abstract*/
	virtual void setSum(int sum);

	/*@return the sum*/
	int getSum(){
		return sum;
	}
};

#endif