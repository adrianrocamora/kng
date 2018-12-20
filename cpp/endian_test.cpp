#include <iostream>

using std::cout;
using std::endl;


int main() {
	unsigned int a = 1;
	char *b = (char*) &a;	
	if (*b) { cout << "Little Endian" << endl; }
 	else { cout << "Little Endian" << endl; }
}
