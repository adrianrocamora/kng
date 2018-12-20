#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    //Output:
    //1,2,3,4,5,6,7,8,9,10,
}
