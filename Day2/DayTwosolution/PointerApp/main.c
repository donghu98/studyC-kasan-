#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a;
	double b;
	char c;

	printf("int�� ���� �ּ� > %p\n", &a);
	printf("double�� ���� �ּ� > %p\n", &b);
	printf("char�� ���� �ּ� > %p\n", &c);

	int a;
	int* pa;

	pa = &a; // ����a�� �ּҸ� �����ͺ����� �Ҵ�
	*pa = 10;

	printf("�����ͷ� a�� ��� > %d\n", *pa);
	printf("���������� a�� ��� > % d\n", a);


}