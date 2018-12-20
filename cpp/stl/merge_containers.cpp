#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v1 = {   1, 2,       5, 6,    8, 9, 10};
    std::vector<int> v2 = {0,    2, 3, 4,       7, 8,    10};
    std::vector<int> tmp(std::max(v1.size(), v2.size()));
    //std::vector<int> res = std::vector<int>(tmp.begin(), std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), tmp.begin()));
    std::vector<int> res(tmp.begin(), std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), tmp.begin()));

    for (int x : v1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (int x : v2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (int x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
