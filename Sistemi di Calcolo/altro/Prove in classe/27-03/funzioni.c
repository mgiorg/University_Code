
unsigned f(int *v, unsigned n)
{
	unsigned i, cnt = 0;
	for (i = 0; i < n; ++i)
	{
		cnt += is_negative(v[i]);
	}
	return cnt;
}

unsigned f_eq(int *v, unsigned n)

{
	int *di = v;	 // edi = v
	unsigned si = n; // esi = n
	unsigned b = 0;	 // ebx <-> i
	unsigned bp = 0;
L:
	if (b >= si)
		goto E;
	int c = di[b];
	unsigned a = is_negative(c); // cnt += is_negative(v[i]);
	bp = bp + a;
E:
	a = bp;
	return a;
}

unsigned g(int* v, unsigned n) {
	unsigned i;
	for(i = 1; i < n; ++i)
		if(!ordinati(v[i-1], v[i])) return 0;
	return 1;
}
unsigned g_eq(int* v, unsigned n) {
	unsigned b;
	int* di = v;
	unsigned si = n;
	b = 1;
L:	
	if(b >= si) goto E2;
	int c = di[b-1];
	int d = di[b];
	int a = ordinati(c, d);
	if(a == 0) goto E1;
	b++;
	goto L;

E1:
	a = 0;
	goto E;
E2:
	a = 1;
E:
	return a;
}

