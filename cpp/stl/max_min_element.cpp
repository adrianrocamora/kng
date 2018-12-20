#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int>::iterator itMax = std::max_element(v.begin(), v.end());
    std::vector<int>::iterator itMin = std::min_element(v.begin(), v.end());

    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    int idxMax = itMax - v.begin();
    int idxMin = itMin - v.begin();

    std::cout << "Max: " << idxMax << ": " << *itMax << std::endl;
    std::cout << "Min: " << idxMin << ": " << *itMin << std::endl;
}
