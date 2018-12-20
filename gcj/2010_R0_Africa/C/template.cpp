#include "rock.h"
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <boost/tokenizer.hpp>

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

//bool compare(Item lhs, Item rhs) { return lhs.id < rhs.id;}
//sort(items, items+numItems, compare);

const int MAX_ITEMS = 2000;
const int MAX_LINES = 200;
const int MAX_CHAR = 1010;

// We can use a map from string to string
//for (msi::iterator it = (c).begin(); it != (c).end(); it++)
std::map<string,string> dict;
// We must also have a check:
// If two consecutive inputs are equal, add a space to the output

int getStdinLine(char *dst);

void init() {
	//They are all lowercase and there are no numbers
	dict["a"] = "2";
	dict["b"] = "22";
	dict["c"] = "222";
	dict["d"] = "3";
	dict["e"] = "33";
	dict["f"] = "333";
	dict["g"] = "4";
	dict["h"] = "44";
	dict["i"] = "444";
	dict["j"] = "5";
	dict["k"] = "55";
	dict["l"] = "555";
	dict["m"] = "6";
	dict["n"] = "66";
	dict["o"] = "666";
	dict["p"] = "7";
	dict["q"] = "77";
	dict["r"] = "777";
	dict["s"] = "7777";
	dict["t"] = "8";
	dict["u"] = "88";
	dict["v"] = "888";
	dict["w"] = "9";
	dict["x"] = "99";
	dict["y"] = "999";
	dict["z"] = "9999";
	dict[" "] = "0";
}

int main(int argc, char **argv)
{
	// Number of entries in data file
	int numEntries = 0;

	// Important!
	init();
	if (argc != 2) {
		cerr << "Error! Unexpected number of inputs to program\n";
		return 1;
	}

	// Potential inputs
	//int numItems;
	//Item items[MAX_ITEMS];
	//string desired_msg[MAX_LINES];

	// Read full text file
	std::ifstream in(argv[1]);
	std::stringstream buffer;
	buffer << in.rdbuf();
	std::string contents(buffer.str());

	//scanf("%d\n", &numEntries);
	int numEntriesCnt = 0;

	boost::char_separator<char> sep("\n");
	// It's a good habit to typedef complex types
	typedef boost::tokenizer < boost::char_separator<char> > t_tokenizer;
	t_tokenizer tok(contents, sep);
	for (t_tokenizer::iterator inLineIt = tok.begin(); inLineIt != tok.end(); ++inLineIt) {

		string inLine = *inLineIt;
		
		if (numEntriesCnt == 0) {
			numEntries = atoi(contents.c_str());
			numEntriesCnt++;
			continue;
		}

		//int msgLen = inLine.length();
		string outLine;
		std::string prevStr = "+";
		for(std::string::iterator it = inLine.begin(); it != inLine.end(); ++it) {
			//+++ How do we do this outside initializations?
			std::string strTemp(1, *it);
			
			// If they are the same add a space
			if (strTemp.compare(prevStr) == 0 ||
				dict[strTemp][0] == dict[prevStr][0]) {
				outLine.append(" ");
			}

			outLine.append(dict[strTemp]);
			prevStr = strTemp;
		}

		// Output
		printf("Case #%d:", numEntriesCnt);	// Important! Verify
		cout << " " << outLine << endl;
		numEntriesCnt++;
	}

	if (numEntries == 0) {
		cerr << "Warning! No entries";
	}

	return 0;
}
