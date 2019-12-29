#include <iostream>
#include <vector>
#include <string>
#include <pair>
#include <unordered_set>
using namespace std;

class Boggle {
	vector<vector<char>> grid;
	unordered_set<string> dictionary;
	vector<vector<bool>> state;

	list<pair<int, int>> find_all_nbrs(int x, int y) {
		list<pair<int,int> nbrs;
		int start_x = std::max(0, x - 1);
		int start_y = std::max(0, y - 1);
		int end_x = std::min((int)(grid.size() - 1), x + 1);
		int end_y = std::min((int)(grid.size() - 1), y + 1);
		for (int i = start_x; i <= end_x; i++) {
			for (int j = start_y; j <= end_y; j++) {
				if (state[i][j]){
					continue;
				}
			}
		}
		return nbrs;
	}

	void find_words_rec(int i, int j), string& current, unordered_set<string>& words) {
		if (!current.empty() && dictionary.find(current) != dictionary.end()) {
			words.insert(current);
		}
		list<pair<int, int>> nbrs = find_all_nbrs(i,j);
		for (auto& pr : nbrs) {
			current += grid[pr.first][pr.second];
			state[pr.first][pr.second] = true;
			find_words_rec(pr.first, pr.second, current, words);
			current.resize(current.size() - 1);
			state[pr.first][pr.second] = false;
		}
	}
public:
	Boggle(const vector<vector<char>>& g, const unordered_set<string>& d) {
		state.resize(g.size());
		for (vector <bool> & v : state) {
			v.resize(g.back().size());
		}
	}
	
	unordered_set<string> find_allworeds() {
		unordered_set<string> words;
		string current_word;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				find_words_rec(i, j, current_word, words);
			}
		}
		return words;
	}
};
