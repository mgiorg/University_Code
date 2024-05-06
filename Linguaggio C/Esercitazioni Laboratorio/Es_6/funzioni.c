#include <stdio.h>
#include <stdbool.h>

float product(float vec[], int n) {
	if(n <= 0) return 1;
	else {
		n--;
		return vec[n] * product(vec, n);
	}
}

void vec_integral(float* v, int n) {
	if(n <= 0) v[0] = v[0];
	else {
		n--;
		float somma = 0;
		for(int i = 0; i <= n-1; ++i) {
			somma += v[i];
		}
		v[n] = somma;
		vec_integral(v, n);
	}
}

int lenght(const char* s) {
	if(*s == '\0') return 0;
	else {
		return 1 + lenght(s+1);
	}
}

// 97-122
bool is_any_lowercase(char* s) {

	if(*s == '\0') return false;
	if(((int)*s >= 97 || (int)*s <= 122)) {
		return true;
	}
	return is_any_lowercase(s+1);
	
}