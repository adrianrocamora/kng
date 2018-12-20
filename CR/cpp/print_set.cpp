#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

bool index_is_enabled(int flags, int idx) {
    int tmp =  (1 << idx);
    if ((tmp & flags) == 0) { return false; } // Careful with parens and bitwise operators!
    else { return true;}
}

void print_subsets(const vector<int>& v, vector<unordered_set<int>>& s) {
    // Bits from 0 to pow(size)
    int subset_total = pow((double)2.0, (double)v.size());
    cout << subset_total << endl;
    for (int i = 0; i < subset_total; i++) {
        unordered_set<int> out;
        for (int j = 0; j < v.size(); j++) { // Iterate over indices
            if (index_is_enabled(i, j)) { 
                out.insert(v[j]);
            }
        }
        s.push_back(out);
    }
}

int main() {
    vector<int> v{2,3,4,5};
    vector<unordered_set<int>> sol;
    print_subsets(v, sol);
    cout << sol.size() << endl;;
    int count = 0;
    for (auto& s : sol) {
        cout << "Set " << count << ": ";
        for (auto& x : s) {
            cout << " " << x;
        }
        cout << endl;
        count++;
    }
}

