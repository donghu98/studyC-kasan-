#include <stdio.h>
/*
* for main.c
* 작성일 : 2022.06.17
*/
/// <summary> /// 3번하면 왼쪽과 같은 식이 쫘르륵 나온다 
/// 메인 엔트리 함수 
/// </summary>
/// <param name=""></param>
/// <returns></returns>
int main(void) {
	int a = 1;

	for (int i = 0; i < 3; i++) { // (초기값;반복조건;증감연산;)
		a = a * 2;
	}
	printf("a=%d\n", a);
}