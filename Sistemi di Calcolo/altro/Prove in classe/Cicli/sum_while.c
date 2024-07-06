int sumwhile(int x, int y) {
	int res = 0;
	while(x > 0) {
		if (y > 0) {
			res+= x;
			y--;
		}
		x--;
	}
	return res;
}

/* EQUIVALENTE
int sumwhile(int x, int y) {
	int a = 0;
	int c = x; 
	int d = y;

L:
	if(c <= 0) goto E;
	if(d <= 0) goto F;

	a+= c;
	d--;

F:
	c--;
	goto L;

E:
	return a;
}



*/