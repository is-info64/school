#include <iostream>

int main(){
    int const N = 6;
    int arr[N] = {3, 7, 1, 2, 5, 9};
 
    int i_max = 0;
    int i_min = 0;

    for (int i = 0; i < N; ++i) {
        if(arr[i] < arr[i_min]) {
            i_min = i;
        }
          if(arr[i] > arr[i_max]) {
            i_max = i;
        }
    } 

    if (i_min > i_max) {
		int tmp = i_min;
		i_min = i_max;
		i_max = tmp;
    }

    int cnt = 0, sum = 0;
    for (int i = i_min + 1; i < i_max; ++i) {
        sum += arr[i];
        ++cnt;
    }

    if(cnt == 0) {
        std::cout << 0;
    }
    else{
        std::cout << (sum * 1.0) / cnt; // умножение на 1.0 необходимо, чтобы получился дробный результат
    }
}
