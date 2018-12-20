#include <iostream>

int toggle_nth_bit(int x, int n) {
	return x ^ (1 << n);
}

int turn_off_rightmost_set_bit(int x) {
	return x & (x-1);
}
int turn_off_first_bit(int x) {
	return x & ~(1 << 0);;
}

int main() {
	std::cout << "toggle_nth_bit: " << toggle_nth_bit(7,1) << ", expected 5" << std::endl;
	std::cout << "toggle_nth_bit: " << toggle_nth_bit(8,0) << ", expected 9" << std::endl;

	std::cout << "turn_off_first_bit: " << turn_off_first_bit(7) << ", expected 6" << std::endl;
	std::cout << "turn_off_first_bit: " << turn_off_first_bit(8) << ", expected 8" << std::endl;

	std::cout << "turn_off_rightmost_set_bit: " << turn_off_rightmost_set_bit(7) << ", expected 6" << std::endl;
	std::cout << "turn_off_rightmost_set_bit: " << turn_off_rightmost_set_bit(8) << ", expected 0" << std::endl;
	return 0;
}








