#include <string>
#include <iostream>
#include <unordered_map>
#include <iostream>

int main() {
	std::unordered_map<std::string,double> myrecipe;

	// copy insertion
	std::pair<std::string,double> myshopping ("baking powder",0.3);
	myrecipe.insert (myshopping);                        

	// move insertion
	myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0)); 

	// range insertion
	std::unordered_map<std::string,double> mypantry = {{"milk",2.0},{"flour",1.5}};
	myrecipe.insert (mypantry.begin(), mypantry.end());  

	// initializer list insertion
	myrecipe.insert( {{"sugar",0.8},{"salt",0.1}} );    

	for (auto &x : myrecipe) {
		std::cout << x.first << ": " << x.second << std::endl;
	}
}
