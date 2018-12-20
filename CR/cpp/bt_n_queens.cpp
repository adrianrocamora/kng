#include <iostream>
#include <vector>
using namespace std;
bool is_valid_move(int proposed_row,int proposed_col, vector<int>& solution) {
	for (int i = 0; i < proposed_row; i++) {
		int old_row = i;
		int old_col = solution[i];
		int diagonal_offset = proposed_row - old_row;
		if (old_col == proposed_col ||
			old_col == proposed_col - diagonal_offset ||
			old_col == proposed_col + diagonal_offset) {
				return false;
		}
	}
	return true;
}
void solve_n_queens_rec(int n, vector<int>& solution,int row,vector<vector<int>>& results){
	if (row == n) {
		results.push_back(solution);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (is_valid_move(row, i, solution)) {
			solution[row] = i;
			solve_n_queens_rec(n, solution, row + 1, results);
		}
	}
}
void solve_n_queens(int n,vector<vector<int>>& results) {
	vector<int> solution(n);
	solve_n_queens_rec(n, solution, 0, results);
}

int main() {
	vector<vector<int>> results;

	for (int i = 1; i <= 6; i++) {
		solve_n_queens(i, results);
		std::cout << "For " << i << " queens. ";
		std::cout << "Number of solutions: " << results.size() << std::endl;

		std::cout << "Printing the first solution if any" << std::endl;

		if (results.size() != 0) {
			for (int k = 0; k < results.size(); k++) {
				for (int j = 0; j < results[k].size(); j++) {
					std::cout << results[k][j] << " " ;
				}
				std::cout << std::endl;
			}
		} else {
			std::cout << "No Solutions" << std::endl;
		}

		std::cout << std::endl;
		results.clear();
	}



	return 0;
}

