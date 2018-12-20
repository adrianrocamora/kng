#include <iostream>
#include <vector>

//-1234567
using namespace std;

template <typename T> 
class BinaryHeap {
private:
	// Skip the 0 position for ease of implementation
	vector<T> data_;
	int size_;
	int leftChildIdx(int idx) {
		return idx*2;
	}
	int rightChildIdx(int idx) {
		return idx*2+1;
	}
	int parentIdx(int idx) {
		return idx/2;
	}
	//void swimUp(
public: 
	void push(T x) {
		//if (size_ < data_.size())
	}
	T getMin() {
		if (size_ < 1) { throw exception();}
		return data_[0];
	}
	void popMin() {
	}
};

int main() {
	BinaryHeap<int> bh;
	for (auto x : {1,5,3,7,4}) {
		bh.push(x);
	}
	cout << bh.getMin() << endl;
	bh.popMin();
	cout << bh.getMin() << endl;

}

