#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[5] = { 0, }; // 배열 초기화

	arr[0] = 90;
	arr[1] = 95;
	arr[2] = 80;
	printf("네번째 학생 점수 입력 > ");
	scanf("%d", &arr[3]);

	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	printf("%d\n", arr[2]);
	printf("%d\n", arr[3]);
	printf("%d\n", arr[4]);

	int sum = 0;
	float average;

	for (int i = 0; i <= 4; i++) {
		sum += arr[i];
	}
	average = sum / 5;

	printf("모든 학생의 점수 총합 :  %d\n", sum);
	printf("모든 학생의 평균점수 :  %.1lf\n", average);
}