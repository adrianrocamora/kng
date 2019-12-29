#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v{12,2,5,1,2,5,6,7,3};
    for (auto& x : v) { cout << x << " "; } cout << endl;
    sort(v.begin(), v.end());
    for (auto& x : v) { cout << x << " "; } cout << endl;
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto& x : v) { cout << x << " "; } cout << endl;

}
