#pragma comment (lib, "libmysql.lib") // MySQL 라리브러리 사용

#include <stdio.h>
#include <stdlib.h> // 기본

#include <Winsock2.h> // DB용 네트워크 사용
#include <my_global.h> 
#include <mysql.h>

int main(void) {
	printf("MYSQL info = %s\n", mysql_get_client_info());

	system("pause");
	return EXIT_SUCCESS;
}
