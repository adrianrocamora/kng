// Each beer costs $2. 
// After drinking a beer, 2 empty bottles earn you a bonus beer, or 4 caps earn you equally a bonus beer. 
// Now with $10 how many beer you can have in maximum
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    const int kMaxMoney = 500;
    vector<vector<vector<int>>> dp;
public:
    Solution () {
        dp.clear();
        dp.resize(201, vector<vector<int>>(101, vector<int>(402, -1)));
    }
    int maxBeers(int money) {
        return maxBeersRec(money, 0, 0);
    }
    int maxBeersRecDP(int money, int emptyBottles, int caps) {
        // No money no more beers to get caps or bottles from
        if (dp.at(money).at(emptyBottles).at(caps) != -2) {
            return dp.at(money).at(emptyBottles).at(caps);
        }
        if (money < 0) { 
            return dp.at(money).at(emptyBottles).at(caps) = -1;
        }
        if (money == 0) {
            return dp.at(money).at(emptyBottles).at(caps) = emptyBottles / 2 + caps / 4; 
        }
        int b = maxBeersRec(money - 2, emptyBottles + 2, caps + 2);
        b = (b >= 0) ? b + 1 : 0;
        int c = maxBeersRec(money - 4, emptyBottles + 4, caps + 4);
        c = (c >= 0) ? c + 2 : 0;
        return dp.at(money).at(emptyBottles).at(caps) = max({b,c});
    }
    int maxBeersRec(int money, int emptyBottles, int caps) {
        // No money no more beers to get caps or bottles from
        if (money < 0) { return -1;}
        if (money == 0) {
            // Cash in your bottles and caps
            return emptyBottles / 2 + caps / 4; 
        }
        int b = maxBeersRec(money - 2, emptyBottles + 2, caps + 2);
        b = (b >= 0) ? b + 1 : 0;
        int c = maxBeersRec(money - 4, emptyBottles + 4, caps + 4);
        c = (c >= 0) ? c + 2 : 0;
        return max({b,c});
    }
};

int main() {
    // Maximize the number of beers
    Solution s;
    //cout << s.maxBeers(10) << endl;
    for (auto x : {0,1,2,3,4,5,10,15,20,50,100,200}) {
        cout << "For $" << x << " you can get at most " << s.maxBeers(x) << " beers" << endl;
    }
}

