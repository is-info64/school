#include <iostream>

struct OverflowExc {
	int max_size;
	OverflowExc(int size) : max_size(size) { }
};

struct MaxCapacityEx {
	int max_size;
	MaxCapacityEx(int size) : max_size(size) { }
};

struct Exception {
	const char* mess;
	Exception(const char* m) : mess(m) { }
};

class Marker {
public:
	enum Color {
		RED = 31, GREEN = 32, BLACK = 30, PINK = 35
	};
	
	const static int MAX_BUFF = 100;
	
	Marker() : Marker(MAX_BUFF, Color::BLACK) {	}
	
	Marker(unsigned int capacity, Color color = Color::PINK) 
			: capacity_(capacity), color_(color) {
		num_chars_ = 0;
		
		if(capacity_ > MAX_BUFF) {
			throw MaxCapacityEx(MAX_BUFF);
		}
		
		buff_ = new char[capacity_];
		std::cout << "default ctor" << std::endl;
	}
		
	Marker(const Marker& rhs) {
		this->color_ = rhs.color_;
		this->capacity_ = rhs.capacity_;
		this->buff_ = new char[capacity_];
		this->num_chars_ = 0;
		std::cout << "copy ctor" << std::endl;
	}
	
	Marker& operator=(const Marker& rhs) {
		this->color_ = rhs.color_;
		this->capacity_ = rhs.capacity_;
		this->~Marker(); // ! otherwise memory leack occur 
		this->buff_ = new char[capacity_];
		this->num_chars_ = 0;
		std::cout << "copy assign" << std::endl;
		return (*this);
	}
	
	~Marker() {
		std::cout << "dctor" << std::endl;
		delete[] buff_;
	}
	
	Marker& Write(char c) {
		if(num_chars_ == capacity_) {
			throw OverflowExc(capacity_);
		}
		
		if(c < 32 /*[space]*/ || c > 126 /*~*/) {
			throw Exception("bad char code");
		}
		
		buff_[num_chars_++] = c;
		return (*this);
	}
		
	void See() {
		std::cout << "\033[1;" << color_ << "m";
		for(int i = 0; i < num_chars_; ++i) {
			std::cout << buff_[i];
		}
		std::cout << "\033[0m\n" << std::endl;
	}
	
	void Erase() {
		num_chars_ = 0;
	}
private:
	int num_chars_;
	unsigned int capacity_;
	Color color_;
	char* buff_;
};

int main() {
	try {
		Marker m(2);
		m.Write('h').Write(120).Write('!');
		m.See();
	}
	catch(MaxCapacityEx exc) {
		std::cout << "[Error]: capacity exception: " << exc.max_size << std::endl;
	}
	catch(OverflowExc exc) {
		std::cout << "[Error]: max num of chars: " << exc.max_size << std::endl;
	}
	catch(Exception ex)	{
		std::cout << "[Error]: " << ex.mess << std::endl;
	}
	catch {
		std::cout << "[Error]: undefined" << std::endl;
	}
	
}
