#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int* pi;
	double* pd;

	pi = (int*)malloc(sizeof(int));; //4바이트로 메모리를 동적 할당
	if (pi == NULL) {
		printf(" # 메모리가 부족합니다. \n");
		exit(1); //비정상적으로 종료 
	}

	pd = (double*)malloc(sizeof(double));
	if (pd == NULL) {
		printf(" # 메모리가 부족합니다. \n");
		exit(1); // 비정상적으로 종료
	}

	*pi = 10;
	*pd = 3.141592;
	printf("%d\n", *pi);
	printf("%lf\n", *pd);

	free(pi); free(pd); // 메모리 해제! 재부팅될 때까지 문제 
}
