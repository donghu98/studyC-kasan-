#pragma comment (lib, "libmysql.lib") // MySQL �󸮺귯�� ���

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <locale.h> // C�⺻
#include <windows.h>

#include <winsock.h>
#include <mysql.h> //mysql ��

#define mysqlip "127.0.0.1"  // 192.168.0.16
#define port 3306
#define userid "root"
#define password ""
#define mysqlname "ems" // mysql schema��

int main(void) {
	//����
	MYSQL* conn; // MySQL ������ ���� MySQL ����ü ������ 
	MYSQL_RES* result;
	MYSQL_ROW row;

	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;

	int i = 0 ;

	setlocale(LC_ALL, "Korean"); // �ѱ��� ����������

		//MySQL ���ӽ���
	conn = mysql_init(NULL); // MySQL �ʱ�ȭ
	mysql_real_connect(conn, mysqlip, userid, password, mysqlname, port, NULL, 0);
	if (conn == NULL) {
		fprintf(stderr, "������� : %s\n", mysql_error(conn));
		return EXIT_FAILURE;
	}

	printf("���Ἲ��!\n");

	//����� ���� ó�� 
	printf("�������� %s\n", conn->server_version);

	//Ŀ���� ���� 
	query_stat = mysql_query(conn, "SELECT * FROM books_info");
	if (query_stat != 0) {
		fprintf(stderr, "�������� : %s\n", mysql_error(conn));
		mysql_close(conn);
		return EXIT_FAILURE;
	}

	result = mysql_store_result(conn); // ��� ������ü ����
	num_fields = mysql_num_fields(result); // �÷��Լ�
	while (row = mysql_fetch_row(result)) {
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++) {
			printf("[%s]", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	//����Ǯ(Connection Pool)
	mysql_close(conn);
	printf("��������\n");
	system("pause");
	return EXIT_SUCCESS;
}
