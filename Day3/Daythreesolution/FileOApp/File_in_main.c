//파일 읽기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	FILE* fp;
	int ch;
	
	fp = fopen("C:\\temp\\a.txt", "r"); //a.txt파일을 읽기모드 오픈 
	if (fp == NULL) {
		printf("파일을 열지 못했습니다\n");
		return 1; //exit(1); // return 1;
	}

	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) break; { // End Of File

			putchar(ch); 
		}
	}
	fclose(fp);  // 파일 반드시 닫아줘야한다!! 반드시!!
}