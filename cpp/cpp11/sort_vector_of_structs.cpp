#include <iostream>
#include <vector>
#include <algorithm>

struct Point { 
    double x;
    double y;
    Point(double inX, double inY) : x(inX), y(inY) {}
};
int main() {
    std::vector<Point> v = {Point(2, 5), Point(0, 0), Point(3, 7), Point(1, 3)};
    for (auto& p : v) {
        std::cout << p.x << ", " << p.y << std::endl;
    }
    std::cout << "Sorting vector based on 'y' element" << std::endl;
    std::sort(v.begin(), v.end(), [](const Point& a, const Point& b) {return a.y < b.y;});
    for (auto& p : v) {
        std::cout << p.x << ", " << p.y << std::endl;
    }
}
