// rock.h
//
// Just a bunch of useful #defines, typedefs and functions
//

#pragma once

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
typedef std::set<int>			si;
typedef std::map<string,int>	msi;

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
