#include <iostream>
#include <string>

// PROTOBUF сериализация 

std::ostream& operator ^ (std::ostream& s, const char& c) {
	s.put(c);
	return s;
}

std::ostream& operator^(std::ostream& s, const std::string& str) {
	s.write(str.c_str(), str.size());
	return s;
}

int main() {
	std::cout.put('H').write("ello, world!\n", 13);
	std::cerr ^ 'H' ^ "ello, world!\n";
}