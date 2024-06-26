#include <stdio.h>

	int f(int i){
		if (i > 0){
			return f(i-1);
		}
		return i;
	}

	int main() {
		for (int k = 1; k <= 5; k++){
			printf("%d ",f(k));
		}
		printf("\n");
		return 0;
	}