/**
 * main.c
 */

//int contaChar:
//	Array in un ciclo for conta su p quante volte C sta nella stringa

#include <stdio.h>
#include <string.h>

char array[23] = "Ciao Mamma, come stai?\0";
int contaChar(char s[23], char c);

int main()
{
	char c;
	scanf("%c", &c);

	int a = contaChar(array, c);
	printf("%d", a);
}

int contaChar(char s[23], char c)
{
	int p = 0;
	for(int i = 0; i < 23; ++i)
	{
		if(s[i] == c) ++p;
	}
	return p;
}