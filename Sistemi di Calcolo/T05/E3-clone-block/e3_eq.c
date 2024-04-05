#include <stdlib.h>
#include <string.h>

void *clone(const void *src, int n)
{
	const void *si = src;
	int b = n;
	void *a = malloc(n);
	void *di = a;
	if (di == 0)
		goto N;
	memcpy(di, si, b);
	a = di;
	return a;
N:
	a = 0;
	return a;
}