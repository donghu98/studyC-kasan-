#include <stdio.h>

void print_ary(int*, int);

int main(void) {
	int ary1[5] = { 10, 20, 30, 40, 50 }; // ũ��5 �迭
	int ary2[7] = { 10, 20, 30, 40, 50, 60, 70 };

	//printf("%d", sizeof(ary1)); // 20
	//printf("%d", sizeof(ary1[0])); // int 4
}

void print_ary(int* pa, int size) { //�����͹޾Ƽ�
	for (int i = 0; i < size; i++) {
		printf("%d\t", pa[i]); //�迭���
	}
}
