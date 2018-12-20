#include <cmath>
#include <iostream>
#include <cstdint>

using namespace std;

uint64_t getMinDivisor(uint64_t num) {
	long breakNum = ceil(sqrt(num));
	if (num == 2) { return num;}
	for (uint64_t i = 2; i <= breakNum; i++) {
		if (num % i == 0) {
			return i;
		}
	}
	return num;
}

int main() {
	int maxPrime;
	for (uint64_t i = 2; i <= 50; ++i) {
		cout << i << ((getMinDivisor(i) == i) ? " Prime " : " Not Prime ") << getMinDivisor(i) << endl;;
	}
	uint64_t other = 1'000'101'010'010'101;
	cout << other << ((getMinDivisor(other) == other) ? " Prime " : " Not Prime ")  << getMinDivisor(other) << endl;;
	return 0;
}

