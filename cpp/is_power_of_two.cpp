#include <iostream>

bool is_power_of_two_slow(unsigned int val)
{
	int count = 0;
	while (val != 0) {
		count += (val & 1);
		val = val >> 1;
	}
	if (count == 1) {
		return true;
	} else {
		return false;
	}
}

bool is_power_of_two(unsigned int n)
{
	if (n == 0) return false;
	return !((n != 1) && (n & (n - 1)));
}

int main()
{
	for(unsigned int i = 0; i < 10000000; i++){
		is_power_of_two_slow(i);
	}


	//std::cout << "0: " << is_power_of_two(0) << std::endl;
	//std::cout << "1: " << is_power_of_two(1) << std::endl;
	//std::cout << "2: " << is_power_of_two(2) << std::endl;
	//std::cout << "3: " << is_power_of_two(3) << std::endl;
	//std::cout << "4: " << is_power_of_two(4) << std::endl;
	//std::cout << "5: " << is_power_of_two(5) << std::endl;
	//std::cout << "6: " << is_power_of_two(6) << std::endl;
	//std::cout << "7: " << is_power_of_two(7) << std::endl;
	//std::cout << "8: " << is_power_of_two(8) << std::endl;

	return 0;
}
		
