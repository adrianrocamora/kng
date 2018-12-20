#include <iostream>
#include <algorithm>
#include <vector>

bool myFun(int i, int j) { return i < j;}

int main() {
	int myInts[] = {9,8,7,6,5,4,3,2,1};
	// Give the vector constructor the first and last element
	std::vector<int> myVec(myInts,myInts+9);

	// Give the selection algorithm the 
	std::partial_sort (myVec.begin(), myVec.begin()+5, myVec.end());

	// Or use a defined function (possibly to reverse the order)
	//std::partial_sort (myVec.begin(), myVec.begin()+5, myVec.end(), myFun);

	std::cout << "myVec contains: ";
	for (	std::vector<int>::iterator it = myVec.begin();
			it != myVec.end();
			it++) {
		std::cout << ' ' << *it;
	}
	std::cout << '\n';



	return 0;
}

