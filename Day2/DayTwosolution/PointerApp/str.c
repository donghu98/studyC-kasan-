#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int a;
	int* pa; // a를 가리킬 포인터변수 pa 

	pa = &a; // 중요!!!!!!!!!!!!!!!!

	printf("정수를 입력하세요 > ");
	scanf("%d", pa);  //scanf("%d" , &a) 비교해보기

	printf("입력된 정수는 %d 입니다.\n", a);

	//여러가지 포인터 사용
	int a = 10, b = 15, total;
	double avg;
	int* pa, * pb;
	//int* pt =&total;
	int* pt;
	pt = &total;

	double* pg;
	pg = &avg;

	pa = &a; pb = &b;

	*pt = *pa + *pb;
	*pg = *pt / 2.0;

	printf("두 정수의 값 : %d, %d\n", *pa, *pb);
	printf("두 정수의 합 : %d\n", *pt);
	printf("두 정수의 평균 : %.2lf\n", *pg);

}
