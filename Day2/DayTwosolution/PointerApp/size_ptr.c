#include <stdio.h>

int main(void) {
	char ch;
	int in;
	double db;

	char* pc = &ch;
	int* pi = &in;
	double* pd = &db;

	printf("�Ϲݺ����� ũ�� --- \n");
	printf("sizeof  char %d\n", sizeof(&ch));
	printf("char�� ������ �ּ� ũ�� : %d\n", sizeof(&ch));
	printf("char�� ������ �ּ� ũ�� : %d\n", sizeof(&ch));


}