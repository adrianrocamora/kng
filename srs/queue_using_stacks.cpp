#include <iostream>
#include <stack>
template <typename T>
class Queue {
private:
    std::stack<T> inStack_;
    std::stack<T> outStack_;
public:
    Queue() {};
    ~Queue() {};
    bool isEmpty() {
        return inStack_.empty() && outStack_.empty();
    }
    void push(const T& in) {
        inStack_.push(in);
    }
    // Return by value here
    T front() {
        T tmpT;
        if (isEmpty()) { throw std::exception();}
        if (!outStack_.empty()) {
            tmpT = outStack_.top();
        }
        else {
            while (!inStack_.empty()) {
                tmpT = inStack_.top();
                inStack_.pop();
                outStack_.push(tmpT);
            }
        }
        return tmpT;
    }
    void pop() {
        if (isEmpty()) { throw std::exception();}
        if (!outStack_.empty()) {
            outStack_.pop();
        }
        else {
            while (!inStack_.empty()) {
                T tmpT = inStack_.top();
                inStack_.pop();
                outStack_.push(tmpT);
            }
            outStack_.pop();
        }
    }
};

int main() {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << (q.isEmpty() ? "Is empty. " : "Not empty. ") << q.front() << std::endl;
    q.pop();
    std::cout << (q.isEmpty() ? "Is empty. " : "Not empty. ") << q.front() << std::endl;
    q.pop();
    std::cout << (q.isEmpty() ? "Is empty. " : "Not empty. ") << q.front() << std::endl;
    q.pop();
    std::cout << (q.isEmpty() ? "Is empty. " : "Not empty. ") << std::endl;
}
