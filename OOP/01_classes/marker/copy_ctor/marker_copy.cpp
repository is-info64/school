#include <iostream>

class Marker {
	
	static int N_MARKER = 0;

public:
	enum Color {
		RED, GREEN, BLUE, PINK, BLACK
	};
	const int MAX_BUFF = 100;
	Color color;
	char* buff;
	int num_chars;
	int capacity;
	
	int N;
	Marker() {
		color = Color::BLACK;
		num_chars = 0;
		capacity = MAX_BUFF;
		buff = new char[capacity];
		
		N = ++N_MARKER;
		std::cout << "default ctor: " << N << std::endl;
	}
		
	Marker(const Marker& rhs) {
		this->color = rhs.color;
		this->capacity = rhs.capacity;
		this->buff = new char[capacity];
		this->num_chars = 0;
		N = ++N_MARKER;
		std::cout << "copy ctor: " << N << std::endl;
	}
	
	/*Marker& operator=(const Marker& rhs) {
		this->color = rhs.color;
		this->capacity = rhs.capacity;
		//delete[] this->buff; // ! otherwise memory leack occur 
		this->~Marker(); // ! otherwise memory leack occur 
		this->buff = new char[capacity];
		this->num_chars = 0;
		N = ++N_MARKER;
		std::cout << "copy assign: " << N << std::endl;
		return *this;
	}*/
	//Marker(const Marker& m) = delete;
	Marker& operator=(const Marker& rhs)  = delete;
	~Marker() {
		std::cout << "dctor: " << N << std::endl;
		delete[] buff;
	}
	
	bool Write(char c) {
		if(num_chars == capacity) {
			return false;
		}
		
		buff[num_chars++] = c;
		return true;
	}
		
	void See() {
		for(int i = 0; i < num_chars; ++i) {
			std::cout << buff[i];
		}
		std::cout << std::endl;
	}
	
	void Erase() {
		num_chars = 0;
	}
	
};

void MarkerTest(Marker marker) {
	std::cout << "\t\tMarkerTest_start()" << std::endl;
	marker.See();
	std::cout << "\t\tMarkerTest_end" << std::endl;
}

void CopyCtorEx() {
	std::cout << "\t\tCopyCtorEx_start()" << std::endl;
	
	Marker m1;
	m1.Write('V');
	m1.Write('a');
	m1.Write('s');
	m1.Write('y');
	m1.Write('a');
	Marker m2 = m1;
	
	//MarkerTest(m1);
	m2.Write('P');
	m2.Write('e');
	m2.Write('t');
	m2.Write('y');
	m2.Write('a');
	m1.See();
	m2.See();
	m2.Erase();
	m1.See();
	m2.See();
	
	m2.Write('P');
	m2.Write('e');
	m2.Write('t');
	m2.Write('y');
	m2.Write('a');
	
	m1.See();
	std::cout << "\t\tCopyCtorEx_end" << std::endl;
}
void CopyAssignEx() {
	std::cout << "\t\tCopyAssignEx_start()" << std::endl;
	Marker m1, m2;
	m1.Write('V');	m1.Write('a');	m1.Write('s');	m1.Write('y');	m1.Write('a');
	m2.Write('P');	m2.Write('e');	m2.Write('t');	m2.Write('y');	m2.Write('a');
	m2 = m1;
	m2.Write('F');	m2.Write('e');	m2.Write('d');	m2.Write('o');	m2.Write('r');
	m1.See();
	m2.See();
	std::cout << "\t\tCopyAssignEx_end" << std::endl;
}
int main(){
   CopyAssignEx();
}
