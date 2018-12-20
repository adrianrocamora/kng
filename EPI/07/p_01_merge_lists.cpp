#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct node_t{
	T data;
	shared_ptr<node_t<T>> next;
	node_t(T data_, shared_ptr<node_t<T>> next_) : data(data_), next(next_) {}
};

template<typename T>
void append_node(
		shared_ptr<node_t<T>> *head,
		shared_ptr<node_t<T>> *tail,
		shared_ptr<node_t<T>> *n) {
	*head ? (*tail)->next = *n : *head = *n;
	*tail = *n;
}

template<typename T>
void append_node_and_advance(
		shared_ptr<node_t<T>> *head,
		shared_ptr<node_t<T>> *tail,
		shared_ptr<node_t<T>> *n) {
	append_node(head, tail, n);
	*n = (*n)->next;
}

template<typename T>
shared_ptr<node_t<T>> mergeLists(
		shared_ptr<node_t<T>> F,
		shared_ptr<node_t<T>> L) {
	shared_ptr<node_t<T>> head = nullptr, tail = nullptr;
	while (F && L) {
		append_node_and_advance(&head, &tail, (F->data < L->data) ? &F : &L);
	}
	if (F) {
		append_node(&head, &tail, &F);
	}
	if (L) {
		append_node(&head, &tail, &L);
	}
	return head;
}

template<typename T>
void printList(
		shared_ptr<node_t<T>> L) {
	while (L) {
		cout << L->data << " ";
		L = L->next;
	}
	cout << endl;
}

int main() {
	auto a = make_shared<node_t<int>>(8, nullptr);
	auto b = make_shared<node_t<int>>(3, a);
	auto c = make_shared<node_t<int>>(1, b);
	printList(c);

	auto f = make_shared<node_t<int>>(9, nullptr);
	auto g = make_shared<node_t<int>>(4, f);
	auto h = make_shared<node_t<int>>(0, g);
	printList(h);

	printList(mergeLists(c, h));
}
