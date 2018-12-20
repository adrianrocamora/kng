#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

string bigAdd(const string& strA, const string strB) {
    int i, x, carry = 0;
    string res;
    string strShort, strLong;
    if (strA.length() < strB.length()) {
        strShort = strA;
        strLong = strB;
    } else {
        strShort = strB;
        strLong = strA;
    }
    for (i = 0; i < strShort.length(); ++i) {
        x = (strShort[i] - '0') + (strLong[i] - '0') + carry;
        res += ('0' + x % 10);
        carry = x / 10;
    }
    for (; i < strLong.length(); ++i) {
        x = (strLong[i] - '0') + carry;
        res += ('0' + x % 10);
        carry = x / 10;
    }
    while (carry > 0) {
        res += ('0' + carry % 10);
        carry = carry / 10;
    }
    return res;
}

string bigMultiply(const string& str, int n) {
	int x, carry = 0;
	string res;
	for (int i = 0; i < str.length(); ++i) {
		x = (  (str[i] -'0') * n) + carry;
		res += to_string(x % 10);
		carry = x / 10;
	}
	while (carry > 0) {
		res += to_string(carry % 10);
		carry = carry / 10;
	}
	return res;
}

string bigMultiply(const string& strA, const string& strB) {
    int i, x, carry = 0;
    string strShort, strLong;
    if (strA.length() < strB.length()) {
        strShort = strA;
        strLong = strB;
    } else {
        strShort = strB;
        strLong = strA;
    }
    string res = "0";
    for (i = 0; i < strShort.length(); ++i) {
        res = bigAdd(res, bigMultiply(string(i,'0') + strLong, strShort[i] - '0'));
    }
	return res;
}

string bigFactorial(int n) {
	string fact;
	fact += ('0' + 1);
	for (int i = n; i > 1; i--) {
		fact = bigMultiply(fact, i);
	}
	return fact;
}

int main() {
    string strA = "1000987", strB = "321";
	std::reverse(strA.begin(), strA.end());
	std::reverse(strB.begin(), strB.end());
	//string sum = bigAdd(strA, strB);
	string sum = bigMultiply(strA, strB);
	std::reverse(sum.begin(), sum.end());
	cout << sum << endl;
    cout << "321316827" << endl;
	return 0;
}
