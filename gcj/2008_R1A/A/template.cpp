#include <stdio.h> 
#include <algorithm> 
#include <iostream> 
#include <vector> 
#include <set> 
#include <string> 
#include <map> 

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

void Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

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

struct Item 
{
	int thing;
	int id;
};

bool compareAsc(long lhs, long rhs) { return lhs < rhs;}
bool compareDesc(long lhs, long rhs) { return lhs > rhs;}
//sort(items, items+numItems, compareAsc);
//sort(items, items+numItems, compareDes);

const int MAX_ITEMS = 810;
const int MAX_LINES = 200;


// Two same size vectors
// Matching problem
// permute each one and get the dot product
// The minimum scalar product would be from 
// negative or smaller numbers
// 
// Proposal:
// Best case:
// extract negative		by positives
//		   positive		by negatives
//         0			by the largest
// 
// Algorithm (unproven);
//	For both vectors
// 		Iteratively find zeros and remove the largest from the other set
// 		Sort both resulting vectors one ascending one descending
//	Get the scalar product  

int main()
{
	// Number of entries in data file
	int numEntries = 0;

	// Potential inputs
	int lenVec;
	Item items[MAX_ITEMS];
	string lines[MAX_LINES];

	vll vec1;
	vll vec2;


	// Outputs go here

	// Potential program skeleton
	scanf("%d\n", &numEntries);
	for(int i = 0; i < numEntries; i++) {
		vec1.clear();
		vec2.clear();
		//// Potential parsing
		//getline(std::cin, lines[i]);
		scanf("%d\n", &lenVec);
		for(int j = 0; j < lenVec; j++) {
			long long acqNum;
			scanf("%lld", &acqNum);
			//cout << acqNum << " ";
			vec1.push_back(acqNum);
		}
		//cout << endl;
		for(int j = 0; j < lenVec; j++) {
			long long acqNum;
			scanf("%lld", &acqNum);
			//cout << acqNum << " ";
			vec2.push_back(acqNum);
		}
		//cout << endl;

		// Sort them 
		sort(vec1.begin(), vec1.end(), compareAsc);
		sort(vec2.begin(), vec2.end(), compareDesc);

		//for (int j = 0; j < vec1.size(); j++) {
			//cout << vec1[j] << " " ;
		//}
		//cout << endl;
		//for (int j = 0; j < vec2.size(); j++) {
			//cout << vec2[j] << " " ;
		//}
		//cout << endl;
		//cout << "Stop read"<< endl;

		// Match the most negative one 



		//// Find zeros and remove the largest corresponding elements
		//vector<long>::iterator iterZer = find(vec1.begin(), vec1.end(), 0L);
		//while (iterZer != vec1.end()) {
			//vector<long>::iterator delMax;

			//if (iterZer != vec1.end()) {
				//// remove
				//delMax = vec2.begin();
				//vec2.erase(delMax);
				//vec1.erase(iterZer);
				//delMax++;
			//}

			//iterZer = find(vec1.begin(), vec1.end(), 0L);
		//}
		//// Repeat
		//iterZer = find(vec2.begin(), vec2.end(), 0L);
		//while (iterZer != vec2.end()) {
			//vector<long>::iterator delMax;

			//if (iterZer != vec2.end()) {
				//// remove
				//delMax = vec1.end()-1;
				//vec1.erase(delMax);
				//vec2.erase(iterZer);
				//delMax--;
			//}

			//iterZer = find(vec2.begin(), vec2.end(), 0L);
		//}

		// Then isolat



		// Exhaustively search whatever options are left
		// Get the scalar product of whatever remains
		long long sum = 0L;
		for (int j = 0; j < vec1.size(); j++) {
			sum = sum + vec1[j] * vec2[j];
		}


		// Output
		printf("Case #%d: ", i+1);	// Important! Verify
		//for (int j = 0; j < numWords; j++) {
			//cout << " " << items[j].word;
			//printf(" %d:", );	
		//}
		cout << sum << endl;
	}

	return 0;
}

//------------------
//// Read full text file
//std::ifstream in(argv[1]);
//std::stringstream buffer;
//buffer << in.rdbuf();
//std::string contents(buffer.str());

//------------------
//boost::char_separator<char> sep("\n");
//// It's a good habit to typedef complex types
//typedef boost::tokenizer < boost::char_separator<char> > t_tokenizer;
//t_tokenizer tok(contents, sep);
//for (t_tokenizer::iterator inLineIt = tok.begin(); inLineIt != tok.end(); ++inLineIt) {
//	string inLine = *inLineIt;

//------------------
//string outLine;
//std::string prevStr = "+";
//for(std::string::iterator it = inLine.begin(); it != inLine.end(); ++it) {
	////+++ How do we do this outside initializations?
	//std::string strTemp(1, *it);
	
	//// If they are the same add a space
	//if (strTemp.compare(prevStr) == 0 ||
		//dict[strTemp][0] == dict[prevStr][0]) {
		//outLine.append(" ");
	//}

	//outLine.append(dict[strTemp]);
	//prevStr = strTemp;
//}
