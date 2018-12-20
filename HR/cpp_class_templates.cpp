#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


template<typename T>
class AddElements {
private:
    T elem_;
public:
    AddElements(T elem) : elem_(elem) {}
    T add(const T& other_elem) {
        T sum;
        sum = elem_ + other_elem;
        return sum;
    }
};

template<>
class AddElements<string> {
private:
    string str_;
public:
    AddElements(string str) : str_(str) {}
    string concatenate(const string& other) {
        return str_ + other;
    }
};

int main () {
    int n,i;
    cin >> n;
    for(i=0;i<n;i++) {
        string type;
        cin >> type;
        if(type=="float") {
            double element1,element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat (element1);
            cout << myfloat.add(element2) << endl;
        }
        else if(type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint (element1);
            cout << myint.add(element2) << endl;
        }
        else if(type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring (element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
