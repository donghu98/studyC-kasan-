#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char* str[80];
	
	//str = "apple";
	strcpy(str, "apple");
	printf("%s\n", str);

	//str = "�ȳ��ϼ���~";
	strcpy(str, "�ȳ��ϼ���~");
	printf("%s\n", str);

	//printf("�̸��� �Է��ϼ��� > ");
	//gets(str);
	//printf("�̸��� %s\n", str);

	char str2[20] = "mango tree";
	strncpy(str2, "apple-pie", 5);
	printf("%s\n", str2);

	char str3[80] = "straw"; // ���� 
	strcat(str3, "berry");
	printf("%s\n", str3);
}