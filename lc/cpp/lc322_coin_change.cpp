#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		//int infNum = numeric_limits<int>::max();
		int infNum = amount+1;
		vector<int> dp(amount+1, infNum);
		dp[0] = 0;
		for (int i = 1; i < dp.size(); i++) {
			for (auto den : coins) {
				if (den <= i) {  // Only use coins up to that value
					dp[i] = min(dp[i], dp[i-den] + 1);
				}
			}
		}
		// If the values where never changed according to the current constraints, then
		// there wasn't a solution for that case
		return dp[amount] == infNum ? -1 : dp[amount];
	}
};

int main() {
	Solution sol;
	//vector<int> coins = {1, 2, 5};
	//int amount = 11;
	vector<int> coins = {2};
	int amount = 3;
	cout << "-1: " << sol.coinChange(coins, amount) << endl;

	return 0;
}
