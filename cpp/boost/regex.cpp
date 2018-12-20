#include <iostream>
#include <boost/regex.hpp>
// Compile with -lboost_regex flag
using namespace std;
int main() {
	boost::regex expr(
			"\\d{4}"
			"/"
			"(0?[1-9]|1[0-2])"
			"/"
			"(0?[1-9]|[1-2][0-9]|3[0-1])",
			boost::regex_constants::extended
		);
	while (true) {
		cout << "Enter a date (year/month/day) (q = quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}
		if (boost::regex_match(str, expr)) {
			cout << " Valid date. " << endl;
		} else {
			cout << " Invalid date. " << endl;
		}
	}
}
