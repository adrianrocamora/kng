#include <iostream>
#include <list>

int main() {
    int data[] = {1, 2, 3, 4, 5};
    std::list<int> mylist(data, data+sizeof(data)/sizeof(data[0]));
    for (int x : mylist) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

