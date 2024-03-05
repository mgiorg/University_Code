/**
 * e3.c
 * Quadrato di lato N
*/

#include <stdio.h>
#define N 7

int main()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}