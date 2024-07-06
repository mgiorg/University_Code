#include <stdio.h>

void times2(short* p);
void times2_int(short* p);
void swap(char* x, char* y);
void swap_short(short* x, short* y);

int main() {
	short x = 10;
	times2_int(&x);
	printf("x = %d\n", x);

	return 0;
}