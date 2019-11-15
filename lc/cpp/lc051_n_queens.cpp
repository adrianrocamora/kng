#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> resStr;
        vector<vector<int>> res;
        vector<int> currSol(n);
        solveNQueensRec(n, currSol, 0, res);
        for (int i = 0; i < res.size(); ++i) {
            vector<string> board(n, string(n,'.'));
            for (int j = 0; j < n; ++j) {
                board[j][res[i][j]] = 'Q';
            }
            resStr.push_back(board);
        }
        return resStr;
    }
    void solveNQueensRec(int n, vector<int>& currSol, int row, vector<vector<int>>& res) {
        if (row == n) {
            res.push_back(currSol);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isValidMove(row, i, currSol)) {
                currSol[row] = i;
                solveNQueensRec(n, currSol, row + 1, res);
            }
        }
    }
    bool isValidMove(int propRow, int propCol, vector<int>& sol) {
        // Check all queens in the solution
        for (int i = 0; i < propRow; ++i) {
            int oldRow = i;
            int oldCol = sol[i];
            int diagOffset = propRow - oldRow;
            if (oldCol == propCol ||
                oldCol == propCol - diagOffset ||
                oldCol == propCol + diagOffset) {
                return false;        
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<string>> res = sol.solveNQueens(n);
    cout << "For " << n << " queens" << endl;
    for (auto& v : res) {
        for (auto x : v) {
            cout << x << endl;
        }
        cout << endl;
    }
}
