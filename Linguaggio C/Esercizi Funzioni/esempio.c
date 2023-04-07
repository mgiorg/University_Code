#include <stdio.h>

//Scrivere una funzione check(x, y, n) che verifichi se x e y sono compresi nell’intervallo [0, n) e
//restituisca il numero di valori (tra x e y) che rispettano la condizione

int check(int a, int b, int n);

const int N = 15;

int main()
{
	int x, y;
	printf("Inserire due numeri interi:\n\n");
	scanf("%d", &x);
	scanf("%d", &y);
	printf("\nControllo se sono compresi nell'intervallo [0, N).\n\n");

	int result = check(x, y, N);

	switch(result)
	{
		case 0:
			printf("Intervallo Vuoto");
			break;

		default: printf("I numeri compresi nell'intervallo sono: %d", result);
	}
	
	return 0;
}

int check(int x, int y, int n)
{
	if(x >= 0 && y >= 0) //i numeri sono positivi
	{
		if(x < n) 
		{
			if(y < n)
			{
				//sono entrambi compresi nell'intervallo
				if(x > y) return x-y;

				else return y-x;
			}
			else
			{
				int a = 0;
				for(int i = x; i < n; ++i)
				{
					++a;
				}
				return a;
			}
		}
		else
		{
			if(y < n)
			{
				int a = 0;
				for(int i = y; i < n; ++i)
				{
					++a;
				}
				return a;
			}
			else return 0;
		}
	}
	else return 0;
}

