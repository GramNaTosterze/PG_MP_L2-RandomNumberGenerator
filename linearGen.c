#include <math.h>

#define C 1
#define A 69069
const long long M = pow(2,31);
unsigned int Xn = 15;

unsigned int linearGenerator() {
	return Xn = (A * Xn + C) % M;
}
