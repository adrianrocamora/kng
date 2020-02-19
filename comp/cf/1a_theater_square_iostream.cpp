// Rectangular shape n x m meters
// Pave with a x a flagstones

#include <cstdint>
#include <iostream>

using namespace std;

int main() {
	int64_t n, m, a;

	cin >> n;
	cin >> m;
	cin >> a;

	//A few cases
	if (a >= n && a >= m) {
		cout << "1" << endl;
		return 0;
	} 

	int64_t mA, nA;
	
	if (m % a == 0) {
		mA = m / a;
	} else {
		mA = m / a + 1;
	}

	if (n % a == 0) {
		nA = n / a;
	} else {
		nA = n / a + 1;
	}

	cout << nA * mA  << endl;
}

