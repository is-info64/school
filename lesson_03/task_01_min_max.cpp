#include <iostream>

int main(){

    int const N = 6;
    int arr[N] = {3, 7, 1, 9, 2, 4};
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < N; ++i){
        if (min > arr[i]){
            min = arr[i];
        }
          if (max < arr[i]){
            max = arr[i];
        }
    } 

    std::cout << min << std::endl;
    std::cout << max << std::endl;
}