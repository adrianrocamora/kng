#include <iostream>
#include <vector>

std::vector<int> two_sum(const std::vector<int> &v, int target) {
	int idx1,idx2;
	bool done = false;
	for (int i = 0; i < v.size(); i++) {
		if (done) { break;}
		for (int j = 0; j < v.size(); j++) {
			if (i == j) { continue;}
			if (v[i] + v[j] == target) { idx1 = i+1;idx2 = j+1;done = true;break;}
		}
	}
	std::vector<int> res{idx1,idx2};
	return res;
}

int main() {
	std::vector<int> in{2,7,11,15};
	int target = 9;
	std::vector<int> res = two_sum(in, target);
	std::cout << "Res: " << res[0] << ", " << res[1] << std::endl;
	return 0;
}




































































































