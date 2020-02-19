#include <iostream>

using namespace std;

template<typename T>
struct node_t{
    T val;
    shared_ptr<node_t<T>> next;
}


template<typename T> 
void zipping_linked_list(const shared_ptr<node_t<T>>& L) {
    shared_ptr<node_t<T>> slow = L, fast = L, pre_slow = nullptr;

    // Find the middle point of L
    while(fast) {
        fast = fast->next;
        if (fast) {
            pre_slow = slow;
            fast = fast->next, slow = slow->next;
        }
    }
    if (!pre_slow) { // There's only one node in the list
        return L;
    }


