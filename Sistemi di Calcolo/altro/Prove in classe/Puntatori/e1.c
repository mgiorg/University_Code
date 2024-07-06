void times2(short* p) {
	*p = *p *2;
}

void times2_int(short* p) {
	short* a = p;
	short cx = *a;

	cx = cx * 2;
	*a = cx;
}