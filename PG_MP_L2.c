#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define C 1
#define N 100000
#define A 69069
const long long M = pow(2,31);

#define X0 15
#define p 7
#define q 3
const int intSize = pow(2,sizeof(int));
unsigned int b = 0b11010010000000000000000000000000;
// 2 zadania 100000 liczb, całkowite od 0 do N-1
// 1 - 2.2
// 2 - 2.6

int rol(int val, int sh) {
	return val << sh | val >> (intSize - sh + 1);
}

unsigned int gen_liniowy(long long Xn) {
	return (A * Xn + C) % M;
}
void printBits(int num) {
	int maxPow = intSize;
	while(maxPow){
		printf("%u ", num&maxPow ? 1 : 0);
		maxPow >>= 1;
	}
	printf("\n");
}

bool btAt(int var, int pos) {
	int mask =  1 << pos;
    int masked_var = var & mask;
    return masked_var >> pos;
}

int setBit(int var, int pos, bool bit) {
	int mask = 1 << (pos - 1);
	return bit ? (var | mask) : (var & (~mask));
}

unsigned int gen_reg_shift() {
	b >>= (intSize - p);
	for( int i = p; i < intSize + p; i++) {
		bool bt = btAt(b, i - p)^btAt(b, i - q);
		b = setBit(b, i, bt);
	}
	printf("%u", b);
	return b;
}

long long binToDec(bool* bin, int size) {
	long long dec = 0;
	int pow2 = 1;
	for( int i = 0; i < size; i++, pow2 = pow2<<1)
		dec += bin[size - i - 1]*pow2;
		
	return dec;
}

int main() {
	unsigned int X_l[N], X_s[N];
	unsigned int count_l[10], count_s[10];
	for( int i = 0; i < 10; i++)
		count_l[i] = count_s[i] = 0;
	 
	X_l[0] = X0;
	for(int i = 1; i < N; i++)
		X_l[i] = gen_liniowy(X_l[i-1]);
	
	for(int i = 0; i < N; i++) {
		X_s[i] = gen_reg_shift();
		printf("%u\n", X_s[i]);
	}
	
	
	for( int i = 0; i < N; i++) {
		count_l[X_l[i]%10]++;
		count_s[X_s[i]%10]++;
	}
	printf("zad1:\n");
	for(int i = 0; i < 10; i++)
		printf("%d\n", count_l[i]);
	
	
	printf("zad2:\n");
	for(int i = 0; i < 10; i++)
		printf("%d\n", count_s[i]);

	
	printBits(12);
	printBits(setBit(12, 3, 0));

	return 0;
}
