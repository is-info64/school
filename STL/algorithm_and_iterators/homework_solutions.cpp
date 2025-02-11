#include <iostream>
#include <algorithm>
#include <string>

int main() {

	/*
		5 String to Int
		[STL/03_templates/task05.cpp]
		Remember the theme of the expanded 
		form of the number (number systems). 
		Write a function that
		returns an integer value passed to it in a string:
		int a = strToInt(“345”); // a <= 345
	*/
	std::string s1 = "123";
	int res = 0;
	std::for_each(s1.begin(), s1.end(), [&res](char c) {
		res = res * 10 + c - '0'; // 123
	});
	std::cout << res << std::endl;
	
	/*
		2 Looks like a Number
		[STL/03_templates/task02.cpp]
		Create a string consisting of digits and letters. 
		Display all the digits contained in the string,
		separated by commas. Try to make sure that the comma
		is not displayed after the last digit.	
	*/
	std::string s = "3h45u15hjk6l";
	bool isFirst = true;
	std::for_each(s.begin(), s.end(), [&isFirst](const char c) { 
			if(std::isdigit(c)) { 
				if(!isFirst) {
					std::cout << ", ";				
				}
				else{
					isFirst = false;				
				}
				std::cout << c; 
			}
	});
}