// ���ڿ� �н� main.c
#define _CRT_SECURE_NO_WARNINGS  // strupy. scanf �� ����� �� ��ó���� 

#include <stdio.h>
#include <stdint.h>
#include <string.h>

void main(void) {
	const double tax_rate = 0.12; // ���� �ʱ�ȭ ���ȭ
	char fruit[6] = "���";
	int ia = 0;

	printf("%d\n", ia);
	printf("%s\n", fruit);

	strcpy(fruit, "apple");
	printf("%s\n", fruit);

	// tax_rate = 0.15; // error ������� ����Ұ� 

}