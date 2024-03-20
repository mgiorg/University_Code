char* my_strcat(char* dest, const char* src) {
	char* s = dest;
	while(*dest) dest++;

	while(*dest = *src) {
		dest++;
		src++;
	}
	return s;
}

char *my_strcat_eq(char *dest, const char *src)
{
	char* d = dest;
	const char* c = src;
L1:
	if(*d == 0) goto E1;
	d++;
	goto L1;
E1:
L2:
	char al = *c;
	*d = al;
	if(al == 0) goto E2;
	d++;
	c++;
	goto L2;
E2:
	char* a = dest;
	return a;
}