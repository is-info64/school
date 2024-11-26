#include <iostream>

int main(){
    int const N = 6;
    int arr[N] = {3, 7, 1, 2, 4, 9};
    int min = arr[0];
    int max = -1;
    int index_max = 0;
    int index_min = 0;
    int high_index = 0;
    int low_index = 0;
    int counter = 0;
    int sum = 0;
    int average = 0;

    for (int i = 0; i < N; ++i){
        if (min > arr[i]){
            min = arr[i];
            index_min = i;
        }
          if (max < arr[i]){
            max = arr[i];
            index_max = i;

        }
    } 

    if (index_min < index_max){
        high_index = index_max;
        low_index = index_min;
    }
    else{
        high_index = index_min;
        low_index = index_max;
    }

    for (int i = low_index + 1; i <= high_index - 1; ++i){
        sum += arr[i];
        counter += 1;
    }

    if (low_index + 1 == high_index - 1){
        average = arr[low_index + 1];
    }

    if(counter == 0){
        std::cout << average;
    }
    else{
        average = sum / counter;
        std::cout << average;
    }
    
}