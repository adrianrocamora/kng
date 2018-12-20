// rock.h
//
// Just a bunch of useful #defines, typedefs and functions
//

#pragma once
#include <vector>

typedef long long		ll;
typedef pair<int, int>	ii;
typedef vector<ii>		vii;
typedef vector<int>		vi;
typedef set<int>		si;
typedef map<string,int>	msi;

#define INF				1000000000

// Repetition simplification
#define REP(i, a, b) \
	for (int i = int(a); i <= int(b); i++)
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
	for (msi::iterator it = (c).begin(); it != (c).end(); it++)


// Initialize DP memoization table with -1
//memset(memo, -1, sizeof memo);

// Clear array of integers
//memset(arr, 0, sizeof arr);



