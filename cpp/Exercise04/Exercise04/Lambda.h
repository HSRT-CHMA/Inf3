#ifndef LAMDA_HPP_
#define LAMDA_HPP_

#include <string>
#include <stdio.h>
#include "iostream"
template<typename T>
class Lambda{

	Lambda(std::string s){
		if (s == "even" | s == "Even"){
			stp::function = [](float data){return (((int)data % 2) == 0) && ((data - (int)data) == 0); };
		}
	    if (s == "negativ" | s == "Negativ"){
			this->[](float data){return (data < 0); };
		}
		if (s == "smallerequalsfive" | s == "SmallerEqualsFive"){
			this->[](float data){return (data <= 5); };
		}
		if (s == "longerequalsthree" | s == "LongerEqualsThree"){
			this->[](std::string data){return (data.length() >= 3); };
		}
		if (s == "stringwiths" | s == "StringWithS"){
			this->[](std::string data){std::size_t found = data.find_first_of("s"); return (found != std::string::npos); };
		}
		else{
			std::cout << "None correct Lamda detected retry" << std::endl;
			std::cin.get();
		}
	}

};
#endif