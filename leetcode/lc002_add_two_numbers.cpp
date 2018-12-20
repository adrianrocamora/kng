// Generate primes given two numbers
#include <stdio.h>
#include <string.h>
#include <math.h>

// Runtime with clang++ is at least 6.4 s with supplied input sample

// Global list of primes
// 0 unknown
// 1 prime
// 2 composite
// Large enought to hold 1 billion primes
// Since it's global it's automatically initialized to 0
char primeList[1000000100];
long maxMaxP = 1;

// This might be more efficient
// Use trial division to see if the number is prime
// Using the number theory theorem that primes are of the 
// form 6k +- 1, excepting 2 and 3
// we can iterate through this efficiently
bool isPrime(long num)
{
	bool res = true;
	//Add memoization
	//If we know the result return the appropriate value
	// This improved performance, but it's highly dependent on
	// the input. 
	// +++ It might make sense to go over all the input values (only 10)
	// and grab the global smallest and largest, create the table for those
	// and solve the problem

	if (primeList[num] == 1) {
		return true;
	}
	else if (primeList[num] == 2) {
		return false;
	}
	// If it's none of these compute and store the result

	//Naive approach
	//Test divisibility up to num - 1
	if (num == 1L) {
		res = false;
	}

	if (num % 2L == 0 || num % 3L == 0) {
		res = false;
	}
	else {
		long maxLim = sqrt(num);

		//6k -+ 1

		long primeTest = 0L;
		//for (long k = 1L; primeTest < num; k++) {

		long k = 1L;
		while (primeTest < num) {
			primeTest = 6L*k - 1L;
			if (k > maxLim) {
				break;
			}
			if (num % primeTest == 0) {
				res = false;
				break;
			}

			primeTest = 6L*k + 1L;
			if (k > maxLim) {
				break;
			}
			if (num % primeTest == 0) {
				res = false;
				break;
			}
			k = k + 1L;
		}
	}
	// Store in DP table
	primeList[num] = res; 

	return res;
}

int main() {
	int numTest;
	scanf("%d\n", &numTest);
	long m, n;
	while(numTest) {
		//print primes between m and n
		scanf("%ld %ld\n", &m, &n);
		for (long i = m; i <= n; i++) {
			if (isPrime(i)) {
				printf("%ld\n", i);
			}
		}
		numTest--;
		if (!numTest) {
			break;
		}
		printf("\n");
	}
	return 0;
}
