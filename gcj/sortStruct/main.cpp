// Just a quick overview illustrating how to sort structures in C++
// 
#include <iostream>
#include <algorithm>

struct Point
{
	int id;
	int x;
	int y;
	// Another option is to overload the < operator
    //bool operator<(const a& rhs) const { num1 < rhs.num1; }
};

bool compare_points_x_ascending(Point lhs, Point rhs) { return lhs.y < rhs.y; }
bool compare_points_x_descending(Point lhs, Point rhs) { return lhs.y > rhs.y; }


int main()
{
	Point points[5];
	Point pointsAscending[5];
	Point pointsDescending[5];

	points[0].id = 0;
	points[0].x = -1;
	points[0].y = 6;

	points[1].id = 1;
	points[1].x = 0;
	points[1].y = 3;

	points[2].id = 2;
	points[2].x = 1;
	points[2].y = 2;

	points[3].id = 3;
	points[3].x = 2;
	points[3].y = 3;

	points[4].id = 4;
	points[4].x = 3;
	points[4].y = 6;

	memcpy(pointsAscending, points, 5*sizeof(Point));
	memcpy(pointsDescending, points, 5*sizeof(Point));

	std::sort(pointsAscending, pointsAscending+5, compare_points_x_ascending);
	std::sort(pointsDescending, pointsDescending+5, compare_points_x_descending);

	std::cout << "Largest y is: " << pointsDescending[0].y << std::endl;
	std::cout << "Its corresponding x is: " << pointsDescending[0].x << std::endl;
	std::cout << "Its corresponding id is: " << pointsDescending[0].id << std::endl;

	std::cout << std::endl;

	std::cout << "Smallest y is: " << pointsAscending[0].y << std::endl;
	std::cout << "Its corresponding x is: " << pointsAscending[0].x << std::endl;
	std::cout << "Its corresponding id is: " << pointsAscending[0].id << std::endl;
}
