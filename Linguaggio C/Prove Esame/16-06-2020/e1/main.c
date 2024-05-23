#include "funzioni.c"

void naveColpita(Mat* src, int r, int c) {
	if (r < 0 || c < 0 || r >= src->rows || c >= src->cols || src-> row_ptrs[r][c] == 0) return;
	if(src-> row_ptrs[r][c] == 1) src-> row_ptrs[r][c] = 0;
	naveColpita(src, r+1, c);
	naveColpita(src, r-1, c);
	naveColpita(src, r, c+1);
	naveColpita(src, r, c-1);
}
void bombardamentoNavale(Mat *src, int r, int c)
{
	naveColpita(src, r, c);
	return;
}

int main() {


	return 0;
}