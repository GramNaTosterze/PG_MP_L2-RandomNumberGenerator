#include <stdio.h>

#define N 100000
// 2 zadania 100000 liczb, całkowite od 0 do N-1
// 1 - 2.2
// 2 - 2.6

extern unsigned int _gen_reg_shift();
unsigned int xorshift();
unsigned int linearGenerator();

int main() {
	unsigned int X_l[N], X_s[N];
	unsigned int count_l[10], count_s[10];
	for( int i = 0; i < 10; i++)
		count_l[i] = count_s[i] = 0;
	 
	for(int i = 0; i < N; i++)
		X_l[i] = linearGenerator();
	
	for(int i = 0; i < N; i++)
		X_s[i] = xorshift();
	
	
	for( int i = 0; i < N; i++) {
		count_l[X_l[i]%10]++;
		count_s[X_s[i]%10]++;
	}
	printf("zad1:\n");
	for(int i = 0; i < 10; i++)
		printf("%d\n", count_l[i]);
	
	
	printf("\nzad2:\n");
	for(int i = 0; i < 10; i++)
		printf("%d\n", count_s[i]);

	return 0;
}
