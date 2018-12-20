#include <iostream>
#include <string>
#include <cstddef>  // std::size_t

int main() {
    //std::string s = " \t\t  ";
    //std::string s = "ab \tx";
    std::string s = " ab \tx\t  ";
    std::string whitespaces (" \t\f\v\n\r");
    std::size_t found; 
    std::cout << "[" << s << "]" << std::endl;
    found = s.find_first_not_of(whitespaces);
    if (found != std::string::npos) {
        s.erase(0, found); 
    } else {
        s.clear();
    }
    std::cout << "[" << s << "]" << std::endl;
    found = s.find_last_not_of(whitespaces);
    if (found != std::string::npos) {
        s.erase(found+1); 
    } else {
        s.clear();
    }
    std::cout << "[" << s << "]" << std::endl;
}
