#include <iostream>

int main(){

    int const N = 7;
    int arr[N] = {3, 7, 1, 9, 4, 2, 8};
    int high = 0;
    int low = 0;
    int median = 0;

    for (int j = 0; j < N; ++j){
        for (int i = 0; i < N - 1; ++i){
            if(arr[i] > arr[i + 1]){
                high = arr[i];
                low = arr[i + 1];
                arr[i] = low;
                arr[i + 1] = high;
            }
        }
    }

    median = arr[N/2];
    std::cout << median;
}