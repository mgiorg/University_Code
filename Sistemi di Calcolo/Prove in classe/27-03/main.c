/**
 * main.c
 * Lezione del 27 Marzo, Massimo Giordano
 * 
 * 
*/
/*
#include <stdio.h>

int f(int x) {
	int y = 1;
	int z = 2;
	int a = g(x+1);
	a = a+y+2;
	return a;
}


! Codice ASSEMBLY
.globl f
f:

	pushl %ebp
	movl %esp, %ebp
	pushl %edi
	pushl %esi

	movl $1, %edi
	movl $2, %esi
	movl 8(%ebp), %eax
	incl %eax

	- Rivedi chiamata a funzione
	pushl %eax
	call g
	addl $4, %esp

	addl %edi, %eax
	addl %esi, %eax

	//* Epilogo
	popl %esi
	popl %edi
	movl %ebp, %esp
	popl %ebp
	ret
*/
#include <stdio.h>

int is_negative(int x) {
	if (x < 0)	return 1;
	else	return 0;
}
int ordinati(int x, int y) {
	if (y > x)	return 1;
	else	return 0;
}

unsigned f(int* v, unsigned n);
unsigned g(int *v, unsigned n);

int main() {
	int v[] = {1, 2, 4, 5, 7};
	int res = g(v, sizeof(v)/sizeof(v[0]));
	printf("Risultato: %d\n", res);
	return 0;
}