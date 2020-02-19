#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include <cmath>
#include <cassert>

using namespace std;
// NOTE: Max steps is 100
class ChessKnight {
    array<array<array<double,100>,8>,8> memo_;
    const vector<pair<int,int>> pair_adder_ = {{-2,-1}, {-1,-2}, {-2,1}, {-1,2}, {2,-1}, {1,-2}, {2,1}, {1,2}};
    double findProbabilityHelper(int x, int y, int step) {
        if (x < 0 || x > 7 || y < 0 || y > 7) {
            return 0.0;
        }
        if (step == 0) { 
            return 1.0;
        }
        if (memo_[x][y][step] != -1) {
            return memo_[x][y][step];
        }
        double res = 0.0;
        for (auto &p : pair_adder_) {
            res += findProbabilityHelper(x + p.first, y + p.second, step - 1) / 8.0;
        }
        memo_[x][y][step] = res;
        return res;
    }
public:
    ChessKnight() {
        for (auto &aa : memo_) {
            for (auto &a : aa) {
                for (auto &x : a) {
                    x = -1;
                }
            }
        }
    }
    double probability_recursive(int x, int y, int step) {
        return findProbabilityHelper(x - 1, y - 1, step);
    }
    double probability_iterative(int x, int y, int step) {
        for (int k = 0; k < step; ++k) {
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    double res = 0.0;
                    for (auto &p : pair_adder_) {
                        if (i + p.first < 0 || i + p.first > 7 || j + p.second < 0 || j + p.second > 7) {
                            res += 0.0;
                        } else if (k == 0) {
                            res += 1.0 / 8.0;
                        } else {
                            res += memo_[i + p.first][j + p.second][k - 1] / 8.0;
                        }
                    }
                    memo_[i][j][k] = res;
                }
            }
        }
        return memo_[x-1][y-1][step-1];
    }
};

bool doubleEqual(double a, double b, double tol = 0.00000001) {
    return std::abs(a - b) < tol;
}

int main() {
    ChessKnight sol;
    //cout << sol.probability_iterative(1,1,2) << endl;
    //cout << sol.probability_iterative(4,4,1) << endl;
    //cout << sol.probability_iterative(2,3,10) << endl;
    //cout << sol.probability_iterative(4,3,50) << endl;
    assert(doubleEqual(sol.probability_iterative(1,1,2), 0.1875));
    cout << "Passed" << endl;
    assert(doubleEqual(sol.probability_iterative(4,4,1), 1.0));
    cout << "Passed" << endl;
    assert(doubleEqual(sol.probability_iterative(2,3,10), 0.0522148497));
    cout << "Passed" << endl;
    assert(doubleEqual(sol.probability_iterative(4,3,50), 8.35643e-7));
    cout << "Passed" << endl;
}
