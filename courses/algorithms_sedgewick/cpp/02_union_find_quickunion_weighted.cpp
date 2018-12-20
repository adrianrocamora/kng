#include <iostream>
#include <vector>

class WeightedQuickUnion {
private:
    std::vector<int> v_, sz_;
    int get_root(int p) {
        while(v_.at(p) != p) {
            p = v_.at(p);
        }
        return p;
    }
public:
    WeightedQuickUnion(int N) {             // O(N)
        for (int i = 0; i < N; i++) {
            v_.push_back(i);
        }
        sz_.clear();
        sz_.resize(N,0);
    }
    ~WeightedQuickUnion() {}
    bool is_connected(int p, int q) {       // O(log N)
        return get_root(p) == get_root(q);
    }
    void merge(int p, int q) {              // O(log N)
        int pRoot = get_root(p);
        int qRoot = get_root(q);
		if (pRoot == qRoot) { return; }
        if (sz_.at(pRoot) < sz_.at(qRoot)) { 
			v_.at(pRoot) = qRoot; sz_.at(qRoot) += sz_.at(pRoot);
		} else { 
			v_.at(qRoot) = pRoot; sz_.at(pRoot) += sz_.at(qRoot); 
		}
    }
};

int main() {
    WeightedQuickUnion wqu(3);
    std::cout << "Expecting 0: " << wqu.is_connected(0,2) << std::endl;
    std::cout << "Expecting 0: " << wqu.is_connected(1,2) << std::endl;
    std::cout << "Expecting 0: " << wqu.is_connected(2,1) << std::endl;
    wqu.merge(0,2);
    std::cout << "Expecting 1: " << wqu.is_connected(0,2) << std::endl;
    std::cout << "Expecting 0: " << wqu.is_connected(1,2) << std::endl;
    std::cout << "Expecting 0: " << wqu.is_connected(2,1) << std::endl;
    wqu.merge(2,1);
    std::cout << "Expecting 1: " << wqu.is_connected(0,2) << std::endl;
    std::cout << "Expecting 1: " << wqu.is_connected(1,2) << std::endl;
    std::cout << "Expecting 1: " << wqu.is_connected(2,1) << std::endl;
}
