//////// 입출력 중 입력
#define _crt_secure_no_warnings  // strupy. scanf 등 사용할 때 전처리기 
#include <stdio.h>
#include <stdint.h>
//////#include <string.h>
//////
void main(void) {
	//////	int a;
	//////
	//////	printf("정수를 입력하세요 >");
	//////	scanf("%d", &a); // 콘솔에서 키보드 입력 ,  a변수의 시작주소 
	//////	printf("입력된 값 : %d\n", a);
	//////
	//////	int age;
	//////	double height;
	//////
	//////	printf("나이와 키를 입력하세요 > ");
	//////	scanf("%d%lf", &age, &height);
	//////	printf("나이는 %dt살, 키는 %.1lf cm입니다\n", age, height);
	//////
	//////
	//////	return 0;
	//////}


	char grade;
	char name[20];

	printf("학점입력 > ");
	scanf("%c", &grade);
	printf("이름입력 > ");
	scanf("%s", &name); //문자열, 변수명 자체가 변수의 시작주소 나타냄

	printf("%s 학생의 학점은 %c", name, grade);
}