#include <stdio.h> 
#include <algorithm> 
#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <cmath> 
#include <set> 
#include <string> 
#include <map> 
#include "gmpxx.h"

using namespace std;

typedef long long				ll;
typedef std::pair<int, int>		ii;
typedef std::vector<ii>			vii;
typedef std::vector<int>		vi;
typedef std::vector<long>		vl;
typedef std::vector<ll>		vll;
typedef std::set<int>			si;
typedef std::map<string,int>	msi;

#define INF				1000000000

// Repetition simplification
#define REP(i, a, b) \
	for (int i = int(a); i <= int(b); i++)
#define TRvl(c, it) \
	for (vl::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
	for (msi::iterator it = (c).begin(); it != (c).end(); it++)

//DO NOT UNCOMMENT! REFERENCE ONLY

////Initialize DP memoization table with -1
//memset(memo, -1, sizeof memo);

////Clear array of integers
//memset(arr, 0, sizeof arr);

////Substr
//std::string str="We think in generalities, but we live in details.";
//std::string str2 = str.substr (12,12);   // "generalities"
//std::size_t pos = str.find("live");      // position of "live" in str
//std::string str3 = str.substr (pos);     // get from "live" to the end

const int MAX_ITEMS = 810;
const int MAX_LINES = 200;

typedef mpz_class big;
typedef mpf_class bigf;

int main()
{
	// Number of entries in data file
	int numEntries = 0;

	big resOut;
	bigf res;

	// Outputs go here
	int exponent = 0;

	// Potential program skeleton
	scanf("%d\n", &numEntries);
	for(int i = 0; i < numEntries; i++) {

		//// Potential parsing
		scanf("%d\n", &exponent);
		//cout << exponent << endl;

		// Already integer (hopefully)
		//res = (big) pow((3.0 + sqrt(5.0)) ,exponent);
		//cout << res << endl;

		res = (bigf)exponent * (bigf)log(3.0+ sqrt(5.0));


		res = exp(res);

		resOut = (big)res;

		// Output
		printf("Case #%d: ", i+1);	// Important! Verify
		//for (int j = 0; j < numWords; j++) {
			//cout << " " << items[j].word;
			//cout << setfill('0') << setw(3) << res;
			cout << setfill('0') << setw(3) << resOut;
		//}
		printf("\n");	
	}

	return 0;
}

