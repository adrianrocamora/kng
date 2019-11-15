#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<std::vector<int>> generate(int numRows) {
		std::vector<std::vector<int>> res;
		for (int i = 0; i < numRows; i++) {
			std::vector<int> tmp;
			int numCols = i+1; 
			for (int j = 0; j < numCols; j++) {
				if (j == 0 || j == numCols - 1) {
					tmp.push_back(1);
				} else {
					tmp.push_back(res[i-1][j-1]+res[i-1][j]);
				}
			}
			res.push_back(tmp);
		}
		return res;
	}
};

int main() {
	Solution sol;
	for (auto &i : {0,1,2,3,4,12}) {
		for (auto &v : sol.generate(i)) {
			for (auto &x : v) {
				std::cout << x << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}
