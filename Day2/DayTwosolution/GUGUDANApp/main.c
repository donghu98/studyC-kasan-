#include <stdio.h>

int main(void) {
	
	for (int i = 2; i < 10; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d * %d = %2d\n", i, j, i * j);
		}
		printf("\n");
	}

}