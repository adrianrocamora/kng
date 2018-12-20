#include <iostream>

using namespace std;

int main() {
    int a = 1;
    char *b = reinterpret_cast<char*>(&a);
	if (*b == 1) { cout << "Little Endian" << endl;}
	else { cout << "Big Endian" << endl;}
}
