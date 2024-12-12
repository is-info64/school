#include <iostream>
#include <cmath>

void TranjectoryModel(double a_0, double v_0, double x_end, int N);

int main() {
    double a_0 = 3.14 / 6.0;
    double v_0 = 20.0;
    double N = 50;

    TranjectoryModel(a_0, v_0, 35, N);
    double* x_exp;
    double* y_exp;	
    int N = ReadData(x_exp, y_exp);
    //Params sol = Solution(...);
    delete[] x_exp;
    delete[] y_exp;
}

void TranjectoryModel(double a_0, double v_0, double x_end, int N) {
    std::cout << N << std::endl;
    double 	x = 0, 
			y = 0,
			step = x_end / N;
			
    for (double x = 0; x < x_end; x += step) {
        y = x * tan(a_0) - (9.8 * (x * x)) 
				/ (2 * (v_0 * v_0) * (cos(a_0) * cos(a_0)));
        std::cout << x << "\t" << y << std::endl;
    }
}

int ReadData(double* exp_x, double* exp_y){
    int N;
    std::cin >> N;

    exp_x = new double[N];
    exp_y = new double[N];

    for(int i = 0; i < N; ++i){
        std::cin >> exp_x[i] >> exp_y[i];
    }

    return N;
}
