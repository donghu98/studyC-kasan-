// int main(void) {} 가 진짜가 아니다 
#include <stdio.h>

// 콘솔에서 C프로그램할때 실제적쓰는 메인 엔트리포인트 함수원형
int main(int argc, char** argv) {
	int i;

	for (i = 0; i < argc; i++) {
		//printf("%d번째 인수 %s\n", i, argv[i]);
		if (i == 1) {
			if (strcmp(argv[i], "--version") == 0) {
				printf("DynamicmallocApp version 3.4\n");
			}
			else if (strcmp(argv[i], "--help") == 0) {
				printf("도움말입니다!!...\n");
			}
		}
	}

	system("pause");
}