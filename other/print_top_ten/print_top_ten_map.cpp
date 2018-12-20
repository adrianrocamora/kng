#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <utility>

int main() {
    std::unordered_map<std::string, int> wordFreq;
    std::string tmpString;
    while (std::cin >> tmpString) {
        auto wordFound = wordFreq.find(tmpString);
        if (wordFound == wordFreq.end()) {
            //wordFreq.insert(std::make_pair(tmpString, 1));  // OK
            wordFreq[tmpString] =  1;                     // OK
        } else {
            //wordFreq.emplace(std::make_pair(tmpString, wordFound->second + 1)); //WRONG! EMPLACE DOES NOT REPLACE!
            //wordFreq.insert(std::make_pair(tmpString, wordFound->second + 1));  //WRONG! INSERT DOES NOT REPLACE!
            //wordFreq[tmpString] = wordFound->second + 1;            // OK, but weird?
            wordFreq[tmpString]++;
        }
    }
    for (auto p : wordFreq) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    std::vector<std::pair<std::string, int>> wordVec(wordFreq.begin(), wordFreq.end());;   
    std::partial_sort(wordVec.begin(), wordVec.begin() + 10, wordVec.end(), 
        [](const std::pair<std::string,int>& lhs, const std::pair<std::string,int>& rhs) {
            return lhs.second > rhs.second;
        }
    );
    std::cout << std::endl << "Top 10 most frequent:" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << wordVec.at(i).first << std::endl;
    }
}
