#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        if (str.length() == 0) { return res;}
        int numStart = 0;
        int validNumLen = 0;
        bool isPositive = true;
        while (str[numStart] == ' ') { numStart++; }
        if (str[numStart] == '-') {
            isPositive = false;
            numStart++;
        } else if (str[numStart] == '+') {
            isPositive = true;
            numStart++;
        } 
        if (numStart < str.length() && !isdigit(str[numStart])) {
            return 0;
        }
        for (int i = numStart; i < str.length(); i++) {
            if (isdigit(str[i])) {
                numStart = i;
                break;
            }
        }
        for (int i = numStart; i < str.length(); i++) {
            if (isdigit(str[i])) { validNumLen++; }
            else { break; }
        }
        cout << "start " << numStart << "   validNumLen " << validNumLen<< endl;
        for (int i = numStart; i < numStart + validNumLen; ++i) {
           res = res * 10 + str[i] - '0';
            if ((isPositive ? res : -res) < numeric_limits<int>::min()) return numeric_limits<int>::min();
            if ((isPositive ? res : -res) > numeric_limits<int>::max()) return numeric_limits<int>::max();
        }
        return isPositive ? res : -res;
    }
};

int main() {
    Solution sol;
    cout << "\"-+1\"" << "    " <<to_string(sol.myAtoi("-+1")) << endl;
    cout << "\"+1\"" << "    " <<to_string(sol.myAtoi("+1")) << endl;
    cout << "\"1\"" << "    " <<to_string(sol.myAtoi("1")) << endl;
    cout << "\"   1\"" << "    " <<to_string(sol.myAtoi("   1")) << endl;
    cout << "\"   -1\"" << "    " <<to_string(sol.myAtoi("   -1")) << endl;
    cout << "\"+\"" << "    " <<to_string(sol.myAtoi("+")) << endl;

    cout << "\"+\"" << "    " <<to_string(sol.myAtoi("+")) << endl;
}
