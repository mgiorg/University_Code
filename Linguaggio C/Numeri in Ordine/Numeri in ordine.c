/**
 * Numeri in ordine.c
 */

/**
 * 	Scrivere un programma in linguaggio C che,
	letti tre numeri interi a, b, c dallo standard
	input, stampi a terminale la sequenza dei tre
	numeri in ordine monotono non decrescente
 */

#include <stdio.h>

int main()
{
	int a, b, c;
	int x, y, z;

	scanf("%d, %d, %d", &a, &b, &c);

	if(a <= b)
	{
		if(a <= c)
		{
			x = a;

			if(b <= c)
			{
				y = b;
				z = c;
			}
			else
			{
				y = c;
				z = b;
			}
		}
		else
		{
			x = c;
			y = a;
			z = b;
		}
	}
	else if (a > b)
	{
		if(a <= c)
		{
			x = b;
			y = a;
			z = c;

		}
		else
		{
			x = b;
			y = c;
			z = a;
		}
	}
	printf("a: %d, b: %d, c: %d", x, y, z);

	return 0;
}