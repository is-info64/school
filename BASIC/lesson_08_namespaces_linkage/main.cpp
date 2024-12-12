#include <iostream>
#include "math.h"
#include "kvedro.h"
/*
#include "math.h"
#ifndef MATH_H
#define MATH_H
namespace math{
	int square(int);
	const double PI = 3.14;
}
#endif

#include "kvedro.h"
#include "math.h"

#ifndef MATH_H
#define MATH_H
namespace math{
	int square(int);
	const double PI = 3.14;
}
#endif
namespace kvedro{
	extern int side;
	int calcSquare();
} 
*/


int main() {
	std::cout << kvedro::calcSquare();
}

