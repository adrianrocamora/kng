#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

// Remember that a priority queue uses the default (less) to create a Max Heap
struct LessThanByCount {
    bool operator() (
            const std::pair<std::string, int> &lhs,
            const std::pair<std::string, int> &rhs) const{
        return lhs.second < rhs.second;
    }
};

int main() {
    std::unordered_set<std::string> words;
    std::unordered_multiset<std::string> wordContainer;
    std::priority_queue<std::pair<std::string,int>, std::vector<std::pair<std::string,int>>, LessThanByCount> wordMaxHeap;

    std::string tmpString;
    while (std::cin >> tmpString) {
        words.insert(tmpString);            // To iterate
        wordContainer.insert(tmpString);    // To count 
    }
    for (const auto& s : words) {
        wordMaxHeap.push(std::make_pair(s,wordContainer.count(s)));
    }
    for (int i = 0; i < 10; i++) {
        std::cout << wordMaxHeap.top().first << ": " << wordMaxHeap.top().second << std::endl;
        wordMaxHeap.pop();
    }
}
