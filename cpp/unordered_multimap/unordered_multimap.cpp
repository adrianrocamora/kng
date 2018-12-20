#include <iostream>
#include <unordered_map>
int main() {
	std::unordered_multimap<char,int> map;
	map.insert(std::unordered_multimap<char,int>::value_type('a',1));
	map.insert(std::unordered_multimap<char,int>::value_type('b',2));
	map.insert(std::unordered_multimap<char,int>::value_type('c',3));
	map.insert(std::unordered_multimap<char,int>::value_type('d',4));
	map.insert(std::unordered_multimap<char,int>::value_type('a',7));
	map.insert(std::unordered_multimap<char,int>::value_type('b',18));
	// Finds a range containing all elements whose key is k
	// pair<iterator, iterator> equal_range(const key_type &k)
	auto range = map.equal_range('a');
	for (auto it = range.first; it != range.second; it++) {
		std::cout << it->first << ' ' << it->second << std::endl;
	}
	return 0;
}
