#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> intersection_STL(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.empty() || nums2.empty()) { return res;}
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = unique(nums1.begin(), nums1.end());
        if (it1 != nums1.end()) {  nums1.erase(it1); }
        auto it2 = unique(nums1.begin(), nums1.end());
        if (it2 != nums2.end()) {  nums2.erase(it2); }
        set_intersection(   nums1.begin(), nums1.end(),
                            nums2.begin(), nums2.end(),
                            back_inserter(res));
        return res;
    }
    vector<int> intersection_only_sorting_allowed(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.empty() || nums2.empty()) { return res;}
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if ((nums1[i] == nums2[j]) && (i == 0 || nums1[i] != nums1[i - 1])) {
                res.push_back(nums1[i]);
                ++i, ++j;
            } else if (nums1[i] < nums2[j]) { 
                ++i;
            } else { 
                ++j; 
            }
        }
        return res;
    }
    vector<int> intersection_one_array_smaller(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.empty() || nums2.empty()) { return res;}
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>& small = (nums1.size() < nums2.size()) ? nums1 : nums2;
        vector<int>& large = (nums1.size() < nums2.size()) ? nums2 : nums1;
        for (int i = 0; i < small.size(); ++i) {
            if ((i == 0 || small[i] != small[i - 1]) && binary_search(large.begin(), large.end(), small[i])) {
                res.push_back(small[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> v1{1,2,2,1};
    vector<int> v2{2,2};
    //vector<int> v1{1,2};
    //vector<int> v2{1,1};
    for (auto x : sol.intersection_one_array_smaller(v1,v2)) {
        cout << x << " ";
    }
    cout << endl;
}
