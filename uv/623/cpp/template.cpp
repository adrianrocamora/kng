// 500!, UVa 623
#include <iostream>	
#include <cmath>	
#include <algorithm>	
#include <cstdio>	
#include <cstring>	
#include "gmpxx.h"	

typedef mpz_class Big;

using namespace std;


int main()
{
	char line[1000];
	int i, j, caseNo = 1, x[20], y[20];
	// For redirecting input file to stdin
	//freopen("10911.txt", "r", stdin);

	int N;		// N does not exceed 1000
	Big fact;
	cin >> N;
	// Exit the routing by entering a negative integer
	// There is no extension by Gamma Function support yet ;)
	while (N>=0) {
		fact = 1;
		
		for (int i = 1; i <= N; i++) {
			fact = fact * i;
		}

		cout << fact << endl;

		cin >> N;
	}

	return 0;
}
