#pragma comment (lib, "libmysql.lib")

#include <winsock.h>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

// mysql 접속 설정(변경 필요)
#define mysqlip "127.0.0.1"
#define port 3306
#define loginusername "BMS"
#define loginpassword "1234"
#define mysqlname "bms"

int main(void) {
	MYSQL* conn;

	conn = mysql_init(NULL);
	mysql_real_connect(conn, mysqlip, loginusername, loginpassword, mysqlname, port, NULL, 0);
	if (conn == NULL) {
		fprintf(stderr, "연결오류 : %s\n", mysql_error(conn));
		return 1;
	}
	else {
		printf("연결성공 \n");
		printf("서버버젼 %s\n", conn->server_version);
	}

	mysql_close(conn);
	return 0;
}
