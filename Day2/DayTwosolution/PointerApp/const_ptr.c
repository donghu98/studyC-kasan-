#include <stdio.h>

int main(void) {

	int a = 10, b = 20;
	const int* pa;

	pa = &a;
	printf("a의 값 %d\n", *pa);

	pa = &b;
	printf("b의 값 %d\n", *pa);

	b = 30;
	printf("b의 값 %d\n", *pa);

	// *pa = 40;  //error const 포인터는 변경불가 
}
