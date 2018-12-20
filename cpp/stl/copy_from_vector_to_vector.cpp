#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> v1 = {11, 12, 13, 14, 15, 16};
    std::vector<int> v2 = {17, 18, 19, 20};;
    v1.resize(v1.size() + v2.size());   // Ensure v1 has enough space and pad with zeros
    std::copy(v2.begin(), v2.end(), v1.end() - v2.size());
    for (int x : v1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    // Output:
    //  11 12 13 14 15 16 17 18 19 20 
}
