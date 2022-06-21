#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <wtypes.h>
#include <sql.h>
#include <sqlext.h>

SQLHENV henv = NULL; //DBȯ�� ����ü 
SQLHENV hdbc = NULL; //DB ���� ����ü

int ODBCConnect(SQLCHAR* dsn, SQLCHAR* userid, SQLCHAR* pwd) {
	SQLRETURN res;
	henv = NULL;
	hdbc = NULL; // �ʱ�ȭ

	//  SQL ȯ�� henv ���� �Ҵ�
	res = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
		// ODBC ������ ���� ȯ�� �Ӽ� ����
		res = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
		if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
			//Ŀ�ؼ� �ڵ� ����
			res = SQLAllocHandle(SQL_HANDLE_DBC,henv, &hdbc);
			if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
				//�����ϱ� ���� ���� ���� 
				SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)10, 0);
				//���� ���� ( �� �� - ! )
				res = SQLConnect(hdbc, dsn, SQL_NTS, userid, SQL_NTS, pwd, SQL_NTS);
				if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
					return 1; //���Ӽ��� true

				}
				
				SQLDisconnect(hdbc);

			}
			SQLFreeHandle(SQL_HANDLE_DBC, hdbc);

			hdbc = henv = NULL;

			return 0; // ���ӽ��� falsee
		}
	}

}

int ODBCDisconnect() {
	if (hdbc) {
		SQLDisconnect(hdbc); // ���� ����
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	}
	if (henv) SQLFreeHandle(SQL_HANDLE_ENV, henv);
	hdbc = henv = NULL;
	return 1;
}

//������ �������� 
int db_fetch() {
	SQLRETURN rt;
	SQLRETURN hstmt;
	SQLCHAR sql[256]; // ����
	SQLLEN n; // ������ ���� ����

	SQLINTEGER id;
	SQLCHAR title[100];
	SQLCHAR writer[100];
	SQLCHAR genre[45];
	SQLDATE release_date;
	SQLSMALLINT pages;
	SQLCHAR company[50];
	SQLDECIMAL price; // ������ ������� ����

	if (hdbc == NULL || henv == NULL) return 0;

	rt = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (!(rt == SQL_SUCCESS || rt == SQL_SUCCESS_WITH_INFO)) return 0;

	strcpy(sql, "SELECT id, title, writer, genre, release_date, pages, company, price, FROM books_info");
	rt = SQLExecDirect(hstmt, sql, SQL_NTS);
	if (rt != SQL_SUCCESS) {
		printf("cannot access query\n");
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return 0;
	
	}

	while (1) {
		rt = SQLFetch(hstmt);
		if (rt == SQL_SUCCESS || SQL_SUCCESS_WITH_INFO) {
			rt == SQLGetData(hstmt, 1, SQL_C_ULONG, &id, 0, &n);
			rt == SQLGetData(hstmt, 2, SQL_C_WCHAR, title, 100, &n);

			printf("%d, %s\n, id, title");
		}
		else if (rt == SQL_NO_DATA) {
			printf("No Data\n");
			break;
		}
		else {
			printf("Fail to fetch data~");
			break;
		}
	}
	
}

int main(void) {
	int ret = 0;
	printf("MSSQL ���ӽ���");
	ODBCConnect("BEMS", "sa", "1234");
	if (ret == 1)
		printf("���Ӽ���\n");

	ret = ODBCDisconnect();
	if (ret == 1)
		printf("��������\n");

	ODBCDisconnect();
	printf("MSSQL ��������");
	return 0;

}