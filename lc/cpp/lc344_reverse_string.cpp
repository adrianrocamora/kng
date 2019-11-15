#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        for (int i = 0; i < s.length()/2; ++i) {
            swap(s[i], s[s.length() - i - 1]);
        }
        return s;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseString("Hello") << endl;
}
