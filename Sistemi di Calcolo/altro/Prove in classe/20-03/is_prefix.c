#include <string.h>

int is_prefix(const char*s, const char* t) {
	while(*s && *t && *s == *t) {
		s++;
		t++;
	}
	return *s == 0 ? 1:0;
}

int is_prefix_eq(const char *s, const char *t)
{
	const char* c = s;
	const char* d = t;
L:
	char al = *c;
	if(al == 0) goto E;
	if(*d == 0) goto E;
	if(al != *d) goto E;
	c++;
	d++;
	goto L;
E:
	int ret = 0 ;
	if(al != 0) goto E2;
	ret = 1;
E2:
	return ret;
}