//���� �б�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	FILE* fp;
	int ch;
	
	fp = fopen("C:\\temp\\a.txt", "r"); //a.txt������ �б��� ���� 
	if (fp == NULL) {
		printf("������ ���� ���߽��ϴ�\n");
		return 1; //exit(1); // return 1;
	}

	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) break; { // End Of File

			putchar(ch); 
		}
	}
	fclose(fp);  // ���� �ݵ�� �ݾ�����Ѵ�!! �ݵ��!!
}