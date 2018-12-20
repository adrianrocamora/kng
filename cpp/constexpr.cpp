#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

constexpr bool is_prime_recursive(size_t number, size_t c)
{
      return (c*c > number) ? true : 
                     (number % c == 0) ? false : 
                                   is_prime_recursive(number, c+1);
}
 
constexpr bool is_prime_func(size_t number)
{
      return (number <= 1) ? false : is_prime_recursive(number, 2);
}

int main() {
	static_assert(is_prime_func(7), "...");
	// The following complains, there's maybe some tweaking required with -fconstexpr-depth=NUM
	//cout << x << (static_assert(is_prime_func(200000), "...") ? "\tPrime" : "\tNot Prime" ) << endl;
}
