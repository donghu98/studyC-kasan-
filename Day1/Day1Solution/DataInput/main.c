//////// ����� �� �Է�
#define _crt_secure_no_warnings  // strupy. scanf �� ����� �� ��ó���� 
#include <stdio.h>
#include <stdint.h>
//////#include <string.h>
//////
void main(void) {
	//////	int a;
	//////
	//////	printf("������ �Է��ϼ��� >");
	//////	scanf("%d", &a); // �ֿܼ��� Ű���� �Է� ,  a������ �����ּ� 
	//////	printf("�Էµ� �� : %d\n", a);
	//////
	//////	int age;
	//////	double height;
	//////
	//////	printf("���̿� Ű�� �Է��ϼ��� > ");
	//////	scanf("%d%lf", &age, &height);
	//////	printf("���̴� %dt��, Ű�� %.1lf cm�Դϴ�\n", age, height);
	//////
	//////
	//////	return 0;
	//////}


	char grade;
	char name[20];

	printf("�����Է� > ");
	scanf("%c", &grade);
	printf("�̸��Է� > ");
	scanf("%s", &name); //���ڿ�, ������ ��ü�� ������ �����ּ� ��Ÿ��

	printf("%s �л��� ������ %c", name, grade);
}