#include <utility>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
    auto orig = make_pair(12,34);
    auto a = make_pair(12,34);
    auto b = make_pair(12,56);
    auto c = make_pair(512,34);
    auto d = make_pair(3124,13242);

    assert(orig == a);
    assert(orig != b);
    assert(orig != c);
    assert(orig != d);
}
