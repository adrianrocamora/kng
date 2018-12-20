#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>

int main() {
    std::unordered_set<std::string> words;
    std::unordered_multiset<std::string> wordContainer;
    // This is be better since we only need the top 10
    // std::priority_queue<std::string, std::vector<std::string> GreaterThanByCount>
    std::vector<std::pair<std::string, int>> wordVec;   // Naive approach

    std::string tmpString;
    while (std::cin >> tmpString) {
        words.insert(tmpString);            // To iterate
        wordContainer.insert(tmpString);    // To count 
    }
    for (const auto& s : words) {
        wordVec.push_back(std::make_pair(s,wordContainer.count(s)));
    }
    std::sort(wordVec.begin(), wordVec.end(), 
        [](const std::pair<std::string,int>& lhs, const std::pair<std::string,int>& rhs) {
            return lhs.second > rhs.second;
        }
    );
    for (int i = 0; i < wordVec.size(); i++) {
        std::cout << wordVec.at(i).first << ": " << wordVec.at(i).second << std::endl;
    }
}
