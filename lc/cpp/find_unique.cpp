#include <iostream>
#include <vector>

int find_unique(const std::vector<int> &v) {
	int res = 0;
    for (auto x : v) {
        res ^= x;
    }
	return res;
}

int main() {
	std::vector<int> in{15,2,7,11,2,11,15};
	int res = find_unique(in);
	std::cout << "Res: " << res << std::endl;
	return 0;
}




































































































