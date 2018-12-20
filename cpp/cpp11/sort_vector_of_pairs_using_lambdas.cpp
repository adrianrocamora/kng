#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
	std::vector<std::pair<std::string,int>> pair_vec{{"John", 29}, {"Anni", 25}, {"Nadine", 30}};
	for (auto &p : pair_vec) {
		std::cout << p.first << ": " << p.second << std::endl;
	}
	std::cout << "Sorting vector of pairs" << std::endl;
	sort(pair_vec.begin(), pair_vec.end(), [](const std::pair<std::string,int>& a, const std::pair<std::string,int>& b) {
		return a.second < b.second;
	});
	for (auto &p : pair_vec) {
		std::cout << p.first << ": " << p.second << std::endl;
	}
}

