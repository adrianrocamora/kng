#include <random>
#include <vector>
#include <iostream>

int main() {
    vector<int> v{1,2,3,4,5,6,7,8};
    default_random_engine re;
    shuffle(v.begin(), v.end(), re());
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}
