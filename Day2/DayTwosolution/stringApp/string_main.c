#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char* str[80];
	
	//str = "apple";
	strcpy(str, "apple");
	printf("%s\n", str);

	//str = "안녕하세요~";
	strcpy(str, "안녕하세요~");
	printf("%s\n", str);

	//printf("이름을 입력하세요 > ");
	//gets(str);
	//printf("이름은 %s\n", str);

	char str2[20] = "mango tree";
	strncpy(str2, "apple-pie", 5);
	printf("%s\n", str2);

	char str3[80] = "straw"; // 빨대 
	strcat(str3, "berry");
	printf("%s\n", str3);
}