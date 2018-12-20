#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int tmp = b;
		b = b % a;
		a = tmp;
	}
	return a;
}

int lcm (int a, int b) {
	int c = gcd(a, b);
	return (c == 0) ? 0 : a * b / c;
}

int main() {
	cout << "lcm(12, 18) = " << lcm(12, 18) << endl;
	cout << "lcm(24, 24) = " << lcm(24, 24) << endl;
}
