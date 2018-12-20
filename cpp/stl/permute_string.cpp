#include <string>
#include <algorithm>
#include <iostream>

int main() {
    std::string str = "aba";
    std::sort(str.begin(), str.end());
    do {
        std::cout << str << std::endl;
    } while (std::next_permutation(str.begin(), str.end()));
}
