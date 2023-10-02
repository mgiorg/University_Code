#include <stdio.h>

void swap(int* a, int* b);

int main()
{
	int uno = 100;
	int due = 200;
	printf("%p , %p\n\n", &uno, &due);

	//swap(&uno, &due);
	uno += 250;
	due += 4;

	printf("%p , %p\n\n", &uno, &due);
	printf("%d , %d\n\n", uno, due);

	return 0;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}