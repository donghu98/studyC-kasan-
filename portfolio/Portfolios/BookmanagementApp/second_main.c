#pragma comment (lib, "libmysql.lib") // MySQL 라리브러리 사용

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <locale.h> // C기본
#include <windows.h>

#include <winsock.h>
#include <mysql.h> //mysql 용

#define mysqlip "127.0.0.1"  // 192.168.0.16
#define port 3306
#define userid "root"
#define password ""
#define mysqlname "ems" // mysql schema명

int main(void) {
	//시작
	MYSQL* conn; // MySQL 접속을 위한 MySQL 구조체 포인터 
	MYSQL_RES* result;
	MYSQL_ROW row;

	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;

	int i = 0 ;

	setlocale(LC_ALL, "Korean"); // 한국어 깨짐방지용

		//MySQL 접속시작
	conn = mysql_init(NULL); // MySQL 초기화
	mysql_real_connect(conn, mysqlip, userid, password, mysqlname, port, NULL, 0);
	if (conn == NULL) {
		fprintf(stderr, "연결오류 : %s\n", mysql_error(conn));
		return EXIT_FAILURE;
	}

	printf("연결성공!\n");

	//연결된 이후 처리 
	printf("서버버전 %s\n", conn->server_version);

	//커리를 실행 
	query_stat = mysql_query(conn, "SELECT * FROM books_info");
	if (query_stat != 0) {
		fprintf(stderr, "쿼리오류 : %s\n", mysql_error(conn));
		mysql_close(conn);
		return EXIT_FAILURE;
	}

	result = mysql_store_result(conn); // 결과 정보객체 리턴
	num_fields = mysql_num_fields(result); // 컬럼함수
	while (row = mysql_fetch_row(result)) {
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++) {
			printf("[%s]", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	//연결풀(Connection Pool)
	mysql_close(conn);
	printf("연결종료\n");
	system("pause");
	return EXIT_SUCCESS;
}
