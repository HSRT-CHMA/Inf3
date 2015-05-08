#ifndef MAXSOLUTION_H
#define MAXSOLUTION_H

class MaxSolution{
protected:
	int max;

public:
	/*abstract*/
	virtual void setMaximum(int max);

	/*@return the maximum*/
	int getMaximum(){
		return max;
	}
};

#endif
