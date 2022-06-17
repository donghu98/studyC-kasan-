#include <stdio.h>

int main(void) {
	char ch;
	int in;
	double db;

	char* pc = &ch;
	int* pi = &in;
	double* pd = &db;

	printf("일반변수의 크기 --- \n");
	printf("sizeof  char %d\n", sizeof(&ch));
	printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
	printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));


}