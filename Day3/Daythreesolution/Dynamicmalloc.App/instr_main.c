// 문자열 입력처리 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char temp[80];
	char* str[3];
	int i;

	for (i = 0; i < 3; i++); {
		printf("문자열을 입력하세요 > ");
		gets(temp);
		str[i] = malloc(strlen(temp) + 1); // \0 때문에 1 증가 
		strcpy(str[i], temp);
	}

	for (i = 0; i < 3; i++) {
		printf("%s\n", str[i]);
	}

	for (i = 0; i < 3; i++) {
		free(str[i]);
	}
}
