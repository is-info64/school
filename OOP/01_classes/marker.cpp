#include <iostream>
#include "marker.h"

Marker::Marker() {
	color = Color::BLACK;
	capacity = MAX_BUFF;
	num_chars = 0;
	buff = new char[capacity];
}
Marker::~Marker() {
	delete[] buff;
}
void Marker::erase() {
	num_chars = 0;
}

bool Marker::write(char c) {
	if(num_chars >= capacity) {
		return false;
	}
	
	buff[num_chars++] = c;	
	return true;
}

void Marker::see() {
	std::cout << "\033[1;" << color << "m";
	for(int i = 0; i < num_chars; ++i) {
		std::cout << buff[i];
	}
	std::cout << "\033[0m\n";
}
