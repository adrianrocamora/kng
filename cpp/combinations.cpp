#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n = 4;
    for (int k = 1; k <= n; ++k) {
        cout << n << " choose " << k << endl;
        vector<vector<int>> vv;
        vector<bool> vIdx(n);
        fill(vIdx.begin() + n - k, vIdx.end(), true);
        do {
            vector<int> vCurr;
            for (int i = 0; i < n; ++i) {
                if (vIdx[i]) {
                    cout << i + 1 << " ";
                    vCurr.push_back(i+1);
                }
            }
            vv.push_back(vCurr);
            cout << endl;
        } while (next_permutation(vIdx.begin(), vIdx.end()));
        cout  << endl;
        cout  << endl;
    }
}

