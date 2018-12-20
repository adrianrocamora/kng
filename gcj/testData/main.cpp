// This program generates a file with random data
// for testing the performance of other procedures
// 
// It writes the resulting data to the standard output
//
// If a file is desired, it can be piped
//

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
	// First entry of the file
	// long type supports values above 2 billion 
	long numEntries;

	cin >> numEntries;

	if (numEntries < 0) {
		cerr << "Error: Not enough entries requested" << endl;
		return 1;
	}

	srand(time(NULL));

	cout << numEntries << endl;

	for (long i = 0; i < numEntries; i++) {
		cout << rand() % 10 << endl;
	}

	return 0;
}

