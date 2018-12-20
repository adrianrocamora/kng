#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

std::vector<int> two_sum(std::vector<int>& v, int target) {
    std::vector<int> res;
    std::unordered_map<int,int> valToIdx;
    for (int i = 0; i < v.size(); i++) {
        valToIdx[v.at(i)] = i;
    }
    for (int i = 0; i < v.size(); i++) {
        int expected_val = target - v.at(i);
        if (valToIdx.find(expected_val) != valToIdx.end()) {
            int j = valToIdx[expected_val];
            if (i >= j) { continue; }
            res.push_back(i+1);
            res.push_back(j+1);
            break;
        }
    }
    return res;
}

std::vector<int> two_sum_slow(std::vector<int>& v, int target) {
    std::vector<int> idx;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i == j) { continue;}
            if (v.at(i) + v.at(j) == target) {
                idx = {i+1, j+1};
                return idx;
            }
        }
    }
    return idx;
}

int main() {
    //std::vector<int> v1 = {2, 7, 11, 15};
    //int t1 = 9;
    //std::vector<int> v1 = {3, 2, 4};
    //int t1 = 6;
    std::vector<int> v1 = {0,4,3,0};
    int t1 = 0;
    std::vector<int> res1 = two_sum(v1, t1);
    std::cout << res1.at(0) << ", " << res1.at(1) << std::endl;
}



