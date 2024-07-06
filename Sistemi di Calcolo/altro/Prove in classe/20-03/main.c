#include <stdio.h>
/**
 * tipo* puntatore;
 * -> spazio occupato dal puntatore = {char = 1byte, short = 2byte, int = 4byte}
 * 
 * p -> v (p punta v) (in C: aritmetica puntatori implicita, in ASM: aritmetica dei puntatori ESPLICITA)
 * se "p++" : (TRADOTTO IN ASSEMBLY)
 * 			-> caso char: addl 	$1, %eax
 * 			-> caso short: addl $2, %eax
 * 			-> caso int: addl 	$4, %eax
 * 
*/

unsigned my_strlen(const char* s);
unsigned my_strlen_eq(const char* s);

char *my_strcat(char *dest, const char *src);
char *my_strcat_eq(char *dest, const char *src);

int is_prefix(const char *s, const char *t);
int is_prefix_eq(const char* s, const char* t);

int main()
{
	
	printf("%d\n", is_prefix("Mamma", "Mammamia"));
	return 0;
}