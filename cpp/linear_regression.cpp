#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

double slope(const std::vector<double>& x, const std::vector<double>& y)
{
    double n    = x.size();
    double s_x  = std::accumulate(x.begin(), x.end(), 0.0);
    double s_y  = std::accumulate(y.begin(), y.end(), 0.0);
    double s_xx = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
    double s_xy = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
    double a    = (n * s_xy - s_x * s_y) / (n * s_xx - s_x * s_x);
    return a;
}

int main()
{
    std::vector<double> x{6, 5, 11, 7, 5, 4, 4};
    std::vector<double> y{2, 3, 9, 1, 8, 7, 5};
	double n    = x.size();
	double s_x  = std::accumulate(x.begin(), x.end(), 0.0);
	double s_y  = std::accumulate(y.begin(), y.end(), 0.0);
	double s_xx = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
	double s_xy = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
    double b    = (n * s_xy - s_x * s_y) / (n * s_xx - s_x * s_x);
    std::cout << b << std::endl;
	return 0;
}
