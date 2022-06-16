#include <stdio.h>

int main(void) {
	// escape character 사용법
	printf("Be Happy!\n");
	printf("123345453234\n");
	printf("My friend\n");
	printf("goot\bd\chance\n");


	// 정수와 실수 화면 출력

	printf("%d\n", 10);
	printf("%lf\n", 3.141592);
	printf("%d\n", 3.141592);  //-5599XX 이상한 값 출력 
	printf("%.1lf\n", 3.141592); // 소수점 첫째자리만 출력 
	printf("%.10f\n", 3.4);

	printf("%d과 %d의 합은 %d입니다.\n", 10, 20, 10 + 20);
	printf("%.1lf - %.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);


	// 진수 표현 
	printf("%d\t", 12);   //10진수
	printf("%d\t", 014);  //8진수
	printf("%d\t", 0xc);  //16진수

    // 지수 표현
	printf("%.1lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);

	//문자와 문자열 표현
	printf("%c\n", 'A');
	printf("%s\n", "A");

	return 0;
}
