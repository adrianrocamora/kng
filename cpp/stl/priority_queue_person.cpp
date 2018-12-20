#include <iostream>
#include <ostream>
#include <queue>

class Person {
private:
    int age_;
    std::string name_;
public:
    Person(std::string name, int age) : name_(name), age_(age) {}
    ~Person() {}
    Person(const Person& v) : name_(v.name_), age_(v.age_) {}
    Person& operator=(const Person& v) {
        if (&v != this) {
            age_ = v.age_;
            name_ = v.name_;
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Person& v) {
        os << v.name_ << ": " << v.age_ << std::endl;
    }
    struct LessThanByAge {
        bool operator()(const Person& lhs, const Person& rhs) const {
            return lhs.age_ < rhs.age_;
        }
    };
};

int main() {
    // Provides constant time lookup of the largest element (default)
    // at the cost of O(N log N) for build- up
    std::priority_queue<Person, std::vector<Person>, Person::LessThanByAge> q;
    q.push(Person("John", 29));
    q.push(Person("Pedro", 22));
    q.push(Person("Mike", 33));
    Person tmp = q.top();
    q.pop();
    std::cout << tmp;
    tmp = q.top();
    q.pop();
    std::cout << tmp;
    tmp = q.top();
    q.pop();
    std::cout << tmp;
}

