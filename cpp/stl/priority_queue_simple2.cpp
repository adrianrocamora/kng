#include <queue>
#include <iostream>
#include <vector>
#include <functional>

template <typename T>
void print_queue(T& q) {
    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    //std::priority_queue<int> q;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int n : {4,8,1,9,0,7,5,3,6,2}) {
        q.push(n);
    }
    //for (auto n : q) {    //WRONG, not initializer list type
    //for (int i = 0; i < q.size(); i++) {  //WRONG. q.size() changes on pop()
    //while (!q.empty()) {
        //std::cout << q.top() << " ";
        //q.pop();
    //}
    print_queue(q);

    std::cout << std::endl;
}



