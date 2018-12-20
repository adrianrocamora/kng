#include "rock.h"

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

int main()
{
	// Number of entries in data file
	int numEntries = 0;

	// Potential inputs
	int numItems;
	Item items[MAX_ITEMS];
	string lines[MAX_LINES];

	// Outputs go here

	// Potential program skeleton
	scanf("%d\n", &numEntries);
	for(int i = 0; i < numEntries; i++) {
		//// Potential parsing
		//getline(std::cin, lines[i]);
		//scanf("%d", &numItems);

		for(int j = 0; j < numItems; j++) {
			items[j].id = j+1;
			//scanf("%d", &items[j].price);
		}

		// brute force
		//for(int j = 0; j < numItems; j++) {
			//for(int k = j+1; k < numItems; k++) {
				////if (items[j].price + items[k].price == credit) {
					////idS = items[j].id;
					////idL = items[k].id;
					////break;
				////}
			//}
		//}

		// Output
		printf("Case #%d:", i+1);	// Important! Verify
		//for (int j = 0; j < numWords; j++) {
			//cout << " " << items[j].word;
			//printf(" %d:", );	
		//}
		printf("\n");
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
