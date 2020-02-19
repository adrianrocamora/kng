// Forming quiz teams, UVa 10911

#include <algorithm>	
#include <iostream>	
#include <cmath>	
#include <cstdio>	
#include <cstring>	

const double INF = 2000000000.0;

int N; 
double dist[20][20], memo [1 << 16];

// DP state
double matching(int bitmask) {
	// initialize the array with -1 in the main function
	if (memo[bitmask] > -0.5) {
		return memo[bitmask];
	}
	if (bitmask == (1 << (2 *N)) - 1) {
		return memo[bitmask] = 0;
	}

	double ans = INF;
	for (int p1 = 0; p1 < 2 * N; p1++) {
		if (!(bitmask & (1 << p1))) {
			for (int p2 = p1 + 1; p2 < 2*N; p2++) {
				if (!(bitmask & (1 << p2))) {
					ans = std::min(
						ans,
						dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2))
						);
				}
			}
			break;
		}

	}
	return memo[bitmask] = ans;
}

int main()
{
	using namespace std;
	char line[1000];
	char name[1000];
	int i, j, caseNo = 1, x[20], y[20];

	// For redirecting input file to stdin
	freopen("10911.txt", "r", stdin);

	// Use scanf to read the input line by line
	//while (sscanf(gets(line), "%d", &N), N) {
	while (sscanf(gets(line),"%d\n", &N), N) {
		for (i = 0; i < 2 * N; i++) {
			sscanf(gets(line), "%s %d %d", &name, &x[i], &y[i]);
			//cout << name << endl;
		}

		//std::cout << name[2*N] << std::endl;

		for (i = 0; i < 2 * N; i++) {
			for (j = 0; j < 2 * N; j++) {
				dist[i][j] = hypot((double)x[i] - x[j], (double)y[i] - y[j]);
			}
		}

		// Use DP to solve minimum weighted perfect matching on small general 
		// graph
		// Initialize memo table
		memset(memo, -1, sizeof memo);
		printf("Case %d: %.2lf\n", caseNo++, matching(0));
	}
	return 0;
}
