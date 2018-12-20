#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>

int main() {
    std::unordered_set<std::string> words;
    std::unordered_multiset<std::string> wordContainer;
    std::vector<std::pair<std::string, int>> wordVec;   // Naive approach
    std::string tmpString;
    while (std::cin >> tmpString) {
        words.insert(tmpString);            // To iterate
        wordContainer.insert(tmpString);    // To count 
    }
    for (const auto& s : words) {
        wordVec.push_back(std::make_pair(s,wordContainer.count(s)));
    }
    std::partial_sort(wordVec.begin(), wordVec.begin() + 10, wordVec.end(), 
        [](const std::pair<std::string,int>& lhs, const std::pair<std::string,int>& rhs) {
            return lhs.second > rhs.second;
        }
    );
    for (int i = 0; i < 10; i++) {
        std::cout << wordVec.at(i).first << std::endl;
    }
}
