#include <stdio.h>
/*
* for main.c
* �ۼ��� : 2022.06.17
*/
/// <summary> /// 3���ϸ� ���ʰ� ���� ���� �Ҹ��� ���´� 
/// ���� ��Ʈ�� �Լ� 
/// </summary>
/// <param name=""></param>
/// <returns></returns>
int main(void) {
	int a = 1;

	for (int i = 0; i < 3; i++) { // (�ʱⰪ;�ݺ�����;��������;)
		a = a * 2;
	}
	printf("a=%d\n", a);
}