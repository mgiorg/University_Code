int sum(int n) {
	int c = n;
	int a = 0;

L: 
	if(c-0 <= 0) goto E;

	a+= c;
	c--;
	goto L;

E:
	return a;
}