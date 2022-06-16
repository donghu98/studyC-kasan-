#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void main(void) {
	char grade;

	switch (grade)
	{
	case'A':
		printf("대단하네요ㅎ");
		break;
	case'B':
		printf("잘했어요");
		break;
	case'C':
		printf("낫 뱃");
		break;
	case'D':
		printf("정신 못차렸군요");
		break;
	case'F':
		printf("학고 맞을래요?");
		break;
	default: //다섯 가지 케이스가 아닌경우
		printf("제대로 입력하세요");
		break;


	}

	printf("학점을 입력하세요 > ");
	scanf("%c", &grade);

	if (grade == 'a') {
		printf("대단하네요ㅎ");
	}
	else if (grade == 'b') {
		printf("잘했어요");

	}
	else if (grade == 'c') {
		printf("낫 뱃");
	}
	else if (grade == 'd') {
		printf("정신 못차렸군요");
	}
	else if (grade == 'f') {
		printf("학고 맞을래요?");
	}

}
