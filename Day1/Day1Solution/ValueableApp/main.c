// 변수학습 main.c
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int a;
	int b, c;
	float fa;
	double da;
	char ch;

	a = 10;
	b = a;
	c = a + 20;
	fa = 3.5f; // float에 실수값 할당
	da = 3.5;
	ch = 'A';

	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", c);
	printf("변수 fa의 값 : %f\n", fa);
	printf("변수 da의 값 : %.1lf\n", da);
	printf("변수 ch의 값 : %c\n", ch);

	char kdh;
	kdh = '김';
	printf("변수 kdh값 : %c\n", kdh);

	short sh = 32767;
	printf("short형 변수 출력 : %d\n", sh)

		return 0 ;
}
