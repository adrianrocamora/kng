#include <stdio.h> 

#include <algorithm> 
#include <iostream> 
#include <iomanip>
#include <vector> 
#include <set> 
#include <string> 
#include <map> 

using namespace std;

typedef long long				ll;
typedef std::pair<int, int>		ii;
typedef std::vector<ii>			vii;
typedef std::vector<int>		vi;
typedef std::set<int>			si;
typedef std::map<string,int>	msi;

#define INF				1000000000

using namespace std;

struct Item 
{
	int thing;
	int id;
};

//bool compare(Item lhs, Item rhs) { return lhs.id < rhs.id;}
//sort(items, items+numItems, compare);

const int MAX_ITEMS = 2000;
const int MAX_LINES = 200;


using namespace std;

bool compare(const pair<float,string>&i, const pair<float,string>&j)
{
    return i.first < j.first;
}

int main()
{
    // Simple vector to store pairs
    vector<pair<float,string> >os;

    // Put some random data
    os.push_back(pair<float,string>(1.58, "Linux"));
    os.push_back(pair<float,string>(5.11, "Android"));
    os.push_back(pair<float,string>(68.16, "Windows"));
    os.push_back(pair<float,string>(8.45, "OS X"));
    os.push_back(pair<float,string>(9.89, "iOS"));
    os.push_back(pair<float,string>(5.41, "Other"));

    // Sort it
    sort(os.begin(),os.end(),compare);

    // Print
    for(int i=0;i<os.size();i++)
        cout << os.at(i).second << " (" << os.at(i).first << "%)"<< endl;
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

