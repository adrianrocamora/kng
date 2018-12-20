#include <iostream>
#include <unordered_map>
#include <string>

int main() {
	std::unordered_map<std::string, int> map1;
	std::unordered_map<std::string, int> map2 = {{"John", 29},{"Pedro", 25} };
	std::cout << ((map1.empty()) ? "Is empty" : "Isn't empty") << std::endl;
	for (auto& x : map1) { 
		std::cout << x.first << ": " << x.second << std::endl;
	}
	std::cout << ((map2.empty()) ? "Is empty" : "Isn't empty") << std::endl;
	for (auto& x : map2) { 
		std::cout << x.first << ": " << x.second << std::endl;
	}
}



