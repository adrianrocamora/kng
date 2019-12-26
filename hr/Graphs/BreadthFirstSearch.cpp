#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// Zero based interface
class Graph {
private:
	// We'll use a bag of adjacent vertices at each point
public:
    vector<vector<int>> vv;
    explicit Graph(int V) {
        for (int i = 0; i < V; ++i) {
            vv.push_back(vector<int>{});
        }
    }
    void addEdge(int a, int b) {
		vv.at(a).push_back(b);
		vv.at(b).push_back(a);
    }
	int V() { return vv.size(); }
};

class BFS {
private:
	vector<bool> marked;
	int start_;
public:
	vector<int> distToStart;
	BFS(Graph g, int start) {
		start_ = start;
		for (int i = 0; i < g.V(); ++i) {
			distToStart.push_back(-1);
			marked.push_back(false);
		}
		distToStart[start] = 0;
		marked[start] = true;
		queue<int> q;
		q.push(start);	
		int currLevelDist = 6;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int i = 0; i < g.vv[curr].size(); ++i) { 
				int currAdj = g.vv[curr][i];
				if (!marked[currAdj]) {
					q.push(currAdj);
					marked[currAdj] = true;
					distToStart[currAdj] = distToStart[curr] + 6;
				}
			}
			//currLevelDist += 6;
		}
	}
};


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int V, E;
		cin >> V >> E;
		Graph g(V);
		for (int j = 1; j <= E; ++j) {
			int va, vb;
			cin >> va >> vb;
			g.addEdge(va - 1, vb - 1);
		}
		int start;
		cin >> start;

		//for (auto &v : g.vv) {
			//for (auto &x : v) {
				//cout << x << " ";
			//}
			//cout << endl;;
		//}

		vector<int> res;
		BFS bfs(g, start - 1);
		//for (auto &x : bfs.distToStart) {
			//cout << x << " ";
		//}
		//cout << endl;
		for (int j = 0; j < V; ++j) {
			if (j == start - 1) { continue; }
			res.push_back(bfs.distToStart.at(j));
		}
		string resStr = accumulate(res.begin(), res.end(), string(""), [](const string& a, int b) {
			return (a.empty()) ? (to_string(b)) : (a + " " +  to_string(b));
		});
		cout << resStr << endl;
	}
}
