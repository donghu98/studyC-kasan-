#pragma comment (lib, "libmysql.lib") // MySQL �󸮺귯�� ���

#include <stdio.h>
#include <stdlib.h> // �⺻

#include <Winsock2.h> // DB�� ��Ʈ��ũ ���
#include <my_global.h> 
#include <mysql.h>

int main(void) {
	printf("MYSQL info = %s\n", mysql_get_client_info());

	system("pause");
	return EXIT_SUCCESS;
}
