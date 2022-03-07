
#include <string>

namespace ariel{

    string nospaces(string input) {
		std::erase(input, ' ');
		std::erase(input, '\t');
		std::erase(input, '\n');
		std::erase(input, '\r');
		return input;
	}  
   	std::string matreg (int a, int b, char c, char d);
    std::string matlong (int a, int b, char c, char d);
    std::string mat (int a, int b, char c, char d);
 
};

 	





