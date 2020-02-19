#include <iostream>
#include <vector>

using namespace std;

void dutch_flag_partitioning(vector<int>& A, int pivot_index) {
    int pivot = A[pivot_index];
    // Unclassified items will be in the range ]equal,larger]
    int smaller = 0, equal = 0, larger = A.size() - 1;
    while (equal <= larger) {
        if (A[equal] < pivot) {
            swap(A[smaller++], A[equal++]);
        } else if (A[equal] == pivot) {
            ++equal;
        } else {    // A[equal] > pivot
            swap(A[equal], A[larger--]);
        }
    }
}

int main() {
    vector<int> v{4,5,2,3,6,11,7,6,1,6,8};
    cout << "Partitioning element == " << 2 << endl;
    for (auto x : v) {
        cout << x << " " ;
    }
    cout << endl;
    dutch_flag_partitioning(v, 4);
    for (auto x : v) {
        cout << x << " " ;
    }
    cout << endl;
}

