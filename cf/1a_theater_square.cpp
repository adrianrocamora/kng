// Rectangular shape n x m meters
// Pave with a x a flagstones

#include <stdio.h>
#include <inttypes.h>

// Use this:
//	printf("%I64d\n",n);
// Instead of this:
//	printf("%lld\n",n);

int main() {
	int64_t n, m, a;

	scanf("%" PRId64 "%" PRId64 "%" PRId64, &n, &m, &a);

	//A few cases
	if (a >= n && a >= m) {
		printf("1\n");
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

	printf("%" PRId64 "\n", (nA) * (mA));
}

