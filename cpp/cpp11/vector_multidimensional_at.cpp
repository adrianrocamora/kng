#include <iostream>
#include <vector> 

int main() {
    std::vector<std::vector<int>> mat(5, std::vector<int>(6));
    //mat[2][3] = 1;		// Unsafe
    mat.at(2).at(3) = 1;	// Better: throws std::out_of_range exception if it goes out of the defined range
    for (auto &v : mat) {
        for (int x : v) {
            std::cout << x << " " ;
        }
        std::cout << std::endl;
    }
}
