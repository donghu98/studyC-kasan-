// calloc, realloc ����غ��� 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* pi; //������ ������
	int size = 5;
	int count = 0;
	int num;
	int i;

	//calloc
	pi = calloc(size, sizeof(int)); // 5�� int�� �迭 0���� �ʱ�ȭ ,20����Ʈ
	while (1)
	{
		printf("����� �Է��ϼ��� -> ");
		scanf("%d", &num);
		if (num <= 0) break;

		//5���� �Է��� ������ �þ�� ����� �÷��ִ� 
		//realloc
		if (count == size) {
			size += 5;
			pi = (int*)realloc(pi, sizeof(int) * size);
		}

		pi[count] = num;
		count++;
	}
	

		for (i = 0; i < size; i++) {
			printf("%5d", pi[i]);
		}
		free(pi);
	}