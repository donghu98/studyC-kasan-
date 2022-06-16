// 문자열 학습 main.c
#define _CRT_SECURE_NO_WARNINGS  // strupy. scanf 등 사용할 때 전처리기 

#include <stdio.h>
#include <stdint.h>
#include <string.h>

void main(void) {
	const double tax_rate = 0.12; // 세율 초기화 상수화
	char fruit[6] = "사과";
	int ia = 0;

	printf("%d\n", ia);
	printf("%s\n", fruit);

	strcpy(fruit, "apple");
	printf("%s\n", fruit);

	// tax_rate = 0.15; // error 상수값은 변경불가 

}