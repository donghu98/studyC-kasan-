// 배열 동적할당
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* pi;
	int i = 0, sum = 0;

	// 핵심!!! 동적할당
	pi = (int*)malloc(5 * sizeof(int));  //int 4 -> bite,  20바이트 void 포인터 : 어떤 것이던 다 받을 수 있다 
	if (pi == NULL) {
		printf("메모리가 부족합니다.\n");
		exit(1); // 일반적 에러 (뭔지 모르는 거)
	}

	printf("다섯 명의 나이를 입력하세요 > ");
	for (i = 0; i < 5; i++) {
		scanf("%d", &pi[i]); //배열형태로 입력 (pi + i) == [i] 
		sum += pi[i]; // *(pi +i)
	}

	printf("다섯 명의 평균나이 : %.1lf\n", sum / 5.0);
	free(pi); //동적메모리 해제, 필수(!)

	//exit(0);  // 성공적으로 프로그램 종료 일반적으로 생략 
}
	

 