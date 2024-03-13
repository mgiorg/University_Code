#include <stdio.h>

void times2(short* p);
void times2_int(short* p);
void swap(char* x, char* y);
void swap_short(short* x, short* y);

int main() {
	short x = 10;
	short y = 15;
	swap_short(&x, &y);
	printf("x = %d, y = %d\n", x, y);

	return 0;
}