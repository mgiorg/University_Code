#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "max_gap.h"

int maxGap(int* array, int start, int end) {
	// TODO: Da completare
	int* temp = array;
	int medio = (end+start)/2;
	if(end-start == 0) {
		return 0;
	}
	if(end-start == 1) {
		return abs(array[end]-array[start]);
	}
	int a = maxGap(array, start, medio);
	int b;
	if(end == 9) 
		b = maxGap(array, medio, end-1);
	else 
		b = maxGap(array, medio, end);
	if(a>b) return a;
	else return b;
}
