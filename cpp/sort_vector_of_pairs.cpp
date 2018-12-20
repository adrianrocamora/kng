#include <iostream>
#include <vector>
#include <algorithm>

bool cmp_second(const std::pair<int,float> &a, const std::pair<int,float> &b){
	return a.second < b.second;
}
int main(){
	std::vector<std::pair<int,float>> v;
	v.push_back(std::make_pair(1,10.0f));
	v.push_back(std::make_pair(2,5.0f));
	std::cout << v[0].first << " " << v[0].second << std::endl;	//1 19
	std::cout << v[1].first << " " << v[1].second << std::endl; //2 5
	std::sort(v.begin(),v.end(),cmp_second);
	std::cout << v[0].first << " " << v[0].second << std::endl; //2 5
	std::cout << v[1].first << " " << v[1].second << std::endl; //1 10
	return 0;
}
