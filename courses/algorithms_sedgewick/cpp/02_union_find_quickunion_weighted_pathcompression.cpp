#include <iostream>
#include <vector>
#include <numeric>

class CompressedWeightedQuickUnion {
private:
    std::vector<int> v_, sz_;
    int get_root(int p) {
        // We could add another loop and set the id[] corresponding to each entry to the root
        // But one trick is to use the one-pass variant and make every other node point to its
        // grandparent
        while (p != v_.at(p)) {
            v_.at(p) = v_.at(v_.at(p));
            p = v_.at(p);
        }
        return p;
    }
public:
    CompressedWeightedQuickUnion(int N) {                                 // O(N)
        v_.clear();     // Equivalent to resize(0) using modern compilers
        v_.resize(N);
        std::iota(std::begin(v_), std::end(v_), 0);
        sz_.clear();
        sz_.resize(N, 0);
    }
    ~CompressedWeightedQuickUnion() {}
    bool is_connected(int p, int q) { return get_root(p) == get_root(q);} // O(log N), amortized O(1)  
    void merge(int p, int q) {                                            // O(log N), amortized O(1)
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
    CompressedWeightedQuickUnion cwqu(3);
    std::cout << "Expecting 0: " << cwqu.is_connected(0,2) << std::endl;
    std::cout << "Expecting 0: " << cwqu.is_connected(1,2) << std::endl;
    std::cout << "Expecting 0: " << cwqu.is_connected(2,1) << std::endl;
    cwqu.merge(0,2);
    std::cout << "Expecting 1: " << cwqu.is_connected(0,2) << std::endl;
    std::cout << "Expecting 0: " << cwqu.is_connected(1,2) << std::endl;
    std::cout << "Expecting 0: " << cwqu.is_connected(2,1) << std::endl;
    cwqu.merge(2,1);
    std::cout << "Expecting 1: " << cwqu.is_connected(0,2) << std::endl;
    std::cout << "Expecting 1: " << cwqu.is_connected(1,2) << std::endl;
    std::cout << "Expecting 1: " << cwqu.is_connected(2,1) << std::endl;
}
