#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
	int x;
	int y;
	Point(int a, int b) : x(a), y(b) {}
};
bool cmp_points_x(const Point& a, const Point& b) {
	return a.x < b.x;
}
bool cmp_points_y(const Point& a, const Point& b) {
	return a.y < b.y;
}
int main() {
	std::vector<Point> v;
	v.push_back(Point(2,3));
	v.push_back(Point(4,1));
	std::cout << v[0].x << " " << v[0].y << std::endl;	//2 3
	std::cout << v[1].x << " " << v[1].y << std::endl;	//4 1
	std::sort(v.begin(), v.end(), cmp_points_y);
	std::cout << v[0].x << " " << v[0].y << std::endl;	//4 1
	std::cout << v[1].x << " " << v[1].y << std::endl;	//2 3
	return 0;
}
