// �����н� main.c
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int a;
	int b, c;
	float fa;
	double da;
	char ch;

	a = 10;
	b = a;
	c = a + 20;
	fa = 3.5f; // float�� �Ǽ��� �Ҵ�
	da = 3.5;
	ch = 'A';

	printf("���� a�� �� : %d\n", a);
	printf("���� b�� �� : %d\n", b);
	printf("���� c�� �� : %d\n", c);
	printf("���� fa�� �� : %f\n", fa);
	printf("���� da�� �� : %.1lf\n", da);
	printf("���� ch�� �� : %c\n", ch);

	char kdh;
	kdh = '��';
	printf("���� kdh�� : %c\n", kdh);

	short sh = 32767;
	printf("short�� ���� ��� : %d\n", sh)

		return 0 ;
}
