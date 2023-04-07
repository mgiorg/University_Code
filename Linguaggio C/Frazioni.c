/**
 * main.c
 */

#include <stdio.h>

#define N 10

int main()
{
	int a = 0;
	int c = 0;
	int scan;

	scanf("%d", &scan);
	
	while(scan != 0)
	{
		c++;
		scanf("%d", &scan);
	}

	printf("\n\n%d", c);
	

	return 0;
}