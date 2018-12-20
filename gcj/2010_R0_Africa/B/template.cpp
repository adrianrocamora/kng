#include <stdio.h> 
#include <algorithm> 
#include <iostream> 
#include <vector> 
#include <string> 

using namespace std;

const int MAX_I = 2000;

struct Item 
{
	string word;
	int id;
};

bool compare(Item lhs, Item rhs) { return lhs.id > rhs.id;}

void Tokenize(const string&, vector<string>&, const string&);


int main()
{
	int numEntries = 0;

	Item items[MAX_I];
	//int numItems;

	string lines[100];

	// The \n escape is very important!
	// otherwise we can skup a line
	scanf("%d\n", &numEntries); // N num cases
	for(int i = 0; i < numEntries; i++) {

		//scanf("%d", &credit);
		//cin >> lines[i];
		getline(std::cin, lines[i]);

		int numWords = 0;

		vector<string> tokens;
		Tokenize(lines[i], tokens, " ");
		//copy(tokens.begin(), tokens.end(), ostream_iterator<string>(cout, " "));
		numWords = tokens.size();

		for(int j = 0; j < numWords; j++) {
			items[j].id = j;
			items[j].word = tokens[j];
		}

		// Sort the list by ascending prices(opt)
		sort(items, items + numWords, compare);

		// Output
		printf("Case #%d:", i+1);
		for (int j = 0; j < numWords; j++) {
			cout << " " << items[j].word;
			// Non POD item
		}
		printf("\n");
	}


	return 0;
}

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
