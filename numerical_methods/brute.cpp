#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	double a = 1.0, b = 2.0;
	double x_0 = 1.4142135623730950488016887;

	for(int N = 3; N < 1000; ++N) {
		double step = (b - a) / N;
		double x_s = -1;
		double f_min = std::abs(a * a - 2);
		for(int i = 0; i < N; ++i) {
			double x = a + i * step;
			double f = std::abs(x * x - 2);
			if(f < f_min) {
				f_min = f;
				x_s = x;
			}
		}
		std::cout << N << "\t" << (x_0 - x_s) / x_0 << "\n";	
	}
}
