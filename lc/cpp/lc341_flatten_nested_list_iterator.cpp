/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
*/
#include <vector>
#include <utility>
#include <stack>
#include <iostream>
#include <iterator>
using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    // start and end iterators
    stack<vector<NestedInteger>::iterator> begins_, ends_;;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins_.push(nestedList.begin());
        ends_.push(nestedList.end());
    }
    int next() {
        //hasNext();  // Not necessary as per the requirements
        return (begins_.top()++)->getInteger();
    }
    bool hasNext() {
        while (begins_.size()) {
            auto begIt = begins_.top();
            auto endIt = ends_.top();
            if (begIt == endIt) {
                begins_.pop(); ends_.pop();
            }
            else { // Within this vector
                if (begIt->isInteger()) {
                    return true;
                } else {
                    // Advance stored element, to mark that range as over
                    ++begins_.top(); 
                    begins_.push(begIt->getList().begin());
                    ends_.push(begIt->getList().end());
                }
            }
        }
        return false;
    }
};

class NestedIteratorOld {
private:
    vector<int> flatVec_;
    int currIdx_;
    int endIdx_;
    void fillFlatVec(const vector<NestedInteger> &nestedList) {
        for (auto &nestInt : nestedList) {
            if (nestInt.isInteger()) {
                flatVec_.push_back(nestInt.getInteger());
                ++endIdx_;
            } else {
                fillFlatVec(nestInt.getList());
            }
        }
    }
public:
    NestedIteratorOld(vector<NestedInteger> &nestedList) {
        flatVec_.clear();
        currIdx_ = 0;
        endIdx_ = 0;
        fillFlatVec(nestedList);
    }

    int next() {
        return flatVec_[currIdx_++];
    }

    bool hasNext() {
        return currIdx_ < endIdx_;
    }
};

/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/
int main() {
}
