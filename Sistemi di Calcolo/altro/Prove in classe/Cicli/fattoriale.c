unsigned fact(unsigned n) {
	unsigned a = 1, c;
	for(c = 2; c < n; ++c) {
		a*= c;
	}
	return a;
}

/* TRADUZIONE FOR-> WHILE
unsigned fact(unsigned n) {
	unsigned a = 1;
	unsigned c;

	c = 2;
	while(c <= n) {
		a*= c;
		++c;
	}
	return a;
}
*/

/* EQUIVALENTE
unsigned fact(unsigned n) {
	unsigned a = 1;
	unsigned c;

	c = 2;
L:
	if(c > n) goto E;
	a*= c;
	++c;
	goto L;
E:
	return a;
}
*/