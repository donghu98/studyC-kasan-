#include <stdio.h>

int main(void) {
	// escape character ����
	printf("Be Happy!\n");
	printf("123345453234\n");
	printf("My friend\n");
	printf("goot\bd\chance\n");


	// ������ �Ǽ� ȭ�� ���

	printf("%d\n", 10);
	printf("%lf\n", 3.141592);
	printf("%d\n", 3.141592);  //-5599XX �̻��� �� ��� 
	printf("%.1lf\n", 3.141592); // �Ҽ��� ù°�ڸ��� ��� 
	printf("%.10f\n", 3.4);

	printf("%d�� %d�� ���� %d�Դϴ�.\n", 10, 20, 10 + 20);
	printf("%.1lf - %.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);


	// ���� ǥ�� 
	printf("%d\t", 12);   //10����
	printf("%d\t", 014);  //8����
	printf("%d\t", 0xc);  //16����

    // ���� ǥ��
	printf("%.1lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);

	//���ڿ� ���ڿ� ǥ��
	printf("%c\n", 'A');
	printf("%s\n", "A");

	return 0;
}
