#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


// NOTE: Wrong approach to the problem


using namespace std;

// 1-based
class UnionFind {
private:
    vector<int> v;
public:
    UnionFind(int V) {
        for (int i = 1; i <= V; ++i) {
            v.push_back(i);
        }
    }
    bool areConnected(int a, int b) {
        return v.at(a - 1) == v.at(b - 1);
    }
    void merge(int a, int b) {
        int a_id = v.at(a - 1);
        int b_id = v.at(b - 1);
        for (int i = 0; i < v.size(); ++i) {
            if (v.at(i) == a_id) {
                v.at(i) = b_id;
            }
        }
    }
};

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int V, E;
        cin >> V >> E;
        UnionFind uf(V);
        for (int j = 1; j <= E; ++j) {
            int va, vb;
            cin >> va >> vb;
            uf.merge(va, vb);
        }
        int start;
        cin >> start;
        vector<int> res;
        for (int j = 1; j <= V; ++j) {
            if (j == start) { continue; }
            if (uf.areConnected(start, j)) {
                res.push_back(6);
            } else {
                res.push_back(-1);
            }
        }
        cout << accumulate(res.begin(), res.end(), string(""), [](const string& a, int b) {
                return (a.empty()) ? (to_string(b)) : (a + " " +  to_string(b));
            }) << endl;

    }
}
