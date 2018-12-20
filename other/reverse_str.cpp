#include <iostream>
#include <algorithm>
#include <string>

using namespace std::string_literals;

void reverseStrRec(std::string& s, int idxBeg, int idxEnd) {
    if (idxBeg >= idxEnd) {
        return;
    }
    std::swap(s[idxBeg], s[idxEnd]);
    reverseStrRec(s, ++idxBeg, --idxEnd);
}
void reverseStr(std::string& s) {
    reverseStrRec(s, 0, s.length()-1);
}

int main() {
    std::string s = "Hello"s;
    reverseStr(s);
    std::cout << s << std::endl;
}
