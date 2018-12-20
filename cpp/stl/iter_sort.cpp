#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::sort(v.rbegin(), v.rend());
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::sort(v.begin(), v.end());
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
