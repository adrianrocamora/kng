#include <iostream>
#include <string>

template<typename ...Values> 
class Tuple{
public:
	Tuple() {};
	~Tuple() {};
};

int main() {
	Tuple<int> basicTuple;
	Tuple<int, std::vector<int>> fancyTuple;
	Tuple<int, std::vector<int>, std::map<std::string,std::vector<int>>> fancierTuple;
	return 0;
}
