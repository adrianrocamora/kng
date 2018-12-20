#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

double square_root(double x) {
    double low = 0;
    double high = x/2 + 1; // TODO: optimize
    double eps = 0.00001;

    while (true) {
        double mid = (low + high) / 2;
        if (abs(x - mid*mid) <= eps) { 
            return mid;
        }
        if (x < mid*mid) { 
            high = mid;
        } else {
            low = mid;
        }
    }
}

int main() {
    cout << "sqrt(0): " << square_root(0) << endl;
    cout << "sqrt(1): " << square_root(1) << endl;
    cout << "sqrt(2): " << square_root(2) << endl;
    cout << "sqrt(3): " << square_root(3) << endl;
    cout << "sqrt(4): " << square_root(4) << endl;
    cout << "sqrt(5): " << square_root(5) << endl;
    cout << "sqrt(6): " << square_root(6) << endl;
    cout << "sqrt(7): " << square_root(7) << endl;
    cout << "sqrt(8): " << square_root(8) << endl;
}   
