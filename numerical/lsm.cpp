#include <iostream>
#include <cmath>

void TranjectoryModel(double a_0, double v_0, double N);

int main(){
    double a_0 = 3.14 / 6.0;
    double v_0 = 10.0;
    double N = 50;
    
    TranjectoryModel(a_0, v_0, N);
}

void TranjectoryModel(double a_0, double v_0, double N){
        std::cout << N << std::endl;
        double y = 0;
        double x = 0;
        double step = 30 / N;
        for(int i = 0; i < N; ++i){
            x = i * N;
            y = x * tan(a_0) - (9.8 * (x*x)) / (2*(v_0*v_0) * (cos(a_0)*cos(a_0)));
            std::cout << x << "\t" << y << std::endl;
            if(x == 30){
                break;
            }
            
        }   
        
    }