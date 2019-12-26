#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void permute_string_rec(string& s, int idx, vector<string>& sol) {
    if (idx == s.length() - 1) {
        sol.push_back(s);
        return;
    }
    for (int i = idx; i < s.length(); i++) {
        swap(s[idx], s[i]);   // Alter it 
        permute_string_rec(s, idx + 1, sol);
        swap(s[idx], s[i]);   // Switch it back
    }
}

void permute_string(string s, vector<string>& sol) {
    permute_string_rec(s, 0, sol);
}

int main() {
    vector<string> solution;
    permute_string("abcd", solution);

    for (auto &s : solution) {
        cout << "  " << s << endl;
    }
}

