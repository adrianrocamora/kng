#include <bitset>
#include <iostream>
#include <iostream>
#include <climits>

using namespace std;

int main() {
    // empty constructor
    //bitset<8> b1;   // [0,0,0,0,0,0,0,0]
    //cout << b1 << endl;

    //unsigned long long constructor
    for (int i = 0; i < 32; i++) {
        bitset<5> b2(i);   // [0,0,1,0,1,0,1,0]
        cout << b2 << endl;
    }

    //bitset<8> b2(42);   // [0,0,1,0,1,0,1,0]
    //for (int i = 0; i < b1.size(); ++i) {
        //cout << b1[i];
    //}
    //cout << endl;

    //cout << b2 << endl;
    //for (int i = b2.size() - 1; i >= 0; --i) {
        //cout << "Robot: " << b2[i] << endl;;
    //}
    //cout << endl;
    
}
