#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2(v1.begin(), v1.begin() + v1.size()/2);
    for (int x : v1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (int x : v2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
