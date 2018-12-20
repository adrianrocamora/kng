#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <forward_list>

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
	if(first == last) { return; }
	auto pivot = *std::next(first, std::distance(first,last)/2);
	ForwardIt middle1 = std::partition(first, last, 
	[pivot](const auto& em){ return em < pivot; });
	ForwardIt middle2 = std::partition(middle1, last, 
	[pivot](const auto& em){ return !(pivot < em); });
	quicksort(first, middle1);
	quicksort(middle2, last);
}


int main() {
	std::vector<int> v{1,2,355,34,3,5,123,33,2};
	quicksort(std::begin(v), std::end(v));
	for (auto x : v) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	std::forward_list<int> fl = {1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
	quicksort(std::begin(fl), std::end(fl));
	for (auto x : fl) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
