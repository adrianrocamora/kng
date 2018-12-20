#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
class Dictionary
{
public:
	Dictionary();
	~Dictionary();
	bool wordExists(std::string word);
private:
	std::unordered_set<std::string> dict_;
};
Dictionary::Dictionary() {
	// Constructs default dictionary from /usr/share/dict/words
	std::ifstream dictFile("/usr/share/dict/words");
	std::string currWord;
	while (dictFile >> currWord) {
		dict_.insert(currWord);
	}
}
Dictionary::~Dictionary() {}
bool Dictionary::wordExists(std::string word)
{
	auto it = dict_.find(word);
	if (it == dict_.end()) {
		return false;
	} else {
		return true;
	}
}
int main() {
	Dictionary dict;
	std::string currWord = "dog";
	std::cout << "Is \"" << currWord << "\" an English word? " << (dict.wordExists(currWord) ? "Yes" : "No") << std::endl;
	currWord = "perro";
	std::cout << "Is \"" << currWord << "\" an English word? " << (dict.wordExists(currWord) ? "Yes" : "No") << std::endl;
	currWord = "cat";
	std::cout << "Is \"" << currWord << "\" an English word? " << (dict.wordExists(currWord) ? "Yes" : "No") << std::endl;
	currWord = "gato";
	std::cout << "Is \"" << currWord << "\" an English word? " << (dict.wordExists(currWord) ? "Yes" : "No") << std::endl;
}



