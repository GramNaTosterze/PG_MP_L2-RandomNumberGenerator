#include <stdint.h>
#include <stdbool.h>

#define X0 15
#define p 7
#define q 3
const int intSize = 32;
bool b[32] = {1, 0, 0, 1, 0,
               1, 1, 0, 0, 0,
               0, 0, 0, 0, 0,
               0, 0, 0, 0, 0,
               0, 0, 0, 0, 0,
               0, 0, 0, 0, 0,
               0, 0};

unsigned int binToDec(bool* bin, int size) {
	unsigned int dec = 0;
	int pow2 = 1;
	for( int i = 0; i < size; i++, pow2 = pow2<<1)
		dec += bin[size - i - 1]*pow2;
	return dec;
}

unsigned int xorshift() {
	for( int i = p; i < intSize; i++) {
		bool bt = b[i-p]^b[i-q];
		b[i] = bt;
	}
	unsigned int ret = binToDec(b,intSize);
	for (int i = 0; i < p; i++)
		b[i] = b[25 + i];
	return ret;
}
