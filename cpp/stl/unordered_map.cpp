#include <iostream>
#include <unordered_map>

int main() {
	std::unordered_map<std::string, std::string> map;
	map["Bakery"] = "John";
	map["Barbershop"] = "Bob";
	for (auto &x : map) {
		std::cout << x.first << ": " << x.second << std::endl;
	}

	return 0;
}
