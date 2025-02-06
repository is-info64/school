#include <iostream>

// Определить сумму четных/нечетных элементов
// в зависимости от состояния isEven
/*
template<class T, class Sep>
T sumel(T* a, int N, Sep sep) {
	T sum = 0;
	for(int i = 0; i < N; ++i) {
		sum += sep(a[i]);
	}

	return sum;
}

int main() {
	int arr[] = {1,2,3,4,5};
	bool isEven;
	std::cin >> isEven;
	int sum = 0;
	sum = sumel<int>(arr, 5, [isEven](int a) { return a % 2 != isEven ? a : 0; });

	std::cout << sum << std::endl;
}*/

// Определить сумму четных/нечетных элементов
// в зависимости от состояния isEven и их количество

template<class T, class Sep>
T sumel(T* a, int N, Sep sep) {
	T sum = 0;
	for(int i = 0; i < N; ++i) {
		sum += sep(a[i]);
	}

	return sum;
}

int main() {
	int arr[] = {1,2,3,4,5};
	bool isEven;
	int cnt = 0;
	std::cin >> isEven;
	int sum = 0;
	sum = sumel<int>(arr, 5, [isEven, &cnt](int a) {
		if(isEven) {
			if(a % 2 == 0){
				++cnt;
				return a;
			}
		}
		else {
			if(a % 2 != 0){
				++cnt;
				return a;
			}
		}

		return 0;
	});

	std::cout << sum << "\t" << cnt << std::endl;
}














