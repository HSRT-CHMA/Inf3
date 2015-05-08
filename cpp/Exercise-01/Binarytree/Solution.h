#pragma once	/*no more header, like upper class*/

class Solution{

protected:
	Solution* solution;
	/*set the Solution*/
	void Solution::setSolution(Solution* solution){
		this->solution = solution;
	}

public:
	/*@return the solution*/
	Solution* Solution::getSolution(){
		return solution;
	}
};