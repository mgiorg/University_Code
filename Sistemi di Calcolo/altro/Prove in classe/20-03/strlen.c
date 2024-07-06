/**
 * Funzioni equivalenti my_strlen
*/
unsigned my_strlen(const char *s)
{
	unsigned cnt = 0;
	while (*s++)
	{
		cnt++;
	}
	return cnt;
}

unsigned my_strlen_eq(const char *s)
{
	const char* c = s;
	unsigned a = 0;
L:
	char d = *c;
	c++;
	if(d == 0) goto E;
	a++;
	goto L;
E:
	return a;
}