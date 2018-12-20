// Generate primes given two numbers

#include <stdio.h>
#include <math.h>

// Global list of primes
// 0 unknown
// 1 prime
// 2 composite
// Large enought to hold 1 billion primes
// 1 based to simplify calculations
char primeList[1100000000];
// Use last gen index?

bool sieve[1100000000];
#define MAX 1000000000
long prime[1100000000];
void genSieve() {
	long i, j, primecount = 0L;
 
	for (i = 0L; i < MAX; i++)
		sieve[i] = true;
	sieve[0] = sieve[1] = false;
	for (i = 2L; i < MAX; i++) {
		if (!sieve[i])
			continue;
		prime[primecount++] = i;
		for (j = i * i; j < MAX; j += i)
			sieve[j] = false;
	}
	for (i = 0L; i < primecount; i++)
		printf("%ld\n", prime[i]);
}

void genPrime(long maxP) {
	// Check the stored array
	//if (primeList[maxP] == 0) {
		//// Generate the array with this maximum
	//}

	long breakNum = ceil(sqrt(maxP));

	//primeList[2] = 1;	
	//printf("%ld\n", 2L);
	for (long i = 2; i <= maxP; i++) {
		if (primeList[i] == 0) {
			// It's a prime
			primeList[i] = 1;	
			// Print the prime
			printf("%ld\n", i);
		}
		else
		{
			// It wasn't a prime
			primeList[i] = 2;	
			continue;
		}

		if (i <= breakNum) {
			for (long j = 2; j*i <= maxP; j++) {
				primeList[j*i] = 2;
			}
		}

	}
}

int main() {
	int maxPrime;
	//scanf("%d\n", &maxPrime);
	genPrime(1000000000);
	//genSieve();

	//printf("%d => %d\n", 31, primeList[31]);
	//printf("%d => %d\n", 121, primeList[121]);

	return 0;
}

