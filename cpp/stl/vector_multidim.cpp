#include <vector>
#include <iostream>

int main() {
	// Does the following initialize the values to anything?
	std::vector<int> vec(4);
	for (int j = 0; j < vec.size(); j++) {
		std::cout << vec[j] << " ";
	}
	std::cout << std::endl << std::endl;

	std::vector<std::vector<int>> mat(5, std::vector<int>(6,42));
	mat[2][3] = 1;
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[0].size(); j++) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

