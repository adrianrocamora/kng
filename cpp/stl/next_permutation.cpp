#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3};  // NOTE: It must be sorted
    do {
        for (auto x : v) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(v.begin(), v.end()));
}
// Output: 
// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1 
