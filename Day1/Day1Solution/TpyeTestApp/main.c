#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void main(void) {
	char grade;

	switch (grade)
	{
	case'A':
		printf("����ϳ׿䤾");
		break;
	case'B':
		printf("���߾��");
		break;
	case'C':
		printf("�� ��");
		break;
	case'D':
		printf("���� �����ȱ���");
		break;
	case'F':
		printf("�а� ��������?");
		break;
	default: //�ټ� ���� ���̽��� �ƴѰ��
		printf("����� �Է��ϼ���");
		break;


	}

	printf("������ �Է��ϼ��� > ");
	scanf("%c", &grade);

	if (grade == 'a') {
		printf("����ϳ׿䤾");
	}
	else if (grade == 'b') {
		printf("���߾��");

	}
	else if (grade == 'c') {
		printf("�� ��");
	}
	else if (grade == 'd') {
		printf("���� �����ȱ���");
	}
	else if (grade == 'f') {
		printf("�а� ��������?");
	}

}
