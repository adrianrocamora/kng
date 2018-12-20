#include <iostream>
#include <vector>

class QuickFind {
private:
    std::vector<int> v_;
public:
    QuickFind(int N) {                  // O(N)
        for (int i = 0; i < N; i++) {
            v_.push_back(i);
        }
    }
    ~QuickFind() {}
    bool is_connected(int p, int q) {   // O(1)
        return v_.at(p) == v_.at(q);
    }
    void merge(int p, int q) {          // O(N)
        int pId = v_.at(p); 
        int qId = v_.at(q);
        for (int i = 0; i < v_.size(); i++) {
            if (v_.at(i) == pId) { v_.at(i) = qId;}
        }
    }
};
int main() {
    QuickFind qf(3);
    std::cout << "Expecting 0: " << qf.is_connected(0,1) << std::endl;
    std::cout << "Expecting 0: " << qf.is_connected(0,2) << std::endl;
    std::cout << "Expecting 0: " << qf.is_connected(1,2) << std::endl;
    qf.merge(0,2);
    std::cout << "Expecting 0: " << qf.is_connected(0,1) << std::endl;
    std::cout << "Expecting 1: " << qf.is_connected(0,2) << std::endl;
    std::cout << "Expecting 0: " << qf.is_connected(1,2) << std::endl;
    qf.merge(2,1);
    std::cout << "Expecting 1: " << qf.is_connected(0,1) << std::endl;
    std::cout << "Expecting 1: " << qf.is_connected(0,2) << std::endl;
    std::cout << "Expecting 1: " << qf.is_connected(1,2) << std::endl;
}

