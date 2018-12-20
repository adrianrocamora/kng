#include <iostream>
#include <algorithm>
#include <string>

inline std::string trim(const std::string &s)
{
   auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c){return std::isspace(c);});
   auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c){return std::isspace(c);}).base();
   return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
}

int main() {
    std::string s = " ab \tx\t  ";
    std::cout << "\"" << s << "\"" << std::endl;
    s = trim(s);
    std::cout << "\"" << s << "\"" << std::endl;
}
//Output:
//" ab 	x	  "
//"ab 	x"
