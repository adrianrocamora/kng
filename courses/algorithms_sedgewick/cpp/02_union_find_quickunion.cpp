#include <iostream>
#include <vector>

class QuickUnion {
private:
    std::vector<int> v_;
    int get_root(int p) {
        while (v_.at(p) != p) {
            p = v_.at(p);
        }
        return p;
    }
public:
    QuickUnion(int N) {                 // O(N)
        for (int i = 0; i < N; i++) {
            v_.push_back(i);
        }
    }
    ~QuickUnion() {}
    bool is_connected(int p, int q){    // O(N)
        return get_root(p) == get_root(q);
    }
    void merge(int p, int q) {          // O(N) 
        int pRoot = get_root(p);
        int qRoot = get_root(q);
        if (pRoot == qRoot) { return;}
        v_.at(pRoot) = qRoot;
    }
};

int main() {
    QuickUnion qu(3);
    std::cout << "Expecting 0: " << qu.is_connected(0,2) << std::endl;
    std::cout << "Expecting 0: " << qu.is_connected(0,1) << std::endl;
    std::cout << "Expecting 0: " << qu.is_connected(1,2) << std::endl;
    qu.merge(0,2);
    std::cout << "Expecting 1: " << qu.is_connected(0,2) << std::endl;
    std::cout << "Expecting 0: " << qu.is_connected(0,1) << std::endl;
    std::cout << "Expecting 0: " << qu.is_connected(1,2) << std::endl;
    qu.merge(2,1);
    std::cout << "Expecting 1: " << qu.is_connected(0,2) << std::endl;
    std::cout << "Expecting 1: " << qu.is_connected(0,1) << std::endl;
    std::cout << "Expecting 1: " << qu.is_connected(1,2) << std::endl;
}

