#include <iostream>
#include <exception>
#include <algorithm>

template <class T>
class vector {
public:
	vector() : size_ (0) {
		arr_ = new T[capacity_];
	}

	vector(int size) : size_ (size) {
		if(size_ > capacity_) {
			capacity_ = size_;
		}	
		
		arr_ = new T[capacity_];
	}
	
	void append(T value) {
		if(size_ < capacity_) {
			arr_[size_++] = value;
			return;
		}

		capacity_ *= 2;	
		T* new_arr = new T[capacity_];
		for(int i = 0 ; i < size_; ++i) {
			new_arr[i] = arr_[i];		
		} 

		new_arr[size_++] = value;
		delete[] arr_;
		arr_ = new_arr; // memory leack	
	}	

	void set(T value, int i) {
		if(i >= size_) {
			throw std::range_error("index out of range :)");		
		}

		arr_[i] = value;	
	}

	T get(int i) {
		return arr_[i];	
	}

	int size() {
		return size_;	
	}

	int capacity() {
		return capacity_;	
	}
	T* begin(){
		return arr_;	
	}

	T* end(){
		return arr_ + size_;	
	}

private:
	T* arr_;
	int capacity_ = 2;
	int size_ = 0;
};

int main() {
	vector<int> v;
	v.append(2);
	v.append(4);
	std::cout << v.size() << "\t" << v.capacity() << std::endl;
	v.append(1);
	std::cout << v.size() << "\t" << v.capacity() << std::endl;
	v.append(3);
	std::cout << v.size() << "\t" << v.capacity() << std::endl;
	v.append(5);
	std::cout << v.size() << "\t" << v.capacity() << std::endl;

	std::sort(v.begin(), v.end());
	for(size_t i = 0; i < v.size(); ++i) {
		std::cout << v.get(i) << " ";	
	}
	
}