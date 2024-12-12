#include "kvedro.h"
#include "math.h"

int kvedro::side = 10;

int kvedro::calcSquare() {
	return math::square(side);
}