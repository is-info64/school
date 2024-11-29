#include <iostream>

int main(){
    int const N = 8;
    int arr[N] = {3, 7, 1, 9, 4, 5, 2, 8};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if(arr[i] > arr[i + 1]) {
				int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }

    double median = N % 2 ? arr[N / 2] : (arr[N / 2 - 1] + arr[N / 2]) / 2.0; // тернарный оператор if else (?:)
    /*if(N % 2 != 0) {
		median = arr[N / 2];
	}
	else {
		median = (arr[N / 2 - 1] + arr[N / 2]) / 2.0;
	}*/
    std::cout << median;
}
