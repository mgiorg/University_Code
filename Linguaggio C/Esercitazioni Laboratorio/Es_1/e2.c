/**
 * e2.c
 * Media da tastiera
 * Esc = 0
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int temp = 1;
	float media = 0.0f;
	int i = 0;

	printf("Inserire valori da tastiera: \n");

	while(temp != 0)
	{
		
		scanf("%d", &temp); 
		if (temp == 0) break;

		printf("Temp = %d\n", temp);
		
		media+= temp;

		++i;
	}
	media = media /i;
	printf("La media è: %f", media);

	return 0;
}