#include <iostream>
#include <string>
#include <fstream> 

int main() 
{
	std::ifstream infile("/usr/share/dict/words");
	std::string currWord;
	while(infile >> currWord) {
		std::cout << currWord << std::endl;
	}
	return 0;
}
