#include <memory>
#include <iostream>

using namespace std;

template<typename T>
struct node_t {
    T val;
    shared_ptr<node_t<T>> next;
    node_t(T val_) : val(val_), next(nullptr) {}
};

template <typename T> 
shared_ptr<node_t<T>> reverse_linked_list(const shared_ptr<node_t<T>>& head) {
    shared_ptr<node_t<T>> prev = nullptr, curr = head;
    while (curr) {
        auto tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}

int main() {
    auto myList = make_shared<node_t<int>>(11);
    myList->next = make_shared<node_t<int>>(12);
    myList->next->next = make_shared<node_t<int>>(13);

    auto revList = reverse_linked_list<int>(myList);

    auto curr = myList;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    auto curr2 = revList;
    while (curr2) {
        cout << curr2->val << " ";
        curr2 = curr2->next;
    }
    cout << endl;
}
