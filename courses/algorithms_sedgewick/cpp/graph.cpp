#include <iostream>
#include <vector>
#include <unordered_set>

class Graph {
private:
    int V_;      // Number of vertices
    int E_;      // Number of vertices
    std::vector<std::unordered_set<int>> adj_;
public:
    Graph(int V) {
        V_ = V;
        E_ = 0;
        adj_ = std::vector<std::unordered_set<int>>(V);
    }
    ~Graph() {}
    int V() {
        return V_;
    }
    std::unordered_set<int> adj(int v){
        return adj_[v];
    }
    void addEdge(int v, int w) {
        if (v >= V_ || w >= V_) {
            throw std::runtime_error("Out of range vertex");
        }
        adj_[v].insert(w);
        adj_[w].insert(v);
        E_++;       // Parallel edges allowed
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,4);
    std::cout << "Number of vertices: " << g.V() << std::endl;
    for (int v = 0; v < g.V(); v++) {
        for (auto &w : g.adj(v)) {
            std::cout << v << '-' << w << std::endl;
        }
    }
}
