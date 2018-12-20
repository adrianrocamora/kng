#include <iostream>
#include <regex>
using namespace std;
int main() {
	regex expr(
			"\\d{4}"
			"/"
			"(0?[1-9]|1[0-2])"
			"/"
			"(0?[1-9]|[1-2][0-9]|3[0-1])"
		);
	while (true) {
		cout << "Enter a date (year/month/day) (q = quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}
		if (regex_match(str, expr)) {
			cout << " Valid date. " << endl;
		} else {
			cout << " Invalid date. " << endl;
		}
	}
}
