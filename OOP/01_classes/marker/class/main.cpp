#include <iostream>
#include "marker.h"

int main() {
	Marker m;
	m.color = Marker::Color::PINK;
	m.write('h');
	m.write('e');
	m.write('l');
	m.write('l');
	m.write('o');
	
	m.see();
}
