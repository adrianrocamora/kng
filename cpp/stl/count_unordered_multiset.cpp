#include <string>
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<std::string> ums = {"dog", "pig", "dog"};
    for (auto& s : {"cat", "dog", "pig"}) {
        std::cout << s << ": " << ums.count(s) << std::endl;
    }
    
}
