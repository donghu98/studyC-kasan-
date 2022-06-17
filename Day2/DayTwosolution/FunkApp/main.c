#include <stdio.h>

//함수선언
int sum(int, int); // 함수원형 이라고 함

//메인함수
int main(void) {
	printf("합산하기\n");

	int total = sum(100, 34);
	printf("합계, %d\n", total);
}
 // 함수구현
int sum(int x, int y) {  // 에러나는 게 sum(위에 있는)을 지정안해줘서 그래서 
	int res;             // 원래는 이 줄이 sum보다 위에 있어야하는데 그렇게 되면 상당히 복잡해 지기 때문에
	                     // 함수원형이라는 것을 추가해서 디버깅한다.
	res = x + y;
	return res;
}