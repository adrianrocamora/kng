#include <random>
#include <iostream>

using namespace std;

int main() {
	default_random_engine g(random_device{}());
	uniform_real_distribution<double> d(5.0, 6.0);
	for (int i = 0; i < 4000; ++i) {
		cout << d(g) << " " << endl;
	}
}

