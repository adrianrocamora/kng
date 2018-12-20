#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::unordered_map<std::string,int> m = {{"uno", 1.0}, {"dos", 2.0}, {"tres", 3.0}};
    std::vector<std::pair<std::string, int>> v(m.begin(), m.end());
    for (auto& p : v) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    // Output: 
    //  tres: 3
    //  uno: 1
    //  dos: 2
    std::sort(v.begin(), v.end());
    for (auto& p : v) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    // Output:
    // dos: 2
    // tres: 3
    // uno: 1
}
