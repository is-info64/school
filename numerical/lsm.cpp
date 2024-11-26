#include <iostream>
#include <cmath>

void TranjectoryModel(double a_0, double v_0, double x_end, double N);

int main() {
    double a_0 = 3.14 / 6.0;
    double v_0 = 20.0;
    double N = 50;

    TranjectoryModel(a_0, v_0, 35, N);
}

void TranjectoryModel(double a_0, double v_0, double x_end, double N) {
    std::cout << N << std::endl;
    double y = 0;
    double x = 0;
    double step = x_end / N;
    for (double x = 0; x < x_end; x += step) {
        y = x * tan(a_0) - (9.8 * (x * x)) / (2 * (v_0 * v_0) * (cos(a_0) * cos(a_0)));
        std::cout << x << "\t" << y << std::endl;
    }
}
