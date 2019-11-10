#include <iostream>
#include <tuple>

using namespace std;

int main() {
	auto tup1 = make_tuple('A', 123, "asdf");
	cout << tuple_size<decltype(tup1)>::value << endl;
	cout << get<0>(tup1) << endl;
	cout << get<1>(tup1) << endl;
	cout << get<2>(tup1) << endl;

	tuple<char, int, string> tup2 = make_tuple('B', 456, "qwre");
	cout << tuple_size<decltype(tup2)>::value << endl;
	cout << get<0>(tup2) << endl;
	cout << get<1>(tup2) << endl;
	cout << get<2>(tup2) << endl;
}

