#include <stdio.h>

//�Լ�����
int sum(int, int); // �Լ����� �̶�� ��

//�����Լ�
int main(void) {
	printf("�ջ��ϱ�\n");

	int total = sum(100, 34);
	printf("�հ�, %d\n", total);
}
 // �Լ�����
int sum(int x, int y) {  // �������� �� sum(���� �ִ�)�� ���������༭ �׷��� 
	int res;             // ������ �� ���� sum���� ���� �־���ϴµ� �׷��� �Ǹ� ����� ������ ���� ������
	                     // �Լ������̶�� ���� �߰��ؼ� ������Ѵ�.
	res = x + y;
	return res;
}