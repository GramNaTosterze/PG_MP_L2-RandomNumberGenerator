#include <stdint.h>
#include <stdbool.h>

#define X0 15
#define p 7
#define q 3
const int intSize = 32;
//uint32_t b = 0b1001011;
bool b[32] = {1, 0, 0, 1, 0,
               1, 1, 0, 0, 0,
               0, 0, 0, 0, 0,
               0, 0, 0, 0, 0,
               0, 0, 0, 0, 0,
               0, 0, 0, 0, 0,
               0, 0};

bool btAt(int var, int pos) {
	int mask =  1 << pos;
    int masked_var = var & mask;
    return masked_var >> pos;
}

int setBit(int var, int pos, bool bit) {
	int mask = 1 << (pos - 1);
	return bit ? (var | mask) : (var & (~mask));
}

unsigned int binToDec(bool* bin, int size) {
	unsigned int dec = 0;
	int pow2 = 1;
	for( int i = 0; i < size; i++, pow2 = pow2<<1)
		dec += bin[size - i - 1]*pow2;
	return dec;
}

unsigned int xorshift() {
	for( int i = p; i < intSize; i++) {
		bool bt = b[i-p]^b[i-q];//btAt(b, i - p)^btAt(b, i - q);
		b[i] = bt; //b = setBit(b, i, bt);
	}
	//printf("%u\n", b);
	//unsigned int ret  = b;
	//b >>= (intSize - p);
	unsigned int ret = binToDec(b,32);
	for (int i = 0; i < p; i++)
		b[i] = b[25 + i];
	return ret;
}
