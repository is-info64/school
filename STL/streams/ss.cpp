#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// PROTOBUF сериализация 
template <typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
	s << "[";	
	for(const auto& el : v) {
		s << el << ", ";	
	}
	s << "]\n";
	return s;
}

int main() {
typedef std::string str;

	{
		str s = "Hello my friend";
		std::stringstream ss(s);
		std::string word;
		while(ss >> word) {
			std::cout << word << "\n";
		}	
	}

	// чтение до разделителя
	{
		str s = "Hello,my,,friend";
		std::vector<str> result;
		std::stringstream ss(s);
		str item;
		while(std::getline(ss, item, ',')) {
			result.push_back(item);		
		}
		std::cout << result;
	}
}












