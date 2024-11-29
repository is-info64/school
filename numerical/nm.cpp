#include <iostream>
#include <cmath>

double brute_force (double, double, int);
double bisection (double, double, int);
double integral (double, double, int);
double f(double arg);

int main(){
	std::cout << brute_force(1, 2, 100) << std::endl;
	std::cout << bisection(1, 2, 100) << std::endl;
	std::cout << integral(0.0, 2*3.14, 100) << std::endl;
}

double f(double x) {
	return x * x - 2;
}

double brute_force(double a, double b, int N) {			
	double step = std::abs(a - b) / N;
	double f_minimum = std::abs(f(a));
	double solution = a;	
	for(int i = 0; i < N; ++i) {
		double f_current = std::abs(f(a + i * step));
		
		if (f_current < f_minimum) {
			f_minimum = f_current;
			solution = a + i * step;					
		}
	}

	return solution;
}

double bisection(double a, double b, int N) {
	for(int i = 0; i <= N; ++i) 
	{
		double c = (a + b) / 2;
		
		if(f(a) * f(c) < 0)	{
			b = c;
		} 
		else {
			a = c;
		}
	}	

    return (a + b) / 2;
}

double integral(double a, double b, int N) {
    double delta_x = (b - a) / N;
    double integral = 0;
    
    for(double x = a; x < b; x += delta_x) {
        integral += delta_x * f(x);
    }

    return integral;
}

