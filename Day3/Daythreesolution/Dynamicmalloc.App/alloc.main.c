// �迭 �����Ҵ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* pi;
	int i = 0, sum = 0;

	// �ٽ�!!! �����Ҵ�
	pi = (int*)malloc(5 * sizeof(int));  //int 4 -> bite,  20����Ʈ void ������ : � ���̴� �� ���� �� �ִ� 
	if (pi == NULL) {
		printf("�޸𸮰� �����մϴ�.\n");
		exit(1); // �Ϲ��� ���� (���� �𸣴� ��)
	}

	printf("�ټ� ���� ���̸� �Է��ϼ��� > ");
	for (i = 0; i < 5; i++) {
		scanf("%d", &pi[i]); //�迭���·� �Է� (pi + i) == [i] 
		sum += pi[i]; // *(pi +i)
	}

	printf("�ټ� ���� ��ճ��� : %.1lf\n", sum / 5.0);
	free(pi); //�����޸� ����, �ʼ�(!)

	//exit(0);  // ���������� ���α׷� ���� �Ϲ������� ���� 
}
	

 