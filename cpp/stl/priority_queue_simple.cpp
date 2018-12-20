#include <iostream>
#include <queue>

template<typename T> void print_queue(T& q) { while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    // Provides constant time lookup of the largest element (default)
    std::priority_queue<int> q;
    for (int n : {1,8,5,6,3,4,0,9,7,2}) {
        q.push(n);
    }
    print_queue(q);
}
// Output: 
//   9 8 7 6 5 4 3 2 1 0 
