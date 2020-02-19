#include <iostream>
#include "gmpxx.h"
typedef mpz_class Big;

using namespace std;

int main()
{
	Big z;
	cin >> z;
	cout << z*2+16 << endl;
	return 0;
}
