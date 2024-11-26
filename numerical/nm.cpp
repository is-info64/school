#include <iostream>
#include <cmath>


double brute_force (double, double, int);
double bisection (double, double, int);
double integral (double, double, int);
double func_value(double arg);

int main(){
	std::cout << brute_force(1, 2, 3) << std::endl;
	std::cout << bisection(1, 2, 3) << std::endl;
	std::cout << integral(0.0, 2*3.14, 0.0001) << std::endl;
}

double func_value(double arg) {
	return std::abs(arg * arg - 2);
}

double brute_force(double a_0, double b_0, int N){
    double a = a_0;
	double b = b_0;
	double f_current;					
	double f_minimum;
	double x = 0;
    double x_ideal = 1.4142135623730950488;
	double pogrehnost;
	double step = std::abs(a - b) / N;
	
		f_minimum = func_value(a);
	
			
		for(int i = 0; i < N; ++i)
		{
			f_current = func_value(a + i * step);
			
			if (std::abs(f_current) < std::abs(f_minimum))
			{
				f_minimum = f_current;
				x = a + i * step;	
									
			}
	 
		}

        return x;
}

double bisection (double a_0, double b_0, int N){
    double a = a_0;
	double b = b_0;	
	double x = 0;
    double x_ideal = 1.4142135623730950488;
	
	
	for(int N_1 = N; N_1 <= 100; ++N_1) 
	{
		x =(a+b)/2;

		if(func_value(x) * func_value(b) > 0)	{
			b = x;
		} 
		else {
			a = x;
		}
	}	

    return x;
}

double integral (double a_0, double b_0, int N){
    double a = a_0;
    double b = b_0;
    double delta_x = (b - a) / N;
    double integral = 0;
    double delta_y = 0;
    double squar = 0;

    for(double i = a; i < b; i = i + delta_x){
        delta_y = func_value(i);
        squar = delta_x*delta_y;
        integral = integral + squar;
    }

    return integral;
}

